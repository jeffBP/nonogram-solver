#pragma once

#include <cassert>

#include "nonogram.hpp"

void cross_nonograms(Nonogram* n1, Nonogram* n2) {
  assert(n1->getSize() == n2->getSize());
  const std::vector<cellVal> n1_front = n1->getFrontHalf();
  const std::vector<cellVal> n2_front = n2->getFrontHalf();
  n1->replaceFrontHalf(n2_front);
  n2->replaceFrontHalf(n1_front);
}