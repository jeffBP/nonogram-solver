#include <memory>

#include "nonogram.hpp"

template<class T>
class Population {
  Population<T>(int n);

private:
  std::vector<T> pop;
};