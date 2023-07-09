Release Process
====================

## Branch updates

### Before every release candidate

* Update translations see [translation_process.md](https://github.com/globalboost/globalboost/blob/master/doc/translation_process.md#synchronising-translations).
* Update release candidate version in `configure.ac` (`CLIENT_VERSION_RC`).
* Update manpages (after rebuilding the binaries), see [gen-manpages.py](https://github.com/globalboost/globalboost/blob/master/contrib/devtools/README.md#gen-manpagespy).
* Update globalboost.conf and commit, see [gen-globalboost-conf.sh](https://github.com/globalboost/globalboost/blob/master/contrib/devtools/README.md#gen-globalboost-confsh).

### Before every major and minor release

* Update [bips.md](bips.md) to account for changes since the last release (don't forget to bump the version number on the first line).
* Update version in `configure.ac` (don't forget to set `CLIENT_VERSION_RC` to `0`).
* Update manpages (see previous section)
* Write release notes (see "Write the release notes" below).

### Before every major release

* On both the master branch and the new release branch:
  - update `CLIENT_VERSION_MAJOR` in [`configure.ac`](../configure.ac)
* On the new release branch in [`configure.ac`](../configure.ac)(see [this commit](https://github.com/globalboost/globalboost/commit/742f7dd)):
  - set `CLIENT_VERSION_MINOR` to `0`
  - set `CLIENT_VERSION_BUILD` to `0`
  - set `CLIENT_VERSION_IS_RELEASE` to `true`

#### Before branch-off

* Update hardcoded [seeds](/contrib/seeds/README.md), see [this pull request](https://github.com/globalboost/globalboost/pull/7415) for an example.
* Update the following variables in [`src/kernel/chainparams.cpp`](/src/kernel/chainparams.cpp) for mainnet, testnet, and signet:
  - `m_assumed_blockchain_size` and `m_assumed_chain_state_size` with the current size plus some overhead (see
    [this](#how-to-calculate-assumed-blockchain-and-chain-state-size) for information on how to calculate them).
  - The following updates should be reviewed with `reindex-chainstate` and `assumevalid=0` to catch any defect
    that causes rejection of blocks in the past history.
  - `chainTxData` with statistics about the transaction count and rate. Use the output of the `getchaintxstats` RPC with an
    `nBlocks` of 4096 (28 days) and a `bestblockhash` of RPC `getbestblockhash`; see
    [this pull request](https://github.com/globalboost/globalboost/pull/20263) for an example. Reviewers can verify the results by running
    `getchaintxstats <window_block_count> <window_final_block_hash>` with the `window_block_count` and `window_final_block_hash` from your output.
  - `defaultAssumeValid` with the output of RPC `getblockhash` using the `height` of `window_final_block_height` above
    (and update the block height comment with that height), taking into account the following:
    - On mainnet, the selected value must not be orphaned, so it may be useful to set the height two blocks back from the tip.
    - Testnet should be set with a height some tens of thousands back from the tip, due to reorgs there.
  - `nMinimumChainWork` with the "chainwork" value of RPC `getblockheader` using the same height as that selected for the previous step.
- Clear the release notes and move them to the wiki (see "Write the release notes" below).
- Translations on Transifex:
    - Pull translations from Transifex into the master branch.
    - Create [a new resource](https://www.transifex.com/globalboost/globalboost/content/) named after the major version with the slug `qt-translation-<RRR>x`, where `RRR` is the major branch number padded with zeros. Use `src/qt/locale/globalboost_en.xlf` to create it.
    - In the project workflow settings, ensure that [Translation Memory Fill-up](https://help.transifex.com/en/articles/6224817-setting-up-translation-memory-fill-up) is enabled and that [Translation Memory Context Matching](https://help.transifex.com/en/articles/6224753-translation-memory-with-context) is disabled.
    - Update the Transifex slug in [`.tx/config`](/.tx/config) to the slug of the resource created in the first step. This identifies which resource the translations will be synchronized from.
    - Make an announcement that translators can start translating for the new version. You can use one of the [previous announcements](https://www.transifex.com/globalboost/communication/) as a template.
    - Change the auto-update URL for the resource to `master`, e.g. `https://raw.githubusercontent.com/globalboost/globalboost/master/src/qt/locale/globalboost_en.xlf`. (Do this only after the previous steps, to prevent an auto-update from interfering.)

#### After branch-off (on the major release branch)

- Update the versions.
- Create the draft, named "*version* Release Notes Draft", as a [collaborative wiki](https://github.com/globalboost-core/globalboost-devwiki/wiki/_new).
- Clear the release notes: `cp doc/release-notes-empty-template.md doc/release-notes.md`
- Create a pinned meta-issue for testing the release candidate (see [this issue](https://github.com/globalboost/globalboost/issues/17079) for an example) and provide a link to it in the release announcements where useful.
- Translations on Transifex
    - Change the auto-update URL for the new major version's resource away from `master` and to the branch, e.g. `https://raw.githubusercontent.com/globalboost/globalboost/<branch>/src/qt/locale/globalboost_en.xlf`. Do not forget this or it will keep tracking the translations on master instead, drifting away from the specific major release.

#### Before final release

- Merge the release notes from [the wiki](https://github.com/globalboost-core/globalboost-devwiki/wiki/) into the branch.
- Ensure the "Needs release note" label is removed from all relevant pull requests and issues.

#### Tagging a release (candidate)

To tag the version (or release candidate) in git, use the `make-tag.py` script from [globalboost-maintainer-tools](https://github.com/globalboost-core/globalboost-maintainer-tools). From the root of the repository run:

    ../globalboost-maintainer-tools/make-tag.py v(new version, e.g. 23.0)

This will perform a few last-minute consistency checks in the build system files, and if they pass, create a signed tag.

## Building

### First time / New builders

Install Guix using one of the installation methods detailed in
[contrib/guix/INSTALL.md](/contrib/guix/INSTALL.md).

Check out the source code in the following directory hierarchy.

    cd /path/to/your/toplevel/build
    git clone https://github.com/globalboost-core/guix.sigs.git
    git clone https://github.com/globalboost-core/globalboost-detached-sigs.git
    git clone https://github.com/globalboost/globalboost.git

### Write the release notes

Open a draft of the release notes for collaborative editing at https://github.com/globalboost-core/globalboost-devwiki/wiki.

For the period during which the notes are being edited on the wiki, the version on the branch should be wiped and replaced with a link to the wiki which should be used for all announcements until `-final`.

Generate the change log. As this is a huge amount of work to do manually, there is the `list-pulls` script to do a pre-sorting step based on github PR metadata. See the [documentation in the README.md](https://github.com/globalboost-core/globalboost-maintainer-tools/blob/master/README.md#list-pulls).

Generate list of authors:

    git log --format='- %aN' v(current version, e.g. 24.0)..v(new version, e.g. 24.1) | sort -fiu

### Setup and perform Guix builds

Checkout the GlobalBoost Core version you'd like to build:

```sh
pushd ./globalboost
SIGNER='(your builder key, ie bluematt, sipa, etc)'
VERSION='(new version without v-prefix, e.g. 24.0)'
git fetch origin "v${VERSION}"
git checkout "v${VERSION}"
popd
```

Ensure your guix.sigs are up-to-date if you wish to `guix-verify` your builds
against other `guix-attest` signatures.

```sh
git -C ./guix.sigs pull
```

### Create the macOS SDK tarball (first time, or when SDK version changes)

Create the macOS SDK tarball, see the [macdeploy
instructions](/contrib/macdeploy/README.md#deterministic-macos-dmg-notes) for
details.

### Build and attest to build outputs

Follow the relevant Guix README.md sections:
- [Building](/contrib/guix/README.md#building)
- [Attesting to build outputs](/contrib/guix/README.md#attesting-to-build-outputs)

### Verify other builders' signatures to your own (optional)

- [Verifying build output attestations](/contrib/guix/README.md#verifying-build-output-attestations)

### Commit your non codesigned signature to guix.sigs

```sh
pushd ./guix.sigs
git add "${VERSION}/${SIGNER}"/noncodesigned.SHA256SUMS{,.asc}
git commit -m "Add attestations by ${SIGNER} for ${VERSION} non-codesigned"
git push  # Assuming you can push to the guix.sigs tree
popd
```

## Codesigning

### macOS codesigner only: Create detached macOS signatures (assuming [signapple](https://github.com/achow101/signapple/) is installed and up to date with master branch)

    tar xf globalboost-osx-unsigned.tar.gz
    ./detached-sig-create.sh /path/to/codesign.p12
    Enter the keychain password and authorize the signature
    signature-osx.tar.gz will be created

### Windows codesigner only: Create detached Windows signatures

    tar xf globalboost-win-unsigned.tar.gz
    ./detached-sig-create.sh -key /path/to/codesign.key
    Enter the passphrase for the key when prompted
    signature-win.tar.gz will be created

### Windows and macOS codesigners only: test code signatures
It is advised to test that the code signature attaches properly prior to tagging by performing the `guix-codesign` step.
However if this is done, once the release has been tagged in the globalboost-detached-sigs repo, the `guix-codesign` step must be performed again in order for the guix attestation to be valid when compared against the attestations of non-codesigner builds.

### Windows and macOS codesigners only: Commit the detached codesign payloads

```sh
pushd ./globalboost-detached-sigs
# checkout the appropriate branch for this release series
rm -rf ./*
tar xf signature-osx.tar.gz
tar xf signature-win.tar.gz
git add -A
git commit -m "point to ${VERSION}"
git tag -s "v${VERSION}" HEAD
git push the current branch and new tag
popd
```

### Non-codesigners: wait for Windows and macOS detached signatures

- Once the Windows and macOS builds each have 3 matching signatures, they will be signed with their respective release keys.
- Detached signatures will then be committed to the [globalboost-detached-sigs](https://github.com/globalboost-core/globalboost-detached-sigs) repository, which can be combined with the unsigned apps to create signed binaries.

### Create the codesigned build outputs

- [Codesigning build outputs](/contrib/guix/README.md#codesigning-build-outputs)

### Verify other builders' signatures to your own (optional)

- [Verifying build output attestations](/contrib/guix/README.md#verifying-build-output-attestations)

### Commit your codesigned signature to guix.sigs (for the signed macOS/Windows binaries)

```sh
pushd ./guix.sigs
git add "${VERSION}/${SIGNER}"/all.SHA256SUMS{,.asc}
git commit -m "Add attestations by ${SIGNER} for ${VERSION} codesigned"
git push  # Assuming you can push to the guix.sigs tree
popd
```

## After 3 or more people have guix-built and their results match

Combine the `all.SHA256SUMS.asc` file from all signers into `SHA256SUMS.asc`:

```bash
cat "$VERSION"/*/all.SHA256SUMS.asc > SHA256SUMS.asc
```


- Upload to the globalboostcore.org server (`/var/www/bin/globalboost-core-${VERSION}/`):
    1. The contents of each `./globalboost/guix-build-${VERSION}/output/${HOST}/` directory, except for
       `*-debug*` files.

       Guix will output all of the results into host subdirectories, but the SHA256SUMS
       file does not include these subdirectories. In order for downloads via torrent
       to verify without directory structure modification, all of the uploaded files
       need to be in the same directory as the SHA256SUMS file.

       The `*-debug*` files generated by the guix build contain debug symbols
       for troubleshooting by developers. It is assumed that anyone that is
       interested in debugging can run guix to generate the files for
       themselves. To avoid end-user confusion about which file to pick, as well
       as save storage space *do not upload these to the globalboostcore.org server,
       nor put them in the torrent*.

       ```sh
       find guix-build-${VERSION}/output/ -maxdepth 2 -type f -not -name "SHA256SUMS.part" -and -not -name "*debug*" -exec scp {} user@globalboostcore.org:/var/www/bin/globalboost-core-${VERSION} \;
       ```

    2. The `SHA256SUMS` file

    3. The `SHA256SUMS.asc` combined signature file you just created

- Create a torrent of the `/var/www/bin/globalboost-core-${VERSION}` directory such
  that at the top level there is only one file: the `globalboost-core-${VERSION}`
  directory containing everything else. Name the torrent
  `globalboost-${VERSION}.torrent` (note that there is no `-core-` in this name).

  Optionally help seed this torrent. To get the `magnet:` URI use:

  ```sh
  transmission-show -m <torrent file>
  ```

  Insert the magnet URI into the announcement sent to mailing lists. This permits
  people without access to `globalboostcore.org` to download the binary distribution.
  Also put it into the `optional_magnetlink:` slot in the YAML file for
  globalboostcore.org.

- Update other repositories and websites for new version

  - globalboostcore.org blog post

  - globalboostcore.org maintained versions update:
    [table](https://github.com/globalboost-core/globalboostcore.org/commits/master/_includes/posts/maintenance-table.md)

  - Delete post-EOL [release branches](https://github.com/globalboost/globalboost/branches/all) and create a tag `v${branch_name}-final`.

  - Delete ["Needs backport" labels](https://github.com/globalboost/globalboost/labels?q=backport) for non-existing branches.

  - globalboostcore.org RPC documentation update

      - Install [golang](https://golang.org/doc/install)

      - Install the new GlobalBoost Core release

      - Run globalboostd on regtest

      - Clone the [globalboostcore.org repository](https://github.com/globalboost-core/globalboostcore.org)

      - Run: `go run generate.go` while being in `contrib/doc-gen` folder, and with globalboost-cli in PATH

      - Add the generated files to git

  - Update packaging repo

      - Push the flatpak to flathub, e.g. https://github.com/flathub/org.globalboostcore.globalboost-qt/pull/2

      - Push the snap, see https://github.com/globalboost-core/packaging/blob/master/snap/build.md

  - This repo

      - Archive the release notes for the new version to `doc/release-notes/` (branch `master` and branch of the release)

      - Create a [new GitHub release](https://github.com/globalboost/globalboost/releases/new) with a link to the archived release notes

- Announce the release:

  - globalboost-dev and globalboost-core-dev mailing list

  - GlobalBoost Core announcements list https://globalboostcore.org/en/list/announcements/join/

  - GlobalBoost Core Twitter https://twitter.com/globalboostcoreorg

  - Celebrate

### Additional information

#### <a name="how-to-calculate-assumed-blockchain-and-chain-state-size"></a>How to calculate `m_assumed_blockchain_size` and `m_assumed_chain_state_size`

Both variables are used as a guideline for how much space the user needs on their drive in total, not just strictly for the blockchain.
Note that all values should be taken from a **fully synced** node and have an overhead of 5-10% added on top of its base value.

To calculate `m_assumed_blockchain_size`, take the size in GiB of these directories:
- For `mainnet` -> the data directory, excluding the `/testnet3`, `/signet`, and `/regtest` directories and any overly large files, e.g. a huge `debug.log`
- For `testnet` -> `/testnet3`
- For `signet` -> `/signet`

To calculate `m_assumed_chain_state_size`, take the size in GiB of these directories:
- For `mainnet` -> `/chainstate`
- For `testnet` -> `/testnet3/chainstate`
- For `signet` -> `/signet/chainstate`

Notes:
- When taking the size for `m_assumed_blockchain_size`, there's no need to exclude the `/chainstate` directory since it's a guideline value and an overhead will be added anyway.
- The expected overhead for growth may change over time. Consider whether the percentage needs to be changed in response; if so, update it here in this section.
