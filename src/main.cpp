// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cstdint>
#include "tree.h"

int main() {
  std::ofstream out("data.csv");
  out << "N,getPerm1,getPerm2,getAllPerm\n";
  for (int n = 1; n <= 8; ++n) {
    std::vector<char> elems;
    for (int i = 0; i < n; ++i) {
      elems.push_back('a' + i);
    }
    PMTree tree(elems);
    int64_t total = 1;
    for (int i = 2; i <= n; ++i) {
      total *= i;
    }
    int idx = static_cast<int>(total);
    auto start1 = std::chrono::high_resolution_clock::now();
    getPerm1(tree, idx);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto dur1 = std::chrono::duration_cast<std::chrono::microseconds>(
      end1 - start1).count();
    auto start2 = std::chrono::high_resolution_clock::now();
    getPerm2(tree, idx);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto dur2 = std::chrono::duration_cast<std::chrono::microseconds>(
      end2 - start2).count();
    auto startAll = std::chrono::high_resolution_clock::now();
    getAllPerm(tree);
    auto endAll = std::chrono::high_resolution_clock::now();
    auto durAll = std::chrono::duration_cast<std::chrono::microseconds>(
      endAll - startAll).count();
    out << n << "," << dur1 << "," << dur2 << "," << durAll << "\n";
  }
  return 0;
}
