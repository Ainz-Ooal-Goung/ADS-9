// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class PMTree {
   public:
    explicit PMTree(const std::vector<char>& elements);
    std::vector<char> getElements() const;

   private:
    std::vector<char> elements_;
};

std::vector<char> getPerm1(const PMTree& tree, int k);
std::vector<char> getPerm2(const PMTree& tree, int k);
std::vector<std::vector<char>> getAllPerms(const PMTree& tree);

#endif  // INCLUDE_TREE_H_
