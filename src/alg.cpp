// Copyright 2022 NNTU-CS
#include <vector>
#include <algorithm>
#include <cstdint>
#include "tree.h"

static int64_t factorial(int n) {
  int64_t res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

PMTree::PMTree(const std::vector<char>& elements)
    : elements_(elements) {}

static std::vector<char> computeKthPerm(std::vector<char>& elems, int64_t k) {
  int n = static_cast<int>(elems.size());
  std::vector<char> answer;
  int64_t total = factorial(n);
  int64_t idx = k - 1;
  for (int i = n; i >= 1; --i) {
    int64_t f = factorial(i - 1);
    int64_t pos = idx / f;
    idx %= f;
    answer.push_back(elems[static_cast<std::size_t>(pos)]);
    elems.erase(elems.begin() + static_cast<std::size_t>(pos));
  }
  return answer;
}

std::vector<char> getPerm1(const PMTree& tree, int k) {
  std::vector<char> elems = tree.getElements();
  std::sort(elems.begin(), elems.end());
  return computeKthPerm(elems, k);
}

std::vector<char> getPerm2(const PMTree& tree, int k) {
  std::vector<char> elems = tree.getElements();
  std::sort(elems.rbegin(), elems.rend());
  int n = static_cast<int>(elems.size());
  int64_t total = factorial(n);
  int64_t mirrorIndex = total - k + 1;
  return computeKthPerm(elems, mirrorIndex);
}

std::vector<std::vector<char>> getAllPerms(const PMTree& tree) {
  std::vector<char> elems = tree.getElements();
  std::sort(elems.begin(), elems.end());
  std::vector<std::vector<char>> all;
  do {
    all.push_back(elems);
  } while (std::next_permutation(elems.begin(), elems.end()));
  return all;
}
