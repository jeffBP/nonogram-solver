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
  cellVal original_val = n1.getCell(2, 3);
  n1.flipCell(2, 3);
  cellVal flipped_val = n1.getCell(2, 3);
  EXPECT_NE(original_val, flipped_val);
}

TEST(NonogramTest, NonogramFlipCellTest) {
  srand(time(NULL));
  Nonogram n1 = Nonogram(5, 5);
  // Make copy of cells before mutation.
  std::vector<cellVal> before_mutation(n1.getSize());
  std::copy(n1.getCells().begin(), n1.getCells().end(), before_mutation.begin());
  n1.flipRandomCell();
  // Make copy of cells after mutation
  std::vector<cellVal> after_mutation(n1.getSize());
  std::copy(n1.getCells().begin(), n1.getCells().end(), after_mutation.begin());
  EXPECT_NE(before_mutation, n1.getCells());
}

TEST(NonogramTest, NonogramTransposeTest) {
  srand(time(NULL));
  Nonogram n1 = Nonogram(5, 5);
  std::vector<cellVal> before_mutation(n1.getSize());
  std::copy(n1.getCells().begin(), n1.getCells().end(), before_mutation.begin());
  std::pair<int, int> indices = n1.transposeRandomCells();

  // Handle case transposing the same cell value.
  if (n1.getCell(indices.first) == n1.getCell(indices.second)) {
    EXPECT_EQ(before_mutation, n1.getCells());
  } else {
    EXPECT_NE(before_mutation, n1.getCells());
  }
}

// Small chance this test fails for now. There is a case where inserting a new value
// produces an identical nonogram.
TEST(NonogramTest, NonogramInsertTest) {
  srand(time(NULL));
  Nonogram n1 = Nonogram(5, 5);
  std::vector<cellVal> before_mutation(n1.getSize());
  std::copy(n1.getCells().begin(), n1.getCells().end(), before_mutation.begin());
  n1.insertRandomCellValAtRandomIdx();
  EXPECT_NE(before_mutation, n1.getCells());
}

TEST(NonogramTest, NonogramCrossTest) {
  srand(time(NULL));
  Nonogram n1 = Nonogram(5, 5);
  Nonogram n2 = Nonogram(5, 5);
  Nonogram n3 = Nonogram(10, 5);

  std::vector<cellVal> n1_front = n1.getFrontHalf();
  std::vector<cellVal> n2_front = n2.getFrontHalf();
  cross_nonograms(&n1, &n2);
  EXPECT_EQ(n1_front, n2.getFrontHalf());
  EXPECT_EQ(n2_front, n1.getFrontHalf());

  // Should fail. Different size nonograms.
  ASSERT_DEATH(cross_nonograms(&n1, &n3), "");
}