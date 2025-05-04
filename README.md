# SquareMat Project

## 📌 Overview
This project implements a `SquareMat` class in C++ to represent square matrices of real numbers. The goal is to demonstrate mastery of key object-oriented concepts in C++, including:

- Operator overloading
- Deep copy semantics (Rule of Three)
- Manual memory management (no use of STL containers)
- Input validation and exception handling
- Modular, testable design

All code strictly avoids using the C++ standard containers (e.g., `vector`, `stack`), relying instead on raw dynamic arrays.

---

## 🧱 Project Structure

| File | Purpose |
|------|---------|
| `SquareMat.hpp` | Header file defining the `SquareMat` class, its interface, and friend functions |
| `SquareMat.cpp` | Implementation of all class methods and overloaded operators |
| `main.cpp` | Demonstration of the class and all supported operators (for manual testing and illustration) |
| `tests.cpp` | Automated unit tests using the [doctest](https://github.com/doctest/doctest) framework |
| `Makefile` | Build system supporting compilation, test execution, and Valgrind memory analysis |

---

## 📦 Compilation and Execution

To build and run the project, use the following commands:

- **Run demonstration program**:
  ```bash
  make Main
  ```

- **Run unit tests**:
  ```bash
  make test
  ```

- **Check for memory leaks with Valgrind**:
  ```bash
  make valgrind
  ```

- **Clean compiled files**:
  ```bash
  make clean
  ```

---

## 🔍 Class Design: `SquareMat`

The `SquareMat` class manages a dynamically allocated 2D array (`double** mat`) and exposes a rich interface through operator overloading.

### Key operators implemented:
- `+`, `-`, unary `-` – Matrix addition, subtraction, and negation
- `*` – Matrix multiplication and scalar multiplication (both left and right)
- `/`, `%` – Scalar division and modulo
- `%` (matrix-to-matrix) – Element-wise multiplication
- `^` – Matrix exponentiation (by integer powers)
- `++`, `--` – Pre/post increment and decrement (element-wise)
- `~` – Transpose
- `[]` – Two-level index operator (`mat[i][j]`) with bounds checking using a proxy object
- `==`, `!=`, `<`, `>`, `<=`, `>=` – Comparison by sum of elements
- `!` – Determinant computation
- `+=`, `-=`, `*=`, `/=`, `%=` – Compound assignment versions

### Rule of Three:
The class correctly implements:
- Destructor
- Copy constructor
- Copy assignment operator

This ensures deep copy behavior and prevents memory leaks.

---

## 🧪 Testing

Unit tests are written in `tests.cpp` using the [doctest](https://github.com/doctest/doctest) library. They cover:

- Arithmetic operations
- Transpose and determinant
- Comparisons
- Indexing
- Error handling (e.g., mismatched sizes, out-of-bounds access)

Run tests using:

```bash
make test
```

---

## 🧠 Memory Safety

All dynamic memory is allocated and released manually using `new[]` and `delete[]`. Memory management has been verified with:

```bash
make valgrind
```

Valgrind confirms **zero memory leaks** and **no invalid memory accesses**.

---

## 📎 Notes

- Namespace used: `mySquareMat`
- Floating point comparisons in tests use `doctest::Approx`
- The `[]` operator is enhanced using a `RowProxy` wrapper to allow bounds-checked `mat[i][j]` access

---

## 📞 Contact

For questions or feedback, please contact the project developer.
