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

TEST(NonogramTest, NonogramCrossTest) {
  srand(time(NULL));
  Nonogram n1 = Nonogram(5, 5);
  Nonogram n2 = Nonogram(5, 5);
  Nonogram n3 = Nonogram(10, 5);

  std::vector<cellVal> n1_front = n1.getFrontHalf();
  std::vector<cellVal> n2_front = n2.getFrontHalf();
  std::vector<cellVal> n1_back = n1.getBackHalf();
  std::vector<cellVal> n2_back = n2.getBackHalf();
  cross_nonograms(&n1, &n2);
  EXPECT_EQ(n1_front, n2.getFrontHalf());
  EXPECT_EQ(n2_front, n1.getFrontHalf());
  EXPECT_EQ(n1_back, n2.getBackHalf());
  EXPECT_EQ(n2_back, n1.getBackHalf());
  ASSERT_DEATH(cross_nonograms(&n1, &n3), "");
}