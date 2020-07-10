#include "../include/instance.h"

unsigned instance::get_n() {return this->n;}

unsigned instance::get_B() {return this->B;}

void instance::read_from_file(const std::string& file_name) {
  std::ifstream _file;
  _file.open(file_name.c_str(), std::ifstream::in);

  if(_file.is_open()) {
    _file >> n >> B;

    items = std::vector< ITEM >(n);

    for(unsigned i = 0; i < n; i++) {
      _file >> items[i].cost;
    }
    for(unsigned i = 0; i < n; i++) {
      _file >> items[i].weight;
      items[i].benefit_ratio = items[i].cost/items[i].weight;
    }
  }
}

void instance::show_data() {
  std::cout << instance::get_n() << ' ' << instance::get_B() << std::endl;
  for (unsigned i = 0; i < items.size(); i++) {
    std::cout << items[i].cost << ' ';
    if (i == (items.size() - 1)) std::cout << std::endl;
  }
  for (unsigned i = 0; i < items.size(); i++) {
    std::cout << items[i].weight << ' ';
    if (i == (items.size() - 1)) std::cout << std::endl;
  }
}
