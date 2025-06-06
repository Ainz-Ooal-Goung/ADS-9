// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdint>
#include "tree.h"

int main() {
  std::cout << "n,total_ns1,total_ns2,total_ns_all\n";
  const int REPEATS = 10000;
  for (int n = 1; n <= 8; ++n) {
    std::vector<char> elems;
    for (int i = 0; i < n; ++i) {
      elems.push_back(static_cast<char>('A' + i));
    }
    PMTree treeN(elems);

    auto t1_start = std::chrono::steady_clock::now();
    for (int i = 1; i <= REPEATS; ++i) {
      volatile auto p = getPerm1(treeN, i % factorial(n) + 1);
      (void)p;
    }
    auto t1_end = std::chrono::steady_clock::now();

    auto t2_start = std::chrono::steady_clock::now();
    for (int i = 1; i <= REPEATS; ++i) {
      volatile auto p = getPerm2(treeN, i % factorial(n) + 1);
      (void)p;
    }
    auto t2_end = std::chrono::steady_clock::now();

    auto tall_start = std::chrono::steady_clock::now();
    volatile auto all = getAllPerms(treeN);
    auto tall_end = std::chrono::steady_clock::now();

    auto d1 = t1_end - t1_start;
    auto total_ns1 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(d1).count();

    auto d2 = t2_end - t2_start;
    auto total_ns2 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(d2).count();

    auto dall = tall_end - tall_start;
    auto total_ns_all =
        std::chrono::duration_cast<std::chrono::nanoseconds>(dall).count();

    std::cout << n << "," << total_ns1 << "," << total_ns2 << ","
              << total_ns_all << "\n";
  }

  return 0;
}
