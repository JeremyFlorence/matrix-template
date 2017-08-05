//File: rational.cpp
/*
 * Name: Jeremy Florence
 * Course: CIS 280
 * Assignment: 3
 * Date: 3/14/17
*/

#include <cmath>
#include "rational.h"

// Constructors

// Default Constructor:
// Initializes a new instance of the Rational object as 0/1
Rational::Rational()  {
    numerator = 0;
    denominator = 1;
}

// Constructor for a single int:
// Initializes a new instance of the Rational object as n/1
Rational::Rational(int n) {
    this->numerator = n;
    this->denominator = 1;
}

// Constructor for two ints:
// Initializes a new instance of the Rational object as n/d
Rational::Rational(int n, int d) {
    this->numerator = n;
    this->denominator = d;
    reduce();
}

Rational Rational::operator+(const Rational& other) {
    return add(*this, other);
}

Rational Rational::operator-(const Rational& other) {
    return sub(*this, other);
}

Rational Rational::operator*(const Rational& other) {
    return mul(*this, other);
}

Rational Rational::operator/(const Rational& other) {
    return div(*this, other);
}

const bool Rational::operator==(const Rational& other) {
    return ((this->numerator)*(other.denominator) == (this->denominator)*(other.numerator));
}

const bool Rational::operator<(const Rational& other) {
    return lessthan(*this, other);
}

const bool Rational::operator<=(const Rational& other) {
    return ((*this<other) || (*this==other));
}

const bool Rational::operator>(const Rational& other) {
    return !(*this<=other);
}

const bool Rational::operator>=(const Rational& other) {
    return !(*this<other);
}

// friend function:
// Takes two Rational objects and returns their sum as another Rational
Rational add(const Rational& r1, const Rational& r2) {
    int num = r1.numerator*r2.denominator + r1.denominator*r2.numerator;
    int denom = abs(r1.denominator*r2.denominator);

    return Rational(num, denom);
}

// friend function:
// Takes two Rational objects and returns their difference as another Rational
Rational sub(const Rational& r1, const Rational& r2) {
    int num = r1.numerator*r2.denominator - r1.denominator*r2.numerator;
    int denom = abs(r1.denominator*r2.denominator);

    return Rational(num, denom);
}

// friend function:
// Takes two Rational objects and returns their product as another Rational
Rational mul(const Rational& r1, const Rational& r2) {
	int num = r1.numerator*r2.numerator;
	int denom = r1.denominator*r2.denominator;
	
	return Rational(num, denom);
}

// friend function:
// Takes two Rational objects and returns their quotient as another Rational
Rational div(const Rational& r1, const Rational& r2) {
	Rational recip(r2.denominator, r2.numerator);
	
	return mul(r1, recip);
}

// friend function:
// Takes a Rational object and returns it's negation as another Rational
Rational neg(const Rational& r) {
	return Rational(-1*r.numerator, r.denominator);
}

// friend function:
// Takes two Rational objects and compares their values:
// returns 1 if r1 < r2, else returns 0
bool lessthan(const Rational& r1, const Rational& r2) {
	return ((r1.numerator*r2.denominator) < (r1.denominator*r2.numerator));
}

// Mutator:
// Reduces this Rational to it's 'smallest' equivalent form
void Rational::reduce() {
    bool negative = numerator*denominator < 0;
    int n = abs(numerator);
    int d = abs(denominator);
    int divisor = gcd(n,d);
    n /= divisor;
    d /= divisor;

    if (negative)
        n *= -1;
    
    this->numerator = n;
    this->denominator = d;
}

// Helper:
// Euclidean divison algorithm
// Returns gcd of two ints
int Rational::gcd(int n, int d) {
    return(d != 0 ? gcd(d, n % d) : n);
}

// Overloads the << operater to output Rational objects
ostream& operator << (ostream& out, const Rational& r){
	return out << r.numerator << "/" << r.denominator;
}

// Overloads the << operator to accept Rational objects as input
istream& operator >> (istream& in, Rational& r) {
	char temp;
	return in >> r.numerator >> temp >> r.denominator;
}