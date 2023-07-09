// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/chainparams.h>

#include <chainparamsseeds.h>
#include <consensus/amount.h>
#include <consensus/merkle.h>
#include <consensus/params.h>
#include <hash.h>
#include <chainparamsbase.h>
#include <logging.h>
#include <primitives/block.h>
#include <primitives/transaction.h>
#include <script/interpreter.h>
#include <script/script.h>
#include <uint256.h>
#include <util/strencodings.h>

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <type_traits>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Brics nations to create $100bn development bank";
    const CScript genesisOutputScript = CScript() << ParseHex("0465b6cdba122a93c06742cd8ba9ad6bda35e715badcc3cd87f8d7a1fd2c3eeb74bb9d8100d7c0ea33892c5c953a6c2d9d6ec1a6789d141ce63e3bf8fdb92cb313") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network on which people trade goods and services.
 */
class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = CBaseChainParams::MAIN;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 240000;
        consensus.script_flag_exceptions.emplace( // BIP16 exception
            uint256S("0x00000000000002dc756eebf4f49723ed8d30cc28a5f108eb94b1ba88ac4f9c22"), SCRIPT_VERIFY_NONE);
        consensus.script_flag_exceptions.emplace( // Taproot exception
            uint256S("0x0000000000000000000f14c35b2d841e986ab5441de8c585d5ffe55ea1e395ad"), SCRIPT_VERIFY_P2SH | SCRIPT_VERIFY_WITNESS);
        consensus.BIP34Height = 10000000;
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 240000; // 
        consensus.BIP66Height = 240000; // 
        consensus.CSVHeight = 419328; // 
        consensus.SegwitHeight = 239904; // 
        consensus.MinBIP9WarningHeight = 241920; // segwit activation height + miner confirmation window
        consensus.powLimit = uint256S("003fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1815; // 90% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = 1685940285; // April 24th, 2021
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = 1688532285; // August 11th, 2021
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 437400; // Approximately November 12th, 2021

        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000000000000003ccc732166a0f");
        consensus.defaultAssumeValid = uint256S("0x09f29bd786ed6777bd3b8526d1e43e4aa64dd94ff26eb0f183f72d34967d95c6"); // 231713

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xa2;
        pchMessageStart[1] = 0xb2;
        pchMessageStart[2] = 0xe2;
        pchMessageStart[3] = 0xf2;
        nDefaultPort = 8226;
        nPruneAfterHeight = 100000;
        m_assumed_blockchain_size = 2;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock(1410213600, 237174, 0x1e0ffff0, 1, 367 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x2e28050194ad73f2405394d2f081361a23c2df8904ec7f026a018bbe148d5adf"));
        assert(genesis.hashMerkleRoot == uint256S("0xacd715d33d3288f616bfe281819a4d84bdea206b8c06088eec584095f5de891c"));

        // Note that of those which support the service bits prefix, most only support a subset of
        // possible options.
        // This is fine at runtime as we'll fall back to using them as an addrfetch if they don't support the
        // service bits we want, but we should get them updated to support all service bits wanted by any
        // release ASAP to avoid it where possible.
        vSeeds.emplace_back("seeder.globalboost.info."); // 
        vSeeds.emplace_back("seeder2.globalboost.info."); // 
        vSeeds.emplace_back("seeder3.globalboost.info."); // 


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,77);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,139);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,128);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "gb";

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_main), std::end(chainparams_seed_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        m_is_test_chain = false;
        m_is_mockable_chain = false;

        checkpointData = {
            {
                {     0, uint256S("0x2e28050194ad73f2405394d2f081361a23c2df8904ec7f026a018bbe148d5adf")},
                {  2672, uint256S("0xe31f98339ec0c628bcc5bd20aef177bdef83deb7a606528c8977ad3a1f511906")},
                { 29000, uint256S("0x63a67152f31a4596fc6ca5073ffe4cf68264922e740285f0ae7b3bb8cbc66b39")},
                { 60000, uint256S("0x8ac508122d4f7b290c19cb45be6e071e7aace53cd043a892e79041672c1ba99d")},
		        {206494, uint256S("0xe852dcc3019c11a7f0589d418bc63f4a197c743e811db920221f930aa9abf589")},
            }
        };

        m_assumeutxo_data = MapAssumeutxo{
         // TODO to be specified in a future patch.
        };

        chainTxData = ChainTxData{
            // Data from RPC: getchaintxstats 440356 45beafcb12bf8c67fa2919a6f2d7c2e0aa252165f8cf3d24239c52456d356f99
            .nTime    = 1688663765,
            .nTxCount = 725060,
            .dTxRate  = 0.002604016349127547,
        };
    }
};

/**
 * Testnet (v3): public test network which is reset from time to time.
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = CBaseChainParams::TESTNET;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 210000;
        consensus.script_flag_exceptions.emplace( // BIP16 exception
            uint256S("0x00000000dd30457c001f4095d208cc1296b0eed002427aa599874af7a432b105"), SCRIPT_VERIFY_NONE);
        consensus.BIP34Height = 21111;
        consensus.BIP34Hash = uint256S("0x0000000023b3a96d3484e5abb3755c413e7d41500f8e2a5c3f0dd01299cd8ef8");
        consensus.BIP65Height = 581885; // 00000000007f6655f22f98e72ed80d8b06dc761d5da09df0fa1dc4be4f861eb6
        consensus.BIP66Height = 330776; // 000000002104c8c45e99a8853285a3b592602a3ccde2b832481da85e9e4ba182
        consensus.CSVHeight = 770112; // 00000000025e930139bac5c6c31a403776da130831ab85be56578f3fa75369bb
        consensus.SegwitHeight = 834624; // 00000000002b980fcd729daaa248fd9316a5200e9b367f4ff2c42453e84201ca
        consensus.MinBIP9WarningHeight = 836640; // segwit activation height + miner confirmation window
        consensus.powLimit = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1512; // 75% for testchains
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = 1619222400; // April 24th, 2021
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = 1628640000; // August 11th, 2021
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        consensus.nMinimumChainWork = uint256S("0x0");
        consensus.defaultAssumeValid = uint256S("0x2e28050194ad73f2405394d2f081361a23c2df8904ec7f026a018bbe148d5adf"); // 2429000

        pchMessageStart[0] = 0x0b;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0x09;
        pchMessageStart[3] = 0x07;
        nDefaultPort = 18226;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 42;
        m_assumed_chain_state_size = 3;

        genesis = CreateGenesisBlock(1410213600, 237174, 0x1e0ffff0, 1, 367 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("2e28050194ad73f2405394d2f081361a23c2df8904ec7f026a018bbe148d5adf"));
        assert(genesis.hashMerkleRoot == uint256S("0xacd715d33d3288f616bfe281819a4d84bdea206b8c06088eec584095f5de891c"));

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        vSeeds.emplace_back("testnet-seed.globalboost.info.");
        vSeeds.emplace_back("seed.tbsty.globalboost.info.");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,65);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,193);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_test), std::end(chainparams_seed_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        m_is_test_chain = true;
        m_is_mockable_chain = false;

        checkpointData = {
            {
                {0, uint256S("2e28050194ad73f2405394d2f081361a23c2df8904ec7f026a018bbe148d5adf")},
            }
        };

        m_assumeutxo_data = MapAssumeutxo{
            // TODO to be specified in a future patch.
        };

        chainTxData = ChainTxData{
            // Data from RPC: getchaintxstats 4096 0000000000000021bc50a89cde4870d4a81ffe0153b3c8de77b435a2fd3f6761
            .nTime    = 1681542696,
            .nTxCount = 65345929,
            .dTxRate  = 0.09855282814711661,
        };
    }
};

/**
 * Signet: test network with an additional consensus parameter (see BIP325).
 */
class SigNetParams : public CChainParams {
public:
    explicit SigNetParams(const SigNetOptions& options)
    {
        std::vector<uint8_t> bin;
        vSeeds.clear();

        if (!options.challenge) {
            bin = ParseHex("512103ad5e0edad18cb1f0fc0d28a3d4f1f3e445640337489abb10404f2d1e086be430210359ef5021964fe22d6f8e05b2463c9540ce96883fe3b278760f048f5189f2e6c452ae");
            vSeeds.emplace_back("seed.signet.globalboost.info.");

            // Hardcoded nodes can be removed once there are more DNS seeds
            vSeeds.emplace_back("178.128.221.177");
            vSeeds.emplace_back("v7ajjeirttkbnt32wpy3c6w3emwnfr3fkla7hpxcfokr3ysd3kqtzmqd.onion:38226");

            consensus.nMinimumChainWork = uint256S("0x000000000000000000000000000000000000000000000000000001899d8142b0");
            consensus.defaultAssumeValid = uint256S("0x0000004429ef154f7e00b4f6b46bfbe2d2678ecd351d95bbfca437ab9a5b84ec"); // 138000
            m_assumed_blockchain_size = 1;
            m_assumed_chain_state_size = 0;
            chainTxData = ChainTxData{
                // Data from RPC: getchaintxstats 4096 0000004429ef154f7e00b4f6b46bfbe2d2678ecd351d95bbfca437ab9a5b84ec
                .nTime    = 1681127428,
                .nTxCount = 2226359,
                .dTxRate  = 0.006424463050600656,
            };
        } else {
            bin = *options.challenge;
            consensus.nMinimumChainWork = uint256{};
            consensus.defaultAssumeValid = uint256{};
            m_assumed_blockchain_size = 0;
            m_assumed_chain_state_size = 0;
            chainTxData = ChainTxData{
                0,
                0,
                0,
            };
            LogPrintf("Signet with challenge %s\n", HexStr(bin));
        }

        if (options.seeds) {
            vSeeds = *options.seeds;
        }

        strNetworkID = CBaseChainParams::SIGNET;
        consensus.signet_blocks = true;
        consensus.signet_challenge.assign(bin.begin(), bin.end());
        consensus.nSubsidyHalvingInterval = 240000;
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256{};
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1815; // 90% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256S("00000377ae000000000000000000000000000000000000000000000000000000");
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        // Activation of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        // message start is defined as the first 4 bytes of the sha256d of the block script
        HashWriter h{};
        h << consensus.signet_challenge;
        uint256 hash = h.GetHash();
        memcpy(pchMessageStart, hash.begin(), 4);

        nDefaultPort = 38226;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1410213600, 12348, 0x207fffff, 1, 367 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x9d78dbf0deeb8c66bf816db67d551e5f537d410de22e0e962836efc819bc35c3"));
        assert(genesis.hashMerkleRoot == uint256S("0xacd715d33d3288f616bfe281819a4d84bdea206b8c06088eec584095f5de891c"));

        vFixedSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        m_is_test_chain = true;
        m_is_mockable_chain = false;
    }
};

/**
 * Regression test: intended for private networks only. Has minimal difficulty to ensure that
 * blocks can be found instantly.
 */
class CRegTestParams : public CChainParams
{
public:
    explicit CRegTestParams(const RegTestOptions& opts)
    {
        strNetworkID =  CBaseChainParams::REGTEST;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP34Height = 1; // Always active unless overridden
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1;  // Always active unless overridden
        consensus.BIP66Height = 1;  // Always active unless overridden
        consensus.CSVHeight = 1;    // Always active unless overridden
        consensus.SegwitHeight = 0; // Always active unless overridden
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)

        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay

        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay

        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 18444;
        nPruneAfterHeight = opts.fastprune ? 100 : 1000;
        m_assumed_blockchain_size = 0;
        m_assumed_chain_state_size = 0;

        for (const auto& [dep, height] : opts.activation_heights) {
            switch (dep) {
            case Consensus::BuriedDeployment::DEPLOYMENT_SEGWIT:
                consensus.SegwitHeight = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_HEIGHTINCB:
                consensus.BIP34Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_DERSIG:
                consensus.BIP66Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_CLTV:
                consensus.BIP65Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_CSV:
                consensus.CSVHeight = int{height};
                break;
            }
        }

        for (const auto& [deployment_pos, version_bits_params] : opts.version_bits_parameters) {
            consensus.vDeployments[deployment_pos].nStartTime = version_bits_params.start_time;
            consensus.vDeployments[deployment_pos].nTimeout = version_bits_params.timeout;
            consensus.vDeployments[deployment_pos].min_activation_height = version_bits_params.min_activation_height;
        }

        genesis = CreateGenesisBlock(1410213600, 12348, 0x207fffff, 1, 367 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x9d78dbf0deeb8c66bf816db67d551e5f537d410de22e0e962836efc819bc35c3"));
        assert(genesis.hashMerkleRoot == uint256S("0xacd715d33d3288f616bfe281819a4d84bdea206b8c06088eec584095f5de891c"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();
        vSeeds.emplace_back("dummySeed.invalid.");

        fDefaultConsistencyChecks = true;
        fRequireStandard = true;
        m_is_test_chain = true;
        m_is_mockable_chain = true;

        checkpointData = {
            {
                {0, uint256S("9d78dbf0deeb8c66bf816db67d551e5f537d410de22e0e962836efc819bc35c3")},
            }
        };

        m_assumeutxo_data = MapAssumeutxo{
            {
                110,
                {AssumeutxoHash{uint256S("0x1ebbf5850204c0bdb15bf030f47c7fe91d45c44c712697e4509ba67adb01c618")}, 110},
            },
            {
                200,
                {AssumeutxoHash{uint256S("0x51c8d11d8b5c1de51543c579736e786aa2736206d1e11e627568029ce092cf62")}, 200},
            },
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "gbrt";
    }
};

std::unique_ptr<const CChainParams> CChainParams::SigNet(const SigNetOptions& options)
{
    return std::make_unique<const SigNetParams>(options);
}

std::unique_ptr<const CChainParams> CChainParams::RegTest(const RegTestOptions& options)
{
    return std::make_unique<const CRegTestParams>(options);
}

std::unique_ptr<const CChainParams> CChainParams::Main()
{
    return std::make_unique<const CMainParams>();
}

std::unique_ptr<const CChainParams> CChainParams::TestNet()
{
    return std::make_unique<const CTestNetParams>();
}
