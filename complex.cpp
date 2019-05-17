#include "complex.h"
#include <cmath>


Cartesian::Cartesian() {
  this->real = 0;
  this->imagine = 0;
}

Cartesian::Cartesian(long double r, long double i) {
  this->real = r;
  this->imagine = i;
}

Cartesian::Cartesian(const Polar &p) {
  this->real = p.getRHO() * cosl(p.getPHI());
  this->imagine = p.getRHO() * sinl(p.getPHI());
}

Cartesian &Cartesian::operator+=(const Cartesian &val) {
  //this->real += val.real;
  //this->imagine += val.imagine;
  *this = *this + val;
  return *this;
}

Cartesian &Cartesian::operator-=(const Cartesian &val) {
  //this->real -= val.real;
  //this->imagine -= val.imagine;
  *this = *this - val;
  return *this;
}

Cartesian &Cartesian::operator*=(const Cartesian &val) {
  *this = *this * val;
  return *this;
}

Cartesian &Cartesian::operator/=(const Cartesian &val) {
  *this = *this / val;
  return *this;
}

long double Cartesian::abs() const {
  return sqrtl(powl(this->real, 2) + powl(this->imagine, 2));
}

long double Cartesian::arg() const{
  return atan2l(imagine, real);
}

long double Cartesian::getReal() const{
  return this->real;
}

long double Cartesian::getImagine() const{
  return this->imagine;
}

void Cartesian::setReal(long double r) {
  this->real = r;
}

void Cartesian::setImagine(long double i) {
  this->imagine = i;
}

//bool Cartesian::operator==(const Cartesian &val) const {
//  return fabsl(this->real - val.real) < EPS && fabsl(this->imagine - val.imagine) < EPS;
//}

Cartesian pow(const Cartesian &p, u_int32_t n) {
  return Cartesian(pow(Polar(p), n));
}


Cartesian operator+(const Cartesian &left, const Cartesian &right) {
  return Cartesian(left.real + right.real, left.imagine + right.imagine);;
}

Cartesian operator-(const Cartesian &left, const Cartesian &right) {
  return Cartesian(left.real - right.real, left.imagine - right.imagine);;
}

Cartesian operator*(const Cartesian &left, const Cartesian &right) {
  long double r = left.real * right.real - left.imagine * right.imagine;
  long double i = left.real * right.imagine + left.imagine * right.real;
  return Cartesian(r, i);;
}

Cartesian operator/(const Cartesian &left, const Cartesian &right) {
  long double denominator = powl(left.real, 2) + powl(left.imagine, 2);
  long double r = left.real * right.real + left.imagine * right.imagine;
  r /= denominator;
  long double i = left.imagine * right.real - left.real * right.imagine;
  i /= denominator;
  return Cartesian(r, i);
}

/*bool operator==(const Cartesian &left, const Cartesian &right) {
  return (left.real == right.real) &&
      (left.imagine == right.imagine);
}

bool operator!=(const Cartesian &left, const Cartesian &right) {
  return !(left == right);
}*/

Polar::Polar() {
  this->rho = 0;
  this->phi = 0;
}

Polar::Polar(long double rho, long double phi) {
  this->rho = rho;
  this->phi = phi;
}

Polar::Polar(const Cartesian &c) {
  this->rho = c.abs();
  this->phi = c.arg();
}

Polar &Polar::operator+=(const Polar &val) {
  *this = *this + val;
  return *this;
}

Polar &Polar::operator-=(const Polar &val) {
  *this = *this - val;
  return *this;
}

Polar &Polar::operator*=(const Polar &val) {
  *this = *this * val;
  return *this;
}

Polar &Polar::operator/=(const Polar &val) {
  *this = *this / val;
  return *this;
}

long double Polar::getRHO() const {
  return this->rho;
}

long double Polar::getPHI() const {
  return this->phi;
}

void Polar::setRHO(long double r) {
  this->rho = r;
}

void Polar::setPHI(long double p) {
  this->phi = p;
}

Polar pow(const Polar &p, u_int32_t n) {
  return Polar(powl(p.getRHO(), n), p.getPHI() * n);
}

Polar operator+(const Polar &left, const Polar &right) {
  return Polar(Cartesian(left) + Cartesian(right));
}

Polar operator-(const Polar &left, const Polar &right) {
  return Polar(Cartesian(left) - Cartesian(right));
}

Polar operator*(const Polar &left, const Polar &right) {
  long double r = left.rho * right.rho;
  long double p = left.phi + right.phi;
  return Polar(r, p);
}

Polar operator/(const Polar &left, const Polar &right) {
  long double r = left.rho / right.rho;
  long double p = left.phi - right.phi;
  return Polar(r, p);
}

/*bool operator==(const Polar &left, const Polar &right) {
  return (left.rho == right.rho) &&
      (left.phi == right.phi);
}

bool operator!=(const Polar &left, const Polar &right) {
 return !(left == right);
}*/