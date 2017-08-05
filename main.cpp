/*
 * CIS 280 C++ Project - Matrix Main
 * File: main.cpp
 * Names: Jeremy Florence, Christopher Tang
 * Date: 3/14/17
*/

//This is the matrix testing program...
#include <iostream>
#include "matrix.h"
#include "rational.h"

using namespace std;

// Allows the user to specify the individual values of a matrix
template<typename T>
Matrix<T> specify_values(Matrix<T> m);

int main() {

    Matrix<int> j(2, 2, 1), k(2, 4, 1), l(4, 2, 2), x(3, 3, 0);
    int y = 2, z = -2;

    cout << "Testing declarations." << endl;
    cout << "Matrix j 2 x 2: \n" << j << endl;
    cout << "Matrix k 2 x 4: \n" << k << endl;
    cout << "Matrix l 4 x 2: \n" << l << endl;
    cout << "Testing matrix \"x\" 3 x 3 with filled value 0: \n" << x << endl;

    cout << "Testing mathematical operations..." << endl;
    cout << "Adding matrix j to matrix j: \n" << j + j << endl;
    cout << "Multiplying matrix k to l: \n" << k * l << endl;
    cout << "Subtracting matrix j from matrix j: \n" << j - j << endl;
    cout << "Multiplying matrix j to matrix k : \n" << j * k << endl;
    cout << "Testing copy constructor..." << endl;
    cout << "Assigning k to j : \n" << (j = k) << endl;

    j = specify_values(j);
    cout << endl << "Printing matrix j: \n";
    cout << j << endl;
    Matrix<int> m(3, 3, 1);
    cout << "Printing matrix m: \n" << m << endl;


    cout << "Testing for operation exception handling..." << endl;
    cout << "Attempting to add j to m: " << endl;
    cout << j+m << endl;



    cout << "Attempting to subtract m from j: " << endl;
    cout << j-m << endl;



    cout << "Attempting to multiply j by m : " << endl;
    cout << j*m << endl;


    cout << "Testing scalar matrix operations on matrix j..." << endl;
    cout << "Matrix scalar addition on matrix j with scalar 2: \n" << j + y << endl;
    cout << "Matrix scalar addition on matrix j with scalar -2: \n" << j + z << endl;
    cout << "Matrix scalar subtraction on matrix j with scalar 2: \n" << j - y << endl;
    cout << "Matrix scalar subtraction on matrix j with scalar -2: \n" << j - z << endl;
    cout << "Matrix scalar multiplication on matrix j with scalar 2: \n" << j * y << endl;
    cout << "Matrix scalar multiplcation on matrix j with scalar -2: \n" << j * z << endl;
    cout << "Matrix scalar division on matrix j with scalar 2: \n" << j / y << endl;
    cout << "Matrix scalar division on matrix j with scalar -2: \n" << j / z << endl;

    cout << "Testing scalar matrix operations matrix k..." << endl;
    cout << "Matrix scalar addition on matrix k with scalar 2: \n" << k + y << endl;
    cout << "Matrix scalar addition on matrix k with scalar -2: \n" << k + z << endl;
    cout << "Matrix scalar subtraction on matrix k with scalar 2: \n" << k - y << endl;
    cout << "Matrix scalar subtraction on matrix k with scalar -2: \n" << k - z << endl;
    cout << "Matrix scalar multiplication on matrix k with scalar 2: \n" << k * y << endl;
    cout << "Matrix scalar multiplcation on matrix k with scalar -2: \n" << k * z << endl;
    cout << "Matrix scalar division on matrix k with scalar 2: \n" << k / y << endl;
    cout << "Matrix scalar division on matrix k with scalar -2: \n" << k / z << endl;

    cout << "Testing scalar matrix operations matrix l..." << endl;
    cout << "Matrix scalar addition on matrix l with scalar 2: \n" << l + y << endl;
    cout << "Matrix scalar addition on matrix l with scalar -2: \n" << l + z << endl;
    cout << "Matrix scalar subtraction on matrix l with scalar 2: \n" << l - y << endl;
    cout << "Matrix scalar subtraction on matrix l with scalar -2: \n" << l - z << endl;
    cout << "Matrix scalar multiplication on matrix l with scalar 2: \n" << l * y << endl;
    cout << "Matrix scalar multiplcation on matrix l with scalar -2: \n" << l * z << endl;
    cout << "Matrix scalar division on matrix l with scalar 2: \n" << l / y << endl;
    cout << "Matrix scalar division on matrix l with scalar -2: \n" << l / z << endl;

    cout << "Testing scalar matrix operations matrix x..." << endl;
    cout << "Matrix scalar addition on matrix x with scalar 2: \n" << x + y << endl;
    cout << "Matrix scalar addition on matrix x with scalar -2: \n" << x + z << endl;
    cout << "Matrix scalar subtraction on matrix x with scalar 2: \n" << x - y << endl;
    cout << "Matrix scalar subtraction on matrix x with scalar -2: \n" << x - z << endl;
    cout << "Matrix scalar multiplication on matrix x with scalar 2: \n" << x * y << endl;
    cout << "Matrix scalar multiplcation on matrix x with scalar -2: \n" << x * z << endl;
    cout << "Matrix scalar division on matrix x with scalar 2: \n" << x / y << endl;
    cout << "Matrix scalar division on matrix x with scalar -2: \n" << x / z << endl;

    cout << "Testing Matrix class with Rational Class..." << endl;
    Matrix<Rational> a(2, 2, 0);
    Matrix<Rational> b(2, 2, 0);
    cout << "Specifying values for Matrix a: " << endl;
    a = specify_values(a);
    cout << "Specifying values for Matrix b: " << endl;
    b = specify_values(b);
    cout << endl << "Printing Matrix a: " << endl;
    cout << a << endl << endl;
    cout << "Printing Matrix b: " << endl;
    cout << b << endl;
    cout << "Testing a*b : " << endl;
    cout << a*b << endl;

    return 0;
}

//Function for specifying the values inside the matrix
template<typename T>
Matrix<T> specify_values(Matrix<T> m) {
  int rows = m.numrows();
  int columns = m.numcols();
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++) {
      cout << "Please enter a value for index (" << i << ", " << j << "): " << endl;
      cin >> m(i,j);
    }
  }

  return m;
}
