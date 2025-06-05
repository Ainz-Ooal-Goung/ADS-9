// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class PMTree {
 private:
  std::vector<char> elements_;
};

 public:
  PMTree(const std::vector<char>& elements);
  std::vector<char> getElements() const;

std::vector<char> getPerm1(const PMTree& tree, int k);
std::vector<char> getPerm2(const PMTree& tree, int k);

#endif  // INCLUDE_TREE_H_
