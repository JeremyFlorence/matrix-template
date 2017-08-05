// File: rational.h
/*
 * Name: Jeremy Florence
 * Course: CIS 280
 * Assignment: 3
 * Date: 3/14/17
*/

#include <iostream>

using namespace std;

/*
 * The Rational class defines a rational number. A Rational number consists
 * of a numerator and denominator. Various operations can be performed on
 * Rational objects such as add, sub, mul, div, neg, and less. Rational
 * objects can also be accepted as output and input using cout and cin as 
 * usual.
*/
class Rational {
    private:
        int numerator;			// Represents the numerator
        int denominator;		// Represents the denominator
        void reduce();			// Reduces the Rational to it's simplest form
        int gcd(int, int);		// Finds the gcd of two ints
    public:
        // Default constructor:
        // Initializes to 0/1
		Rational();	
		
		// Constructor:
		// Initializes to n/1
        Rational(int);
		
		//Constructor:
		// Initializes to n/d
        Rational(int, int);
		
		// Returns -r
	    friend Rational neg(const Rational& r);
		
		// Returns the Rational representation of r1+r2
		friend Rational add(const Rational& r1, const Rational& r2);
        
		// Returns the Rational representation of r1-r2
		friend Rational sub(const Rational& r1, const Rational& r2);
		
		// Returns the Rational representation of r1*r2
        friend Rational mul(const Rational& r1, const Rational& r2);
		
		// Returns the Rational representation of r1/r2
        friend Rational div(const Rational& r1, const Rational& r2);
		
		// Returns 1 if r1 < r2; 0 otherwise
        friend bool lessthan(const Rational& r1, const Rational& r2);

		Rational operator+(const Rational&);
		Rational operator*(const Rational&);
		Rational operator-(const Rational&);
		Rational operator/(const Rational&);
		const bool operator<(const Rational&);
		const bool operator<=(const Rational&);
		const bool operator>(const Rational&);
		const bool operator>=(const Rational&);
		const bool operator==(const Rational&);
		
		// Allows r to be accepted as output
        friend ostream& operator << (ostream&, const Rational& r);
		
		// Allows r to be accepted as input
		friend istream& operator >> (istream&, Rational& r);

};