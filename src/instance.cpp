#include "../include/instance.h"

unsigned instance::get_n() { return this->n; }

unsigned instance::get_B() { return this->B; }

std::vector< ITEM > instance::get_items() { return this->items; }

void instance::read_from_file( const std::string &file_name ) {
  std::ifstream _file;
  _file.open(file_name.c_str(), std::ifstream::in);

  if(_file.is_open()) {
    _file >> n >> B;

    items = std::vector< ITEM >( n );

    for(unsigned i = 0; i < n; i++) {
      items[i].index = i;
      _file >> items[i].profit;
      _file >> items[i].weight;
      items[i].benefit_ratio = (double) items[i].profit/items[i].weight;
    }

    _file.close();
  }
}

void instance::show_instance() {
  std::cout << instance::get_n() << std::endl << instance::get_B() << std::endl;
  for (unsigned i = 0; i < items.size(); i++) {
    std::cout << i << ' ' << items[i].profit << ' ' << items[i].weight << std::endl;
  }
}
