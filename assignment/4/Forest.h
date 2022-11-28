#ifndef CSI2372_ASSIGNMENT_4_FOREST_H_
#define CSI2372_ASSIGNMENT_4_FOREST_H_

#include "Graph.h"

class Forest : public Graph {
 public:
  // methods
  bool add_edge(int u, int v) override;

  // operators
  friend std::ostream& operator<<(std::ostream& out, const Forest& forest);
};

#endif // CSI2372_ASSIGNMENT_4_FOREST_H_
