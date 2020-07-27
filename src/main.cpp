#include "../include/instance.h"
#include "../include/solution.h"
#include "../include/heuristics.h"

int main( int argc, char* argv[] ) {

  //Instantiating the instance class and reading data from instance file.
  instance knapsack;
  knapsack.read_from_file( argv[1] );
  //knapsack.show_instance();

  /* Instantiating the heuristics class and getting a solution instance
     instantiated from the greedy_heuristic method. */
  heuristics h;
  solution sol = h.greedy_heuristic( knapsack );

  /* Using some methods from the solution class to:
      1. Print the solution in console out; and,
      2. Writing the soluction vector x | x[i] \in {0,1} in an output file. */
  sol.print_solution();
  sol.write_sol_file ( "solution.txt" );

  return 0;
}
