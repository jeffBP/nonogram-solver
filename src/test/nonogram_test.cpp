#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

#include "../nonogram.hpp"
#include "../nonogram_utils.hpp"

TEST(NonogramTest, NonogramConstructTest) {
  Nonogram n1 = Nonogram();

  // Default constructor, 5x5
  EXPECT_EQ(n1.getSize(), 25);
  EXPECT_EQ(n1.getHeight(), 5);
  EXPECT_EQ(n1.getWidth(), 5);

  Nonogram n2 = Nonogram(10, 5);
  EXPECT_EQ(n2.getSize(), 50);
  EXPECT_EQ(n2.getHeight(), 10);
  EXPECT_EQ(n2.getWidth(), 5);
}

TEST(NonogramTest, NonogramCellFlipTest) {
  Nonogram n1 = Nonogram(5, 5);
  n1.randomizeCells();
  cellVal original_val = n1.getCell(2, 3);
  n1.flipCell(2, 3);
  cellVal flipped_val = n1.getCell(2, 3);
  EXPECT_NE(original_val, flipped_val);
}

TEST(NonogramTest, NonogramMutateTest) {
  Nonogram n1 = Nonogram(5, 5);
  n1.randomizeCells();
  // Make copy of cells before mutation.
  std::vector<cellVal> before_mutation(n1.getSize());
  std::copy(n1.getCells().begin(), n1.getCells().end(), before_mutation.begin());
  n1.mutateRandomCell();
  // Make copy of cells after mutation
  std::vector<cellVal> after_mutation(n1.getSize());
  std::copy(n1.getCells().begin(), n1.getCells().end(), after_mutation.begin());
  EXPECT_NE(before_mutation, after_mutation);
}

TEST(NonogramTest, NonogramCrossTest) {
  srand(time(NULL));
  Nonogram n1 = Nonogram(5, 5);
  n1.randomizeCells();
  Nonogram n2 = Nonogram(5, 5);
  n2.randomizeCells();
  Nonogram n3 = Nonogram(10, 5);
  n3.randomizeCells();

  std::vector<cellVal> n1_front = n1.getFrontHalf();
  std::vector<cellVal> n2_front = n2.getFrontHalf();
  cross_nonograms(&n1, &n2);
  EXPECT_EQ(n1_front, n2.getFrontHalf());
  EXPECT_EQ(n2_front, n1.getFrontHalf());
  ASSERT_DEATH(cross_nonograms(&n1, &n3), "");
}