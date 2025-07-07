# MyADT Library

**MyADT** (My Abstract Data Types) is a collection of C++ implementations of classic data structures. This library is designed for educational purposes, allowing users to explore how common data structures work under the hood.

## 📦 Features

This library includes:

- ✅ Singly and Doubly Linked Lists
- ✅ Binary Tree
- ✅ Stack and Queue
- ✅ Vector
- ✅ Hash Table
- ✅ Unique and Shared Smart Pointers (custom implementation)

Each data structure is implemented using modern C++ features, such as smart pointers.

## 🗂️ Project Structure

```text
.
├── MyADT/                 # Source code for all data structures
├── examples/              # Example usage for each structure
├── build/                 # CMake build directory(after build lib)
├── CMakeLists.txt         # Project build script

```

---

## 🔧 Build Instructions

### Requirements

- C++ compiler (GCC, Clang, or MSVC)
- CMake 3.10+
- Make (Linux/macOS) or Ninja

### Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/MyADT.git
cd MyADT

# Create build directory
mkdir build && cd build

# Configure the project
cmake ..

# Build the static library
make
```

This will generate:

- `libMyADT.a` — static library you can link with
- Compiled object files for internal use
- You can also link the examples manually or modify the CMake file to include them in the build.

---

## 🧪 Running Examples

You can compile and run an example manually:

```bash
g++ -std=c++17 -I../MyADT ../examples/Example_List.cpp ../build/libMyADT.a -o list_example
./list_example
```

Or create your own `main.cpp` file and link it against `libMyADT.a`:

```bash
g++ -std=c++17 -I../MyADT main.cpp ../build/libMyADT.a -o my_program
```

---

## 💡 How to Use

To use any of the data structures in your project, simply include the necessary headers:

```cpp
#include "mylist.h"
#include "myvector.h"
#include "myhashtable.h"
// And more...
```

All headers are located in the `MyADT/` folder.

Each header defines a separate data structure implemented using modern C++ features.

---
