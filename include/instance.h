#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

struct ITEM {
  unsigned index;
  unsigned profit;
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
  std::vector< ITEM > get_items();

  //Methods
  void read_from_file( const std::string& );
  void show_instance();
};

#endif /* INSTANCE_H_ */
