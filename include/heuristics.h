#ifndef HEURISTICS_H_
#define HEURISTICS_H_

#include "instance.h"
#include "solution.h"

#include <vector>
#include <algorithm>

class heuristics {
private:
  //Instance Data
  instance knapsack;

  //Solution vector;
  std::vector< unsigned > _x;

  //Instance Data
  std::vector < ITEM > data_array;

public:
  //Heuristic methods
  solution greedy_heuristic( instance& );

};

#endif
