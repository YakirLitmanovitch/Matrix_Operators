#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept> 
#include <cmath>




namespace mySquareMat {

    SquareMat::SquareMat(int matSize) : size(matSize) { // Constructor
        // Initialize the matrix with the given size
        // Allocate memory for the matrix
        if (matSize <= 0) {
            throw std::invalid_argument("Size must be positive");
        }
        mat = new double*[size];
        for (int i = 0; i < size; ++i) {
            mat[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                mat[i][j] = 0.0; // Initialize to zero
            }
        }
    }
    SquareMat::~SquareMat() { // Destructor
        // Deallocate memory for the matrix
        for (int i = 0; i < size; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }
    SquareMat::SquareMat(const SquareMat& other) : size(other.size) { // Copy constructor
        // Allocate memory for the new matrix
        mat = new double*[size];
        for (int i = 0; i < size; ++i) {
            mat[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
    
    double SquareMat::sumElements() const { // Helper function to sum elements of the matrix
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sum += mat[i][j];
            }
        }
        return sum;
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) { // Assignment operator
        if (this != &other) { // Avoid self-assignment

            for (int i = 0; i < size; ++i) { // Deallocate old memory
                delete[] mat[i];
            }
            delete[] mat;

            size = other.size; 
            mat = new double*[size]; 
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator+(const SquareMat& other) const { // Addition operator
        if (size != other.size) {
            throw std::invalid_argument("Matrices must be of the same size for addition");
        }
        // Create a new matrix to store the result
        SquareMat result(size); 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
    
    SquareMat SquareMat::operator-(const SquareMat& other) const { // Subtraction operator
        if (size != other.size) {
            throw std::invalid_argument("Matrices must be of the same size for subtraction");
        }
        // Create a new matrix to store the result
        SquareMat result(size); 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }
    
    SquareMat SquareMat::operator-() const { // Negation operator
        // Create a new matrix to store the result
        SquareMat result(size); 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = -mat[i][j];
            }
        }
        return result;
    }
    
    SquareMat SquareMat::operator*(const SquareMat& other) const { // Multiplication operator
        if (size != other.size) {
            throw std::invalid_argument("The matrices must be of the same size for multiplication");
        }
        // Create a new matrix to store the result
        SquareMat result(size); 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = 0.0;
                for (int k = 0; k < size; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
    
    SquareMat SquareMat::operator*(double scalar) const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] * scalar;
            }
        }
        return result;
    }
    
    SquareMat operator*(double scalar, const SquareMat& mat) { // Scalar multiplication operator
        return mat * scalar; // Reuse the existing operator*
    }
    
    RowProxy SquareMat::operator[](int i) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return RowProxy(mat[i], size);
    }
    
    const RowProxy SquareMat::operator[](int i) const {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return RowProxy(mat[i], size);
    }

    // double* SquareMat::operator[](int i) { // Index operator - write
    //     if (i < 0 || i >= size)
    //         throw std::out_of_range("Row index out of range");
    //     return mat[i]; 
    // }
    
    // const double* SquareMat::operator[](int i) const { // Index operator - read
    //     if (i < 0 || i >= size)
    //         throw std::out_of_range("Row index out of range");
    //     return mat[i];
    // }

    SquareMat SquareMat::operator%(const SquareMat& other) const {// Multiplication element-wise operator
        if (size != other.size) {
            throw std::invalid_argument("Cannot perform element-wise multiplication on matrices of different sizes.");
        }
    
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] * other.mat[i][j];
            }
        }
    
        return result;
    }
    
    SquareMat SquareMat::operator%(int scalar) const { // Scalar multiplication element-wise operator
        if (scalar == 0) {
            throw std::invalid_argument("Modulo by zero is not allowed.");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = static_cast<int>(mat[i][j]) % scalar;
            }
        }
        return result;
    }
    
    SquareMat SquareMat::operator/(int scalar) const { // Scalar division element-wise operator
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[i][j] = mat[i][j] / scalar;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator^(int power) const { // Power operator - using exponentiation by squaring
        if (power < 0) {
            throw std::invalid_argument("Matrix exponent must be non-negative.");
        }
    
        SquareMat result(size);
        SquareMat base(*this); 
    
        // Initialize result as the identity matrix
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.mat[i][j] = (i == j) ? 1.0 : 0.0;
    
        while (power > 0) {
            if (power % 2 == 1) {
                result = result * base; // Multiply result by base
            }
            base = base * base;
            power /= 2;
        }
    
        return result;
    }

    SquareMat& SquareMat::operator++() { // Pre increment operator - returns the incremented object
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] += 1;
        return *this; 
    }

    SquareMat SquareMat::operator++(int) { // Post increment operator - returns the old state
        SquareMat temp = *this; // Save the current state
        ++(*this);              // Increment the current object
        return temp;            // Return the old state
    }
    
    SquareMat& SquareMat::operator--() { // Pre decrement operator - returns the decremented object
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] -= 1;
        return *this;
    }

    SquareMat SquareMat::operator--(int) { // Post decrement operator - returns the old state
        SquareMat temp = *this; // Save the current state
        --(*this); // Decrement the current object
        return temp; // Return the old state
    }

    SquareMat SquareMat::operator~() const { // Transpose operator
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result; // Return the new transposed matrix
    }

    bool SquareMat::operator==(const SquareMat& other) const { // Equality operator
        return sumElements() == other.sumElements();

    }

    bool SquareMat::operator!=(const SquareMat& other) const { // Inequality operator
        return !(*this == other);
    }

    bool SquareMat::operator<(const SquareMat& other) const { // Less than operator
        return sumElements() < other.sumElements();
    }

    bool SquareMat::operator>(const SquareMat& other) const { // Greater than operator
        return sumElements() > other.sumElements();
    }

    bool SquareMat::operator<=(const SquareMat& other) const { // Less than or equal to operator
        return sumElements() <= other.sumElements();
    }

    bool SquareMat::operator>=(const SquareMat& other) const { // Greater than or equal to operator
        return sumElements() >= other.sumElements();
    }
    
    double SquareMat::operator!() const { // Determinant operator - calculates the determinant by recursion minor
        if (size == 1) { // Case for 1x1 matrix
            return mat[0][0];
        }
        if (size == 2) { // Case for 2x2 matrix
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }
    
        double det = 0.0; // Initialize determinant
        int sign = 1; // Cofactor sign
    
        for (int col = 0; col < size; ++col) {
            // Create a minor matrix by excluding the first row and the current column
            SquareMat minor(size - 1);
    
            for (int i = 1; i < size; ++i) {
                int minorCol = 0;
                for (int j = 0; j < size; ++j) {
                    if (j == col) continue;
                    minor.mat[i-1][minorCol] = mat[i][j];
                    ++minorCol;
                }
            }
    
            // Calculate the determinant of the minor matrix
            det += sign * mat[0][col] * !minor;
            sign = -sign; // Alternate sign for cofactor expansion
        }
    
        return det;
    }
    
    SquareMat& SquareMat::operator+=(const SquareMat& other) { // Addition assignment operator
        if (size != other.size) {
            throw std::invalid_argument("Matrices must be of the same size for addition.");
        }
    
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] += other.mat[i][j];
    
        return *this;
    }

    SquareMat& SquareMat::operator-=(const SquareMat& other) { // Subtraction assignment operator
        if (size != other.size) {
            throw std::invalid_argument("Matrices must be of the same size for subtraction.");
        }
    
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] -= other.mat[i][j];
    
        return *this;
    }

    SquareMat& SquareMat::operator*=(double scalar) { // Scalar multiplication assignment operator
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] *= scalar;
    
        return *this;
    }

    SquareMat& SquareMat::operator*=(const SquareMat& other) { // Matrix multiplication assignment operator
        if (size != other.size) {
            throw std::invalid_argument("Matrices must be of the same size for element-wise multiplication.");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] *= other.mat[i][j];
    
        return *this;
    }

    SquareMat& SquareMat::operator/=(double scalar) { // Scalar division assignment operator
        if (scalar == 0.0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
    
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] /= scalar;
    
        return *this;
    }

    SquareMat& SquareMat::operator%=(int scalar) { // Scalar modulu element-wise assignment operator
        if (scalar == 0) {
            throw std::invalid_argument("Modulo by zero is not allowed.");
        }
    
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                mat[i][j] = static_cast<int>(mat[i][j]) % scalar;
    
        return *this;
    }
    
    SquareMat& SquareMat::operator%=(const SquareMat& other) { // Mat modulu element-wise assignment operator
        if (size != other.size) {
            throw std::invalid_argument("Matrices must be of the same size for element-wise modulo.");
        }
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                int a = static_cast<int>(mat[i][j]);
                int b = static_cast<int>(other.mat[i][j]);
                if (b == 0) {
                    throw std::invalid_argument("Modulo by zero element is not allowed.");
                }
                mat[i][j] = a % b;
            }
    
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const SquareMat& m) { // Output operator
        for (int i = 0; i < m.size; ++i) {
            for (int j = 0; j < m.size; ++j) {
                os << m.mat[i][j];
                if (j < m.size - 1) os << " ";
            }
            os << "\n";
        }
        return os;
    

    }
}