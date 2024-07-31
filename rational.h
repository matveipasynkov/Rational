#ifndef RATIONAL_H
#define RATIONAL_H
#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
 private:
  int mutable numerator_ = 0;
  int mutable denominator_ = 1;
 public:
  Rational();
  Rational(int); // NOLINT
  Rational(int, int);
  void Reduce() const;
  int GetNumerator() const;
  int GetDenominator() const;
  void SetNumerator(int);
  void SetDenominator(int);
  Rational operator+(const Rational&) const;
  Rational operator-(const Rational&) const;
  Rational operator/(const Rational&) const;
  Rational operator*(const Rational&) const;
  Rational& operator+=(const Rational&);
  Rational& operator-=(const Rational&);
  Rational& operator/=(const Rational&);
  Rational& operator*=(const Rational&);
  Rational operator+() const;
  Rational operator-() const;
  Rational operator++(int);
  Rational operator--(int);
  Rational& operator++();
  Rational& operator--();
  bool operator>(const Rational&) const;
  bool operator>=(const Rational&) const;
  bool operator==(const Rational&) const;
  bool operator<(const Rational&) const;
  bool operator<=(const Rational&) const;
  friend std::istream& operator>>(std::istream&, Rational&);
  friend std::ostream& operator<<(std::ostream&, const Rational&);
};
Rational operator+(const int&, const Rational&);
Rational operator-(const int& self, const Rational& other) ;
Rational operator/(const int& self, const Rational& other);
Rational operator*(const int& self, const Rational& other);
bool operator<(const int& self, const Rational& other);
bool operator>(const int& self, const Rational& other);
bool operator<=(const int& self, const Rational& other);
bool operator>=(const int& self, const Rational& other);
bool operator==(const int& self, const Rational& other);
#endif //RATIONAL_H
