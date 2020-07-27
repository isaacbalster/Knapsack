#include "../include/solution.h"

solution::solution() : cost(0) {}

solution::solution( instance &_knapsack ) {
  this->knapsack = _knapsack;
  this->x = std::vector< unsigned >( knapsack.get_n() );
  this->cost = 0;
  this->feasible = true;
}

solution::solution( instance &_knapsack, std::vector< unsigned > _x, double _cost, bool _feasible, double _weight_sum ) : cost(_cost), feasible(_feasible), weight_sum(_weight_sum) {
  this->knapsack = _knapsack;
  this->x = _x;
}

void solution::set_cost( double _cost ) { this->cost = _cost; }

void solution::set_feasible( bool _feasible ) { this->feasible = _feasible; }

double solution::get_cost() { return this->cost; }

std::vector < unsigned > solution::get_x() { return this->x; }

bool solution::is_feasible() { return this->feasible; }

void solution::print_solution() {

  std::vector < ITEM > temp = this->knapsack.get_items();

  std::cout << "Heuristic solution with profit " << this->cost << ":\n" << std::endl;

  for (unsigned i = 0 ; i < this->x.size() ; i++) {
    if (this->x[i] == 1) {
      std::cout << "Item " << i << " picked ( p[" << i << "] = " << temp[i].profit << ", w[" << i << "] = " << temp[i].weight << " )" << std::endl;
    }
  }

  std::cout << std::endl << "Weight's sum: " << this->weight_sum << ", Knapsack capacity: " << this->knapsack.get_B() << ".\n" << std::endl;

}

void solution::write_sol_file( const std::string file_name ) {
  std::fstream _file;
  _file.open(file_name.c_str(), std::fstream::out);

  if(_file.is_open()) {

    for (unsigned i = 0 ; i < this->x.size() ; i++) {
      _file << this->x[i] << std::endl;
    }

    _file.close();
  }
}
