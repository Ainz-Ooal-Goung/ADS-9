// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class PMTree {
  std::vector<char> elements;
 public:
  explicit PMTree(const std::vector<char>& elems);
  std::vector<char> getElements() const;
};
std::vector<std::vector<char>> getAllPerm(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int index);
std::vector<char> getPerm2(PMTree& tree, int index);
#endif  // INCLUDE_TREE_H_
