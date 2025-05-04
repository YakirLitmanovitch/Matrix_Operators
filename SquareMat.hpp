#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>

namespace mySquareMat {
    class RowProxy {
        private:
            double* row;
            int size;
        
        public:
            RowProxy(double* r, int s) : row(r), size(s) {}
        
            double& operator[](int j) {
                if (j < 0 || j >= size) {
                    throw std::out_of_range("Column index out of bounds");
                }
                return row[j];
            }
        
            const double& operator[](int j) const {
                if (j < 0 || j >= size) {
                    throw std::out_of_range("Column index out of bounds");
                }
                return row[j];
            }
        };
    class SquareMat {
        private:
            int size;
            double** mat;

            double sumElements() const; // Helper function to sum elements of the matrix
        public:
            SquareMat(int matSize); // Constructor
            ~SquareMat();
            SquareMat(const SquareMat& other); // Copy constructor

            SquareMat& operator=(const SquareMat& other); // Assignment operator
            SquareMat operator+(const SquareMat& other) const; // Addition operator
            SquareMat operator-(const SquareMat& other) const; // Subtraction operator
            SquareMat operator-() const; // Negation operator
            SquareMat operator*(const SquareMat& other) const; // Multiplication operator
            SquareMat operator*(double scalar) const; // Scalar multiplication operator
            friend SquareMat operator*(double scalar, const SquareMat& mat); // Scalar multiplication operator
            //double* operator[](int i); // Index operator - write
            //const double* operator[](int i) const; // Index operator - read
            RowProxy operator[](int i);
            const RowProxy operator[](int i) const;
            SquareMat operator%(const SquareMat& other) const; // Multiplication element-wise operator
            SquareMat operator%(int scalar) const; // Scalar multiplication element-wise operator
            SquareMat operator/(int scalar) const; // Scalar division element-wise operator
            SquareMat operator^(int power) const; // Power operator
            SquareMat& operator++(); // Pre increment operator
            SquareMat operator++(int); // Post increment operator
            SquareMat& operator--(); // Pre decrement operator
            SquareMat operator--(int); // Post decrement operator
            SquareMat operator~() const; // Transpose operator
            bool operator==(const SquareMat& other) const; // Equality operator
            bool operator!=(const SquareMat& other) const; // Inequality operator
            bool operator<(const SquareMat& other) const; // Less than operator
            bool operator>(const SquareMat& other) const; // Greater than operator
            bool operator<=(const SquareMat& other) const; // Less than or equal to operator
            bool operator>=(const SquareMat& other) const; // Greater than or equal to operator
            double operator!() const; // Determinant operator
            SquareMat& operator+=(const SquareMat& other); // Addition assignment operator
            SquareMat& operator-=(const SquareMat& other); // Subtraction assignment operator
            SquareMat& operator*=(double scalar); // Scalar multiplication assignment operator
            SquareMat& operator*=(const SquareMat& other); // Mat multiplication assignment operator
            SquareMat& operator/=(double scalar); // Scalar division assignment operator
            SquareMat& operator%=(int scalar); // Scalar modulu element-wise assignment operator
            SquareMat& operator%=(const SquareMat& other); // Mat modulu element-wise assignment operator
            friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat); // Output operator
            
    };
}
#endif 