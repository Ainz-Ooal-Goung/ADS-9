// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <chrono>
#include "tree.h"

int main() {
  PMTree tree3(std::vector<char>{'1', '2', '3'});
  for (int k = 1; k <= 6; ++k) {
    auto perm = getPerm1(tree3, k);
    std::cout << "Perm1, k=" << k << ": ";
    for (char c : perm) {
      std::cout << c;
    }
    std::cout << '\n';
  }

  std::cout << "\nРазмер n; Время getPerm1 (мкс); Время getPerm2 (мкс)\n";
  for (int n = 1; n <= 8; ++n) {
    std::vector<char> elems;
    for (int i = 0; i < n; ++i) {
      elems.push_back(static_cast<char>('A' + i));
    }
    PMTree treeN(elems);
    int k = 1;
    for (int i = 1; i <= n; ++i) {
      k *= i;
    }
    k = k / 2;
    
    auto t1_start = std::chrono::steady_clock::now();
    auto p1 = getPerm1(treeN, k);
    auto t1_end = std::chrono::steady_clock::now();
    
    auto t2_start = std::chrono::steady_clock::now();
    auto p2 = getPerm2(treeN, k);
    auto t2_end = std::chrono::steady_clock::now();
    
    auto us1 = std::chrono::duration_cast<std::chrono::microseconds>(t1_end - t1_start).count();
    auto us2 = std::chrono::duration_cast<std::chrono::microseconds>(t2_end - t2_start).count();
    
    std::cout << n << "; " << us1 << "; " << us2 << "\n";
  }

  return 0;
}
