#include <gtest/gtest.h>
#include "complex.h"
#include <iostream>
#include <math.h>
/*
int main() {
  Cartesian x1 = Cartesian();
  Cartesian x2 = Cartesian(1, 1);
  x1 -= x2;
  std::cout<<x1.getReal();
  std::cout<<" ";
  std::cout<<x1.getImagine();
  return 0;
}*/


TEST(CartesianTest, ConstructorTest) {
  Cartesian x1 = Cartesian();
  Cartesian x2 = Cartesian(1, 1);
  EXPECT_EQ(x1, Cartesian(0, 0));
  EXPECT_EQ(x2, Cartesian(1, 1));
}

TEST(CartesianTest, plusIsTest) {
  Cartesian x1 = Cartesian();
  Cartesian x2 = Cartesian(1, 1);
  EXPECT_EQ(x1 += x2, Cartesian(1, 1));
  EXPECT_EQ(x2 += x1, Cartesian(1, 1));
}

TEST(CartesianTest, minusIsTest) {
  Cartesian x1 = Cartesian();
  Cartesian x2 = Cartesian(1, 1);
  EXPECT_EQ(x1-=x2, Cartesian(-1, -1));
  EXPECT_EQ(x2-=x1, Cartesian(1, 1));
}

TEST(CartesianTest, multiplicationIsTest) {
  Cartesian x1 = Cartesian(1, 2);
  Cartesian x2 = Cartesian(3, 4);
  EXPECT_EQ(x1 *= x2, Cartesian(-5, 10));
  EXPECT_EQ(x2 *= x1, Cartesian(-5, 10));
}

TEST(CartesianTest, divIsTest) {
  Cartesian x1 = Cartesian(8, 12);
  Cartesian x2 = Cartesian(4, 6);
  EXPECT_EQ(x1 /= x2, Cartesian(2, 0));
}

TEST(CartesianTest, absTest) {
  Cartesian x1 = Cartesian(4, 3);
  EXPECT_EQ(x1.abs(), Cartesian(5, 0));
}

TEST(CartesianTest, argTest) {
  Cartesian x1 = Cartesian(4, 1);
  Cartesian x2 = Cartesian(8, 2);
  EXPECT_EQ(x1.arg(), x2.arg());
}

TEST(CartesianTest, getTest) {
  Cartesian x = Cartesian(2, 3);
  EXPECT_EQ(x.getReal(), 2);
  EXPECT_EQ(x.getImagine(), 3);
}

TEST(CartesianTest, setTest) {
  Cartesian x = Cartesian();
  x.setReal(2);
  x.setImagine(3);
  EXPECT_EQ(x, Cartesian(2, 3));
}

TEST(CartesianTest, powTest) {
  Cartesian x = Cartesian(0, 1);
  EXPECT_EQ(pow(x, 2), Cartesian(-1, 5.01655761266833202345e-20));
}

TEST(PolarTest, ConstructorTest) {
  Polar x1 = Polar();
  Polar x2 = Polar(1, 1);
  EXPECT_EQ(x1, Polar(0, 0));
  EXPECT_EQ(x2, Polar(1, 1));
}

TEST(PolarTest, plusIsTest) {
  Polar x1 = Polar(2, 3);
  Polar x2 = Polar(4, 5);
  EXPECT_EQ(x1 += x2, Polar(3.65262242987770661918, -1.80434642873943556335));
}

TEST(PolarTest, minusIsTest) {
  Polar x1 = Polar(4, 6);
  Polar x2 = Polar(2, 3);
  EXPECT_EQ(x1-=x2, Polar(5.98664179199049183589, -0.236022860519899068296));
}

TEST(PolarTest, multiplicationIsTest) {
  Polar x1 = Polar(2, 4);
  Polar x2 = Polar(3.3, 6.6);
  x1 *= x2;
  EXPECT_EQ(x1, Polar(6.59999999999999964473, -2.59999999999999964473));
}

TEST(PolarTest, divIsTest) {
  Polar x1 = Polar(8, 12);
  Polar x2 = Polar(4, 6);
  x1 /= x2;
  EXPECT_EQ(x1, Polar(1.64999999999999991118, -10.5999999999999996447));
}

TEST(PolarTest, getTest) {
  Polar x = Polar(2, 3);
  EXPECT_EQ(x.getRHO(), 2);
  EXPECT_EQ(x.getPHI(), 3);
}

TEST(PolarTest, setTest) {
  Polar x = Polar();
  x.setRHO(2);
  x.setPHI(3);
  EXPECT_EQ(x, Cartesian(2, 3));
}

TEST(PolarTest, powTest) {
  Polar x = Polar(4, M_PI_4);
  EXPECT_EQ(pow(x, 2), Polar(16, M_PI_2));
}