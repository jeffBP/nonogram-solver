#include <vector>
#include <string>
#include <iostream>

#include "src/nonogram.hpp"
#include "src/nonogram_utils.hpp"

int main(int argc, char** argv) {
  Nonogram n1 = Nonogram();
  Nonogram n2 = Nonogram();

  srand(time(NULL));
  n1.randomizeCells();
  n2.randomizeCells();
  std::cout << "Before Swap:" << std::endl;
  for (size_t i = 0; i < n1.getFrontHalf().size(); ++i) {
    std::cout << std::to_string(n1.getFrontHalf().at(i)) << std::endl;
  }
  cross_nonograms(&n1, &n2);
  std::cout << std::endl << "After Swap:" << std::endl;
  for (size_t i = 0; i < n1.getFrontHalf().size(); ++i) {
    std::cout << std::to_string(n1.getFrontHalf().at(i)) << std::endl;
  }

}