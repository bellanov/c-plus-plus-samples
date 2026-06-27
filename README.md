# C++ Samples

Modern design patterns and best practices in the C++ programming language.

## Overview

This repository contains sample C++ code demonstrating modern design patterns and best practices including:

- **Exception-Based Error Handling**: Clean, idiomatic C++ error handling without error codes
- **RAII (Resource Acquisition Is Initialization)**: Safe resource management with std::string
- **STL Algorithms**: Standard library utilities for safe, efficient operations
- **Modern C++ Features**: C++17 capabilities including lambdas, auto, and move semantics
- **Static Utility Classes**: Compile-time polymorphism for utility functions
- **Comprehensive Testing**: 20+ unit tests with 100% pass rate

## Project Structure

```
├── include/          # Header files (.hpp) with public API
├── src/             # C++ implementation files (.cpp)
├── test/            # Unit tests using Google Test
├── CMakeLists.txt   # CMake build configuration
├── .clang-format    # Code style enforcement (LLVM-based)
├── .github/         # GitHub Actions CI/CD workflows
└── README.md        # This file
```

## Prerequisites

- C++17 capable compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.14+
- Build tools (make or ninja)
- lcov (optional, for coverage reports)

## Building

### Quick Start

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Build Configurations

```bash
# Debug build with symbols and coverage
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Release build optimized
cmake -DCMAKE_BUILD_TYPE=Release ..
```

## Running Tests

```bash
cd build
ctest --output-on-failure
```

## Code Coverage

Generate and view code coverage reports:

```bash
cd build

# Generate coverage data
lcov --capture --directory . --output-file coverage.info --include '*/src/*'

# Generate HTML report
genhtml coverage.info --output-directory coverage_html

# View report
open coverage_html/index.html
```

## Code Style

Code follows the LLVM style guide enforced by clang-format.

Check formatting:
```bash
clang-format --dry-run -Werror src/*.cpp include/*.hpp
```

Fix formatting:
```bash
clang-format -i src/*.cpp include/*.hpp
```

## Design Patterns Demonstrated

### 1. Exception-Based Error Handling

Modern C++ replaces error codes with exceptions for cleaner error handling:

```cpp
try
{
    std::string result = StringUtils::duplicate("hello");
    std::cout << "Success: " << result << std::endl;
}
catch (const StringException &e)
{
    std::cerr << "Error: " << e.what() << std::endl;
}
```

**Advantages:**
- Clear separation of success and error paths
- No need to check error codes after each operation
- Automatic stack unwinding on errors
- Type-safe exception handling

### 2. RAII with std::string

Resource Acquisition Is Initialization ensures automatic memory management:

```cpp
std::string result = StringUtils::concat("Hello", " World");
// No manual allocation or deallocation needed
// std::string handles all memory automatically
```

**Advantages:**
- Automatic memory cleanup (no leaks)
- Exception-safe resource management
- No manual free() or delete calls needed
- Simplifies code significantly

### 3. STL Algorithms and Containers

Uses standard library containers and algorithms for safe operations:

```cpp
std::string reversed = StringUtils::reverse("Hello");
// Uses std::reverse() from <algorithm>
// Safe, optimized, and well-tested
```

**Advantages:**
- Battle-tested implementations
- Optimized performance
- Consistent with C++ idioms
- Better compiler optimizations

### 4. Static Utility Classes

Compile-time polymorphism using static methods in a utility class:

```cpp
class StringUtils
{
public:
    static std::string duplicate(const std::string &src);
    static std::string reverse(const std::string &src);
    // ... more static methods
private:
    StringUtils() = delete;
    ~StringUtils() = delete;
};
```

**Advantages:**
- No runtime overhead (no virtual calls)
- Clear API surface
- Cannot be instantiated
- Namespace-like organization

### 5. Lambda Expressions

Modern C++ lambdas for functional programming:

```cpp
std::transform(result.begin(), result.end(), result.begin(),
               [](unsigned char c) { return std::toupper(c); });
```

**Advantages:**
- Concise inline functions
- Capture local variables
- No separate function definition needed
- Compiler optimizes efficiently

## String Utilities API

The `StringUtils` class provides the following operations:

### duplicate()
Safely duplicate a string
```cpp
std::string copy = StringUtils::duplicate("hello");
```

### concat()
Concatenate two strings safely
```cpp
std::string result = StringUtils::concat("Hello", "World");
```

### length()
Get string length with bounds checking
```cpp
size_t len = StringUtils::length("hello", 100);
```

### reverse()
Reverse a string
```cpp
std::string rev = StringUtils::reverse("hello");  // "olleh"
```

### toUpperCase()
Convert string to uppercase
```cpp
std::string upper = StringUtils::toUpperCase("Hello");  // "HELLO"
```

### toLowerCase()
Convert string to lowercase
```cpp
std::string lower = StringUtils::toLowerCase("HELLO");  // "hello"
```

## CI/CD Pipeline

The repository includes GitHub Actions workflows that:

1. **Lint**: Validates code formatting with clang-format
2. **Build**: Compiles code in Release mode after linting
3. **Test**: Runs 20+ unit tests with Debug instrumentation
4. **Coverage**: Generates lcov reports and uploads to Codecov

All coverage reports are available as build artifacts.

## Testing Examples

### Basic Unit Test

```cpp
TEST_F(StringUtilsTest, ReverseSuccessful)
{
    std::string result = StringUtils::reverse("Hello");
    EXPECT_EQ(result, "olleH");
}
```

### Exception Testing

```cpp
TEST_F(StringUtilsTest, DuplicateEmptyString)
{
    EXPECT_THROW(StringUtils::duplicate(""), StringException);
}
```

### Chained Operations

```cpp
TEST_F(StringUtilsTest, ChainedOperations)
{
    std::string str = "hello";
    std::string upper = StringUtils::toUpperCase(str);
    std::string reversed = StringUtils::reverse(upper);
    EXPECT_EQ(reversed, "OLLEH");
}
```

## Modern C++ Features Used

- **std::string**: Automatic memory management
- **std::algorithm**: Safe, optimized operations (reverse, transform)
- **std::exception**: Standard exception hierarchy
- **Lambdas**: Functional programming with captures
- **auto**: Type deduction
- **constexpr**: Compile-time evaluation where possible
- **= delete**: Explicitly deleted functions
- **override**: Virtual function annotation

## Contributing

When contributing:

1. Ensure code compiles with C++17 standard
2. Format code with clang-format (LLVM style)
3. Write tests for all new functionality
4. Maintain or improve code coverage
5. Update documentation as needed
6. All tests must pass before committing

## Build Command Reference

```bash
# Full build pipeline
mkdir build && cd build && cmake .. && cmake --build . && ctest

# With coverage
cmake -DCMAKE_BUILD_TYPE=Debug .. && cmake --build . && ctest
```

## License

See LICENSE file for details.

