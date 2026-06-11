# C Samples

Modern design patterns and best practices in the C programming language.

## Overview

This repository contains sample C code demonstrating modern design patterns including:

- **Modular Architecture**: Well-organized code structure with clear separation of concerns
- **Error Handling**: Comprehensive error codes and result structures for safe operations
- **Memory Management**: Explicit allocation and cleanup patterns
- **Type Safety**: Strong typing with enums for error codes
- **Testing**: Comprehensive unit tests with code coverage reporting

## Project Structure

```
├── include/          # Header files with public API
├── src/             # C source implementation files
├── test/            # Unit tests (C++ using Google Test)
├── cmake/           # CMake configuration
├── CMakeLists.txt   # Main CMake configuration
├── .clang-format    # Code style configuration
├── .github/         # GitHub Actions workflows
└── README.md        # This file
```

## Prerequisites

- GCC or Clang compiler
- CMake 3.14+
- Build tools: make or ninja
- lcov (for coverage reports)

## Building

### Quick Start

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Build Options

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
clang-format --dry-run -Werror src/*.c include/*.h
```

Fix formatting:
```bash
clang-format -i src/*.c include/*.h
```

## Design Patterns Demonstrated

### 1. Result-Based Error Handling
Instead of returning error codes mixed with data, use a result structure:

```c
typedef struct {
    StringError error;
    char* data;
    size_t length;
} StringResult;

StringResult string_duplicate(const char* src);
```

### 2. Explicit Resource Management
Clear allocation and cleanup patterns:

```c
StringResult result = string_duplicate("hello");
if (result.error == STR_OK) {
    // Use result.data
    string_result_free(&result);
}
```

### 3. Bounds Checking
Safe operations with maximum length parameters:

```c
StringResult string_length(const char* str, size_t max_len);
```

### 4. Null-Safe Operations
All functions handle NULL inputs gracefully:

```c
if (src == NULL) {
    result.error = STR_NULL_POINTER;
    return result;
}
```

## CI/CD Pipeline

The repository includes GitHub Actions workflows that:

1. **Lint**: Checks code formatting with clang-format
2. **Build**: Compiles the code in Release mode
3. **Test**: Runs unit tests with Google Test framework
4. **Coverage**: Generates and reports code coverage statistics

Coverage reports are automatically uploaded to Codecov and available as build artifacts.

## Example Usage

```c
#include "string_utils.h"
#include <stdio.h>

int main() {
    StringResult dup = string_duplicate("Hello");
    if (dup.error == STR_OK) {
        printf("Duplicated: %s\n", dup.data);
        string_result_free(&dup);
    }
    return 0;
}
```

## Testing with Google Test

The project uses Google Test for comprehensive unit testing:

```bash
# Build and run all tests
cd build
cmake --build .
ctest --output-on-failure

# Run specific test
./string_utils_test --gtest_filter=StringUtilsTest.DuplicateSuccessful
```

## Contributing

When contributing:

1. Ensure code is formatted with clang-format
2. Write tests for all new functionality
3. Maintain or improve code coverage
4. Update documentation as needed

## License

See LICENSE file for details.
