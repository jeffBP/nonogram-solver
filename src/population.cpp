#include "population.hpp"

template <class T>
Population<T>::Population(int n): pop(std::vector<T>(n, T())) {}


