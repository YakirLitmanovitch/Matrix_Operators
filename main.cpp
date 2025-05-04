#include <iostream>
#include "SquareMat.hpp"

using namespace mySquareMat;

int main() {
    //create two 2x2 matrices
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    std::cout << "Matrix a:\n" << a;
    std::cout << "Matrix b:\n" << b;

    // addition and subtraction
    std::cout << "a + b:\n" << (a + b);
    std::cout << "b - a:\n" << (b - a);

    // normal multiplication
    std::cout << "a * b:\n" << (a * b);

    // scalar multiplication
    std::cout << "a * 2.0:\n" << (a * 2.0);
    std::cout << "2.0 * a:\n" << (2.0 * a);

    // element-wise multiplication
    std::cout << "a % b (element-wise):\n" << (a % b);

    // mudolo by scalar
    std::cout << "a % 3:\n" << (a % 3);

    // devision by scalar
    std::cout << "a / 2:\n" << (a / 2.0);

    // power
    std::cout << "a ^ 2:\n" << (a ^ 2);

    std::cout << "Before increment:\n" << a;

    // Pre-increment: 
    std::cout << "++a (pre-increment):\n" << ++a;

    // Post-increment: 
    std::cout << "a++ (post-increment):\n" << a++;
    std::cout << "After a++ (value of a now):\n" << a;

    std::cout << "Before decrement:\n" << a;

    // Pre-decrement: 
    std::cout << "--a (pre-decrement):\n" << --a;

    // Post-decrement: 
    std::cout << "a-- (post-decrement):\n" << a--;
    std::cout << "After a-- (value of a now):\n" << a;

    // transpose
    std::cout << "Transpose of a:\n" << ~a;

    // implementation by []
    a[0][0] = 42;
    std::cout << "a after a[0][0] = 42:\n" << a;

    // comparison operators
    std::cout << "a == b? " << (a == b ? "Yes" : "No") << "\n";
    std::cout << "a > b? " << (a > b ? "Yes" : "No") << "\n";

    // determinant
    std::cout << "Determinant of a (!a): " << !a << "\n";

    // compound assignment operators
    a += b;
    std::cout << "a += b:\n" << a;

    a -= b;
    std::cout << "a -= b:\n" << a;

    a *= 2.0;
    std::cout << "a *= 2:\n" << a;

    a *= b;
    std::cout << "a *= b (element-wise):\n" << a;

    a /= 2.0;
    std::cout << "a /= 2:\n" << a;

    a %= 5;
    std::cout << "a %= 5:\n" << a;

    a %= b;
    std::cout << "a %= b (element-wise):\n" << a;

    return 0;
}