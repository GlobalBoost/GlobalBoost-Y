# Libraries

| Name                     | Description |
|--------------------------|-------------|
| *libglobalboost_cli*         | RPC client functionality used by *globalboost-cli* executable |
| *libglobalboost_common*      | Home for common functionality shared by different executables and libraries. Similar to *libglobalboost_util*, but higher-level (see [Dependencies](#dependencies)). |
| *libglobalboost_consensus*   | Stable, backwards-compatible consensus functionality used by *libglobalboost_node* and *libglobalboost_wallet* and also exposed as a [shared library](../shared-libraries.md). |
| *libglobalboostconsensus*    | Shared library build of static *libglobalboost_consensus* library |
| *libglobalboost_kernel*      | Consensus engine and support library used for validation by *libglobalboost_node* and also exposed as a [shared library](../shared-libraries.md). |
| *libglobalboostqt*           | GUI functionality used by *globalboost-qt* and *globalboost-gui* executables |
| *libglobalboost_ipc*         | IPC functionality used by *globalboost-node*, *globalboost-wallet*, *globalboost-gui* executables to communicate when [`--enable-multiprocess`](multiprocess.md) is used. |
| *libglobalboost_node*        | P2P and RPC server functionality used by *globalboostd* and *globalboost-qt* executables. |
| *libglobalboost_util*        | Home for common functionality shared by different executables and libraries. Similar to *libglobalboost_common*, but lower-level (see [Dependencies](#dependencies)). |
| *libglobalboost_wallet*      | Wallet functionality used by *globalboostd* and *globalboost-wallet* executables. |
| *libglobalboost_wallet_tool* | Lower-level wallet functionality used by *globalboost-wallet* executable. |
| *libglobalboost_zmq*         | [ZeroMQ](../zmq.md) functionality used by *globalboostd* and *globalboost-qt* executables. |

## Conventions

- Most libraries are internal libraries and have APIs which are completely unstable! There are few or no restrictions on backwards compatibility or rules about external dependencies. Exceptions are *libglobalboost_consensus* and *libglobalboost_kernel* which have external interfaces documented at [../shared-libraries.md](../shared-libraries.md).

- Generally each library should have a corresponding source directory and namespace. Source code organization is a work in progress, so it is true that some namespaces are applied inconsistently, and if you look at [`libglobalboost_*_SOURCES`](../../src/Makefile.am) lists you can see that many libraries pull in files from outside their source directory. But when working with libraries, it is good to follow a consistent pattern like:

  - *libglobalboost_node* code lives in `src/node/` in the `node::` namespace
  - *libglobalboost_wallet* code lives in `src/wallet/` in the `wallet::` namespace
  - *libglobalboost_ipc* code lives in `src/ipc/` in the `ipc::` namespace
  - *libglobalboost_util* code lives in `src/util/` in the `util::` namespace
  - *libglobalboost_consensus* code lives in `src/consensus/` in the `Consensus::` namespace

## Dependencies

- Libraries should minimize what other libraries they depend on, and only reference symbols following the arrows shown in the dependency graph below:

<table><tr><td>

```mermaid

%%{ init : { "flowchart" : { "curve" : "basis" }}}%%

graph TD;

globalboost-cli[globalboost-cli]-->libglobalboost_cli;

globalboostd[globalboostd]-->libglobalboost_node;
globalboostd[globalboostd]-->libglobalboost_wallet;

globalboost-qt[globalboost-qt]-->libglobalboost_node;
globalboost-qt[globalboost-qt]-->libglobalboostqt;
globalboost-qt[globalboost-qt]-->libglobalboost_wallet;

globalboost-wallet[globalboost-wallet]-->libglobalboost_wallet;
globalboost-wallet[globalboost-wallet]-->libglobalboost_wallet_tool;

libglobalboost_cli-->libglobalboost_util;
libglobalboost_cli-->libglobalboost_common;

libglobalboost_common-->libglobalboost_consensus;
libglobalboost_common-->libglobalboost_util;

libglobalboost_kernel-->libglobalboost_consensus;
libglobalboost_kernel-->libglobalboost_util;

libglobalboost_node-->libglobalboost_consensus;
libglobalboost_node-->libglobalboost_kernel;
libglobalboost_node-->libglobalboost_common;
libglobalboost_node-->libglobalboost_util;

libglobalboostqt-->libglobalboost_common;
libglobalboostqt-->libglobalboost_util;

libglobalboost_wallet-->libglobalboost_common;
libglobalboost_wallet-->libglobalboost_util;

libglobalboost_wallet_tool-->libglobalboost_wallet;
libglobalboost_wallet_tool-->libglobalboost_util;

classDef bold stroke-width:2px, font-weight:bold, font-size: smaller;
class globalboost-qt,globalboostd,globalboost-cli,globalboost-wallet bold
```
</td></tr><tr><td>

**Dependency graph**. Arrows show linker symbol dependencies. *Consensus* lib depends on nothing. *Util* lib is depended on by everything. *Kernel* lib depends only on consensus and util.

</td></tr></table>

- The graph shows what _linker symbols_ (functions and variables) from each library other libraries can call and reference directly, but it is not a call graph. For example, there is no arrow connecting *libglobalboost_wallet* and *libglobalboost_node* libraries, because these libraries are intended to be modular and not depend on each other's internal implementation details. But wallet code is still able to call node code indirectly through the `interfaces::Chain` abstract class in [`interfaces/chain.h`](../../src/interfaces/chain.h) and node code calls wallet code through the `interfaces::ChainClient` and `interfaces::Chain::Notifications` abstract classes in the same file. In general, defining abstract classes in [`src/interfaces/`](../../src/interfaces/) can be a convenient way of avoiding unwanted direct dependencies or circular dependencies between libraries.

- *libglobalboost_consensus* should be a standalone dependency that any library can depend on, and it should not depend on any other libraries itself.

- *libglobalboost_util* should also be a standalone dependency that any library can depend on, and it should not depend on other internal libraries.

- *libglobalboost_common* should serve a similar function as *libglobalboost_util* and be a place for miscellaneous code used by various daemon, GUI, and CLI applications and libraries to live. It should not depend on anything other than *libglobalboost_util* and *libglobalboost_consensus*. The boundary between _util_ and _common_ is a little fuzzy but historically _util_ has been used for more generic, lower-level things like parsing hex, and _common_ has been used for globalboost-specific, higher-level things like parsing base58. The difference between util and common is mostly important because *libglobalboost_kernel* is not supposed to depend on *libglobalboost_common*, only *libglobalboost_util*. In general, if it is ever unclear whether it is better to add code to *util* or *common*, it is probably better to add it to *common* unless it is very generically useful or useful particularly to include in the kernel.


- *libglobalboost_kernel* should only depend on *libglobalboost_util* and *libglobalboost_consensus*.

- The only thing that should depend on *libglobalboost_kernel* internally should be *libglobalboost_node*. GUI and wallet libraries *libglobalboostqt* and *libglobalboost_wallet* in particular should not depend on *libglobalboost_kernel* and the unneeded functionality it would pull in, like block validation. To the extent that GUI and wallet code need scripting and signing functionality, they should be get able it from *libglobalboost_consensus*, *libglobalboost_common*, and *libglobalboost_util*, instead of *libglobalboost_kernel*.

- GUI, node, and wallet code internal implementations should all be independent of each other, and the *libglobalboostqt*, *libglobalboost_node*, *libglobalboost_wallet* libraries should never reference each other's symbols. They should only call each other through [`src/interfaces/`](`../../src/interfaces/`) abstract interfaces.

## Work in progress

- Validation code is moving from *libglobalboost_node* to *libglobalboost_kernel* as part of [The libglobalboostkernel Project #24303](https://github.com/globalboost/globalboost/issues/24303)
- Source code organization is discussed in general in [Library source code organization #15732](https://github.com/globalboost/globalboost/issues/15732)
