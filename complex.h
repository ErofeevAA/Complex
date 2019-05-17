#include <zconf.h>
#define EPS 1e-9

class Polar;

class Cartesian {
 private:
  long double imagine;
  long double real;

 public:
  Cartesian();
  Cartesian(long double i, long double r);
  explicit Cartesian(const Polar &p);

  Cartesian &operator+=(const Cartesian &val);
  Cartesian &operator-=(const Cartesian &val);
  Cartesian &operator*=(const Cartesian &val);
  Cartesian &operator/=(const Cartesian &val);

  long double abs() const;
  long double arg() const;

  long double getReal() const;
  long double getImagine() const;

  void setReal(long double r);
  void setImagine(long double r);

  bool operator==(const Cartesian &val) const;

  friend Cartesian pow(const Cartesian &p, u_int32_t n);

  friend Cartesian operator+(const Cartesian &left, const Cartesian &right);
  friend Cartesian operator-(const Cartesian &left, const Cartesian &right);
  friend Cartesian operator*(const Cartesian &left, const Cartesian &right);
  friend Cartesian operator/(const Cartesian &left, const Cartesian &right);

  //friend bool operator==(const Cartesian &left, const Cartesian &right);
  //friend bool operator!=(const Cartesian &left, const Cartesian &right);
};

class Polar {
private:
  long double rho;
  long double phi;

 public:
  Polar();
  Polar(long double rho, long double phi);
  explicit Polar(const Cartesian &p);

  Polar &operator+=(const Polar &val);
  Polar &operator-=(const Polar &val);
  Polar &operator*=(const Polar &val);
  Polar &operator/=(const Polar &val);

  long double getRho() const;
  long double getPhi() const;

  void setRHO(long double r);
  void setPHI(long double p);

  bool operator==(const Polar &val) const;

  friend Polar pow(const Polar &x, u_int32_t y);

  friend Polar operator+(const Polar &left, const Polar &right);
  friend Polar operator-(const Polar &left, const Polar &right);
  friend Polar operator*(const Polar &left, const Polar &right);
  friend Polar operator/(const Polar &left, const Polar &right);

  //friend bool operator==(const Polar &left, const Polar &right);
  //friend bool operator!=(const Polar &left, const Polar &right);
};