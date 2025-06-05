// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"

static long long factorial(int n) {
  long long res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

PMTree::PMTree(const std::vector<char>& elements)
  : elements_(elements) {}

std::vector<char> PMTree::getElements() const {
  return elements_;
}

static std::vector<char> computeKthPerm(std::vector<char> elems, int k) {
  int n = static_cast<int>(elems.size());
  long long total = factorial(n);
  if (k < 1 || k > total) {
    return std::vector<char>();
  }
  std::vector<char> result;
  long long idx = k - 1;
  for (int i = n; i >= 1; --i) {
    long long f = factorial(i - 1);
    int pos = static_cast<int>(idx / f);
    result.push_back(elems[pos]);
    elems.erase(elems.begin() + pos);
    idx %= f;
  }
  return result;
}

std::vector<char> getPerm1(const PMTree& tree, int k) {
  std::vector<char> elems = tree.getElements();
  std::sort(elems.begin(), elems.end());
  return computeKthPerm(elems, k);
}

std::vector<char> getPerm2(const PMTree& tree, int k) {
  std::vector<char> elems = tree.getElements();
  std::sort(elems.begin(), elems.end());
  return computeKthPerm(elems, k);
}
