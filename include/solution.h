#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "instance.h"

#include <vector>
#include <string>
#include <fstream>

class solution {
private:
  //Instance Data
  instance knapsack;

  //Solution Data
  std::vector < unsigned > x;

  //Solution cost
  double cost;
  bool feasible;
  double weight_sum;

public:
  //Constructor
  solution();
  solution( instance& );
  solution( instance&, std::vector < unsigned >, double, bool, double );

  //Setters
  void set_cost( double );
  void set_feasible( bool );

  //Getters
  double get_cost();
  std::vector < unsigned > get_x();

  //Methods
  bool is_feasible();
  void print_solution();
  void write_sol_file( const std::string );

};

#endif
