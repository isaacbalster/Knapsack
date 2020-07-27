#include "../include/heuristics.h"

bool compare(const ITEM &a, const ITEM &b) {
  return a.benefit_ratio > b.benefit_ratio;
}

solution heuristics::greedy_heuristic( instance &_knapsack ) {
  this->knapsack = _knapsack;
  this->data_array = _knapsack.get_items();

  this->_x = std::vector< unsigned >( knapsack.get_n(), 0 );

  std::sort( data_array.begin(), data_array.end(), compare);

  double weight_sum = 0;
  double profit_sum = 0;

  for (unsigned i = 0; i < data_array.size(); i++) {
    if (this->data_array[i].weight + weight_sum <= this->knapsack.get_B()) {
      weight_sum += this->data_array[i].weight;
      profit_sum += this->data_array[i].profit;
      this->_x[ data_array[i].index ] = 1;
    }
  }

  std::cout << std::endl << std::endl;

  return solution ( this->knapsack, this->_x, profit_sum, true, weight_sum );
}
