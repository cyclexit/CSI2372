#ifndef CSI2372_ASSIGNMENT_4_TREE_H_
#define CSI2372_ASSIGNMENT_4_TREE_H_

#include "Forest.h"

class Tree : public Forest {
 public:
  // ctors and dtors
  Tree();

  // methods
  bool set_root(int node);

  // operators
  Graph& operator++() override;
  Graph operator++(int) override;
  Graph& operator--() override;
  Graph operator--(int) override;
  friend std::ostream& operator<<(std::ostream& out, const Tree& tree);

 protected:
  int root;
};

#endif // CSI2372_ASSIGNMENT_4_TREE_H_
