#include <gtest/gtest.h>
#include "complex.h"
#include <math.h>


TEST(CartesianTest, ConstructorTest) {
  Cartesian x1, x2(1, 1);
  EXPECT_EQ(x1, Cartesian(0, 0));
  EXPECT_EQ(x2, Cartesian(1, 1));
}

TEST(CartesianTest, plusIsTest) {
  Cartesian x1, x2(1, 1);
  x1 += x2;
  EXPECT_EQ(x1, Cartesian(1, 1));
}


TEST(CartesianTest, minusIsTest) {
  Cartesian x1, x2(1, 1);
  x1 -= x2;
  EXPECT_EQ(x1, Cartesian(-1, -1));
}

TEST(CartesianTest, multiplicationIsTest) {
  Cartesian x1(1, 2), x2(3, 4);
  x1 *= x2;
  EXPECT_EQ(x1, Cartesian(-5, 10));
}

TEST(CartesianTest, divIsTest) {
  Cartesian x1(6, 12), x2(3, 6);
  x1 /= x2;
  EXPECT_EQ(x1, Cartesian(2, 0));
}

TEST(CartesianTest, absTest) {
  Cartesian x1(4, 3);
  EXPECT_EQ(x1.abs(), 5.0);
}

TEST(CartesianTest, argTest) {
  Cartesian x1(4, 1), x2(8, 2);
  EXPECT_EQ(x1.arg(), x2.arg());
}

TEST(CartesianTest, getTest) {
  Cartesian x(2, 3);
  EXPECT_EQ(x.getReal(), 2.0);
  EXPECT_EQ(x.getImagine(), 3.0);
}

TEST(CartesianTest, setTest) {
  Cartesian x;
  x.setReal(2);
  x.setImagine(3);
  EXPECT_EQ(x, Cartesian(2, 3));
}

TEST(CartesianTest, powTest) {
  Cartesian x(0, 1);
  EXPECT_EQ(pow(x, 2), Cartesian(-1, 5.01655761266833202345e-20));
}

TEST(PolarTest, ConstructorTest) {
  Polar x1, x2(1, 1);
  EXPECT_EQ(x1, Polar(0, 0));
  EXPECT_EQ(x2, Polar(1, 1));
}

TEST(PolarTest, plusIsTest) {
  Polar x1(2, 3), x2(4, 5);
  x1 += x2;
  EXPECT_EQ(x1, Polar(3.65262242987770661918, -1.80434642873943556335));
}

TEST(PolarTest, minusIsTest) {
  Polar x1(4, 6), x2(2, 3);
  x1 -= x2;
  EXPECT_EQ(x1, Polar(5.98664179199049183589, -0.236022860519899068296));
}

TEST(PolarTest, multiplicationIsTest) {
  Polar x1(2, 4), x2(3.3, -6.6);
  x1 *= x2;
  EXPECT_EQ(x1, Polar(6.59999999999999964473, -2.59999999999999964473));
}

TEST(PolarTest, divIsTest) {
  Polar x1(2, 4), x2(3.3, -6.6);
  x2 /= x1;
  EXPECT_EQ(x2, Polar(1.64999999999999991118, -10.5999999999999996447));
}

TEST(PolarTest, getTest) {
  Polar x(2, 3);
  EXPECT_EQ(x.getRho(), 2.0);
  EXPECT_EQ(x.getPhi(), 3.0);
}

TEST(PolarTest, setTest) {
  Polar x;
  x.setRHO(2);
  x.setPHI(3);
  EXPECT_EQ(x, Polar(2, 3));
}

TEST(PolarTest, powTest) {
  Polar x(4, M_PI_4);
  EXPECT_EQ(pow(x, 2), Polar(16, M_PI_2));
}