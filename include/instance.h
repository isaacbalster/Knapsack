#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

struct ITEM {
  unsigned cost;
  unsigned weight;
  double benefit_ratio;
};

class instance {
private:
  //Parameters
  unsigned n; //Number of items
  unsigned B; //Knapsack's capacity

  //Data
  std::vector< ITEM > items;

public:
  //Getters
  unsigned get_n();
  unsigned get_B();

  //Methods
  void read_from_file(const std::string&);
  void show_data();
};

#endif /* INSTANCE_H_ */
