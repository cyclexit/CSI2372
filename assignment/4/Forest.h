// Hongyi Lin 300053082
// Stacy Guo 300157080

#ifndef CSI2372_ASSIGNMENT_4_FOREST_H_
#define CSI2372_ASSIGNMENT_4_FOREST_H_

#include "Graph.h"

class Forest : public Graph {
 public:
  // ctors and dtors
  Forest();
  Forest(int node_count);
  Forest(const Forest& other);
  ~Forest() = default;

  // methods
  bool add_edge(int u, int v) override;
};

#endif // CSI2372_ASSIGNMENT_4_FOREST_H_
