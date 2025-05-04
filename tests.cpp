// Yakirli45@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace mySquareMat;

TEST_CASE("Matrix creation and access") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    CHECK(m[0][0] == doctest::Approx(1));
    CHECK(m[1][1] == doctest::Approx(4));
}

TEST_CASE("Matrix addition and subtraction") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    SquareMat c = a + b;
    CHECK(c[0][0] == doctest::Approx(6));
    CHECK(c[1][1] == doctest::Approx(12));

    SquareMat d = b - a;
    CHECK(d[0][0] == doctest::Approx(4));
    CHECK(d[1][1] == doctest::Approx(4));
}

TEST_CASE("Matrix scalar multiplication and division") {
    SquareMat m(2);
    m[0][0] = 2; m[0][1] = 4;
    m[1][0] = 6; m[1][1] = 8;

    SquareMat m2 = m * 0.5;
    CHECK(m2[0][0] == doctest::Approx(1.0));
    CHECK(m2[1][1] == doctest::Approx(4.0));

    m /= 2;
    CHECK(m[0][0] == doctest::Approx(1.0));
    CHECK(m[1][1] == doctest::Approx(4.0));
}

TEST_CASE("Matrix transpose and determinant") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    SquareMat t = ~m;
    CHECK(t[0][1] == doctest::Approx(3));
    CHECK(t[1][0] == doctest::Approx(2));

    CHECK((!m) == doctest::Approx(-2)); // det = 1*4 - 2*3 = -2
}

TEST_CASE("Matrix equality and comparison") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 4; b[0][1] = 3;
    b[1][0] = 2; b[1][1] = 1;

    CHECK(a == b); // both sums = 10
    CHECK(!(a != b));
    CHECK(!(a < b));
    CHECK(!(a > b));
    CHECK(a <= b);
    CHECK(a >= b);
}
TEST_CASE("Matrix increment and decrement") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    SquareMat pre = ++m;
    CHECK(pre[0][0] == doctest::Approx(2));
    CHECK(m[1][1] == doctest::Approx(5));

    SquareMat post = m++;
    CHECK(post[0][0] == doctest::Approx(2));
    CHECK(m[0][0] == doctest::Approx(3));

    SquareMat preDec = --m;
    CHECK(preDec[0][0] == doctest::Approx(2));

    SquareMat postDec = m--;
    CHECK(postDec[0][0] == doctest::Approx(2));
    CHECK(m[0][0] == doctest::Approx(1));
}

TEST_CASE("Matrix modulo with scalar and multiplaction element-wise") {
    SquareMat m(2), b(2);
    m[0][0] = 10; m[0][1] = 9;
    m[1][0] = 8; m[1][1] = 7;

    b[0][0] = 4; b[0][1] = 5;
    b[1][0] = 3; b[1][1] = 2;

    SquareMat modScalar = m % 3;
    CHECK(modScalar[0][0] == doctest::Approx(1)); // 10 % 3 = 1
    CHECK(modScalar[1][1] == doctest::Approx(1)); // 7 % 3 = 1

    SquareMat modElem = m % b;
    CHECK(modElem[0][0] == doctest::Approx(40)); // 10 * 4 = 40
    CHECK(modElem[1][0] == doctest::Approx(24)); // 8 * 3 = 24
}

TEST_CASE("Matrix exponentiation") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    SquareMat m2 = m ^ 2;
    CHECK(m2[0][0] == doctest::Approx(7));
    CHECK(m2[1][1] == doctest::Approx(22));
}
TEST_CASE("Error handling for invalid matrix operations") {
    // Try to create a matrix with invalid size
    CHECK_THROWS(SquareMat(-1));
    CHECK_THROWS(SquareMat(0));

    // Size mismatch for binary operations
    SquareMat a(2), b(3);
    CHECK_THROWS(a + b);
    CHECK_THROWS(a - b);
    CHECK_THROWS(a * b);
    CHECK_THROWS(a % b);
    CHECK_THROWS(a += b);
    CHECK_THROWS(a -= b);
    CHECK_THROWS(a *= b);
    CHECK_THROWS(a %= b);

    // Modulo by zero (scalar)
    SquareMat m(2);
    m[0][0] = 5; m[0][1] = 7;
    m[1][0] = 9; m[1][1] = 11;
    CHECK_THROWS(m % 0);
    CHECK_THROWS(m %= 0);

    // Division by zero
    CHECK_THROWS(m / 0);
    CHECK_THROWS(m /= 0);

    // Out of bounds access
    CHECK_THROWS((void)m[-1][0]);
    CHECK_THROWS((void)m[0][-1]);
    CHECK_THROWS((void)m[2][0]);
    CHECK_THROWS((void)m[0][2]);
    }