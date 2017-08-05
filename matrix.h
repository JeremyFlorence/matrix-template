/*
 * CIS 280 C++ Project - Matrix Class
 * File: matrix.h
 * Names: Jeremy Florence, Christopher Tang
 * Date: 3/14/17
*/

/*The matrix template class allows you to construct a matrix object with a filler value of any type.
This class allows you to perform matrix arithmetic on the matrices, including matrix-matrix
addition, multiplication, subtraction as well as the scalar matrix addition, multiplication,
subtraction, and division operations.
The << operator is overloaded to display the matrix.
There are accessors for the matrix template to allow you to access specific elements in the matrix,
using the notation m(unsigned int i, unsigned int j) where m is a matrix, this allows you to access
the value at i, j.
The accessors numrows() and numcols() return how many rows and how many columns the matrix is made of.*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T> class Matrix {
    private:
        vector<vector<T> > matrix;  // 2D vector representing matrix
        unsigned int rows;  // stores the number of rows
        unsigned int columns;   //stores the number of columns

    public:
        // --------------------Constructors--------------------

        // Filler - Initializes by filling the entire matrix with the same value
        Matrix(unsigned int _rows, unsigned int _columns, const T& _filler);

        // Copy Constructor
        Matrix(const Matrix<T>& other);

        // Destructor
        virtual ~Matrix();



        // -------------Matrix/Matrix Arithmetic---------------

        Matrix<T> operator+(const Matrix<T>& other);
        Matrix<T> operator-(const Matrix<T>& other);
        Matrix<T> operator*(const Matrix<T>& other);
        Matrix<T>& operator=(const Matrix<T>& other);

        // -------------Matrix/Scalar Arithmetic---------------
        Matrix<T> operator+(const T& scalar);
        Matrix<T> operator-(const T& scalar);
        Matrix<T> operator*(const T& scalar);
        Matrix<T> operator/(const T& scalar);

        // --------------Misc. Matrix Operations---------------

        // Returns the transpose of a Matrix, work in progress
        //Matrix<T> transpose();

        // Allows a matrix to be printed as output
        template<typename U>
        friend ostream& operator<<(ostream& out, const Matrix<U>& m);

        // ----------------------Accessors---------------------

        // Access to individual elements
        T& operator()(const unsigned int& row, const unsigned int& column);

        // Access to individual elements (constant)
        const T& operator()(const unsigned int& row, const unsigned int& column) const;

        // gets the number of rows
        unsigned int numrows() const;

        // gets the number ofcolumns
        unsigned int numcols() const;


};

#include "matrix.cpp"

#endif
