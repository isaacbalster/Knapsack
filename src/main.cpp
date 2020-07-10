#include "../include/instance.h"

int main(int argc, char* argv[]) {
  instance knapsack;
  knapsack.read_from_file(argv[1]);
  knapsack.show_data();
  return 0;
}
