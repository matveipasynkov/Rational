#include <iostream>
#include <numeric>
#include "rational.h"

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(int x) : numerator_(x){}

Rational::Rational(int x, int y) : numerator_(x), denominator_(y) {
  if (y == 0) {
    throw RationalDivisionByZero{};
  }
  Reduce();
}

void Rational::Reduce() const {
  int divider = std::gcd(numerator_, denominator_);
  numerator_ /= divider;
  denominator_ /= divider;
  if (denominator_ < 0) {
    numerator_ = -numerator_;
    denominator_ = -denominator_;
  }
}

int Rational::GetNumerator() const {
  return numerator_;
}

int Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int value) {
  numerator_ = value;
  Reduce();
}

void Rational::SetDenominator(int value) {
  if (value == 0) {
    throw RationalDivisionByZero{};
  }
  denominator_ = value;
  Reduce();
}

Rational Rational::operator+(const Rational& other) const {
  int result_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  int result_denominator = denominator_ * other.denominator_;
  return {result_numerator, result_denominator};
}

Rational Rational::operator-(const Rational& other) const {
  int result_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  int result_denominator = denominator_ * other.denominator_;
  return {result_numerator, result_denominator};
}

Rational Rational::operator/(const Rational& other) const {
  int result_numerator = numerator_ * other.denominator_;
  int result_denominator = denominator_ * other.numerator_;
  if (result_denominator == 0) {
    throw RationalDivisionByZero{};
  }
  return {result_numerator, result_denominator};
}

Rational Rational::operator*(const Rational& other) const {
  return {numerator_ * other.numerator_, denominator_ * other.denominator_};
}

Rational& Rational::operator+=(const Rational& other) {
  numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
  denominator_ *= other.denominator_;
  Reduce();
  return *this;
}

Rational& Rational::operator-=(const Rational& other) {
  numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
  denominator_ *= other.denominator_;
  Reduce();
  return *this;
}

Rational& Rational::operator/=(const Rational& other) {
  numerator_ *= other.denominator_;
  denominator_ *= other.numerator_;
  if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  Reduce();
  return *this;
}

Rational& Rational::operator*=(const Rational& other) {
  numerator_ *= other.numerator_;
  denominator_ *= other.denominator_;
  Reduce();
  return *this;
}

Rational Rational::operator+() const {
  return {numerator_, denominator_};
}

Rational Rational::operator-() const {
  return {-numerator_, denominator_};
}

Rational Rational::operator++(int) {
  Rational old_rational{numerator_, denominator_};
  numerator_ += denominator_;
  Reduce();
  return old_rational;
}

Rational Rational::operator--(int) {
  Rational old_rational{numerator_, denominator_};
  numerator_ -= denominator_;
  Reduce();
  return old_rational;
}

Rational& Rational::operator--() {
  numerator_ -= denominator_;
  Reduce();
  return *this;
}

Rational& Rational::operator++() {
  numerator_ += denominator_;
  Reduce();
  return *this;
}

bool Rational::operator<(const Rational& other) const {
  return numerator_ * other.denominator_ < other.numerator_ * denominator_;
}

bool Rational::operator>(const Rational& other) const {
  return numerator_ * other.denominator_ > other.numerator_ * denominator_;
}

bool Rational::operator==(const Rational& other) const {
  return numerator_ * other.denominator_ == other.numerator_ * denominator_;
}

bool Rational::operator>=(const Rational& other) const {
  return *this > other || *this == other;
}

bool Rational::operator<=(const Rational& other) const {
  return *this < other || *this == other;
}

Rational operator+(const int& self, const Rational& other) {
  return other + self;
}

Rational operator-(const int& self, const Rational& other) {
  return -other + self;
}

Rational operator/(const int& self, const Rational& other) {
  Rational rational_self = self;
  return rational_self / other;
}

Rational operator*(const int& self, const Rational& other) {
  return other * self;
}

bool operator<(const int& self, const Rational& other) {
  return other > self;
}

bool operator<=(const int& self, const Rational& other) {
  return other >= self;
}

bool operator==(const int& self, const Rational& other) {
  Rational rational = self;
  return rational == other;
}

bool operator>(const int& self, const Rational& other) {
  return other < self;
}

bool operator>=(const int& self, const Rational& other) {
  return other <= self;
}

std::istream& operator>>(std::istream& is, Rational& self) {
  char slash = '/';
  int numerator = 0;
  int denominator = 1;
  is >> numerator;
  if (is.peek() == '/') {
    is >> slash;
    is >> denominator;
  } else {
    denominator = 1;
  }
  self = Rational{numerator, denominator};
  return is;
}

std::ostream& operator<<(std::ostream& os, const Rational& self) {
  if (self.denominator_ != 1) {
    os << self.numerator_ << '/' << self.denominator_;
  } else {
    os << self.numerator_;
  }
  return os;
}