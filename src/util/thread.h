// Copyright (c) 2021-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GLOBALBOOST_UTIL_THREAD_H
#define GLOBALBOOST_UTIL_THREAD_H

#include <functional>
#include <string>

namespace util {
/**
 * A wrapper for do-something-once thread functions.
 */
void TraceThread(std::string_view thread_name, std::function<void()> thread_func);

} // namespace util

#endif // GLOBALBOOST_UTIL_THREAD_H
