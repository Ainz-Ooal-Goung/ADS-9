// Copyright 2022 NNTU-CS
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdint>
#include "tree.h"

static int64_t factorial(int n) {
  int64_t result = 1;
  for (int i = 2; i <= n; ++i) result *= i;
  return result;
}
static void recursePerm(std::vector<char>& a,
  int l,
  std::vector<std::vector<char>>& res) {
  int n = static_cast<int>(a.size());
  if (l == n) {
    res.push_back(a);
    return;
  }
  for (int i = l; i < n; ++i) {
    std::swap(a[l], a[i]);
    recursePerm(a, l + 1, res);
    std::swap(a[l], a[i]);
  }
}
std::vector<std::vector<char>> getAllPerm(PMTree& tree) {
  std::vector<char> elems = tree.getElements();
  std::vector<std::vector<char>> all;
  recursePerm(elems, 0, all);
  return all;
}
std::vector<char> getPerm1(PMTree& tree, int index) {
  std::vector<char> elems = tree.getElements();
  int n = static_cast<int>(elems.size());
  int64_t total = factorial(n);
  if (index < 1 || index > total) return {};
  std::sort(elems.begin(), elems.end());
  int idx = index - 1;
  for (int i = 0; i < idx; ++i) {
    std::next_permutation(elems.begin(), elems.end());
  }
  return elems;
}
std::vector<char> getPerm2(PMTree& tree, int index) {
  std::vector<char> elems = tree.getElements();
  int n = static_cast<int>(elems.size());
  int64_t total = factorial(n);
  if (index < 1 || index > total) return {};
  std::sort(elems.begin(), elems.end());
  int idx = index - 1;
  std::vector<char> result;
  std::vector<char> available = elems;
  for (int i = n; i >= 1; --i) {
    int64_t f = factorial(i - 1);
    int pos = idx / f;
    result.push_back(available[pos]);
    available.erase(available.begin() + pos);
    idx %= f;
  }
  return result;
}
