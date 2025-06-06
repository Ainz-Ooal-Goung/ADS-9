// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <chrono>
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

    long long K = 1;
    for (int i = 1; i <= n; ++i) K *= i;
    K /= 2;

    auto t1_start = std::chrono::steady_clock::now();
    for (int r = 0; r < REPEATS; ++r) {
      volatile auto p1 = getPerm1(treeN, static_cast<int>(K));
    }
    auto t1_end = std::chrono::steady_clock::now();

    auto t2_start = std::chrono::steady_clock::now();
    for (int r = 0; r < REPEATS; ++r) {
      volatile auto p2 = getPerm2(treeN, static_cast<int>(K));
    }
    auto t2_end = std::chrono::steady_clock::now();

    auto tall_start = std::chrono::steady_clock::now();
    volatile auto all = getAllPerms(treeN);
    auto tall_end = std::chrono::steady_clock::now();

    auto total_ns1 = std::chrono::duration_cast<std::chrono::nanoseconds>(t1_end - t1_start).count();
    auto total_ns2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2_end - t2_start).count();
    auto total_ns_all = std::chrono::duration_cast<std::chrono::nanoseconds>(tall_end - tall_start).count();

    std::cout << n << "," << total_ns1 << "," << total_ns2 << "," << total_ns_all << "\n";
  }

  return 0;
}
