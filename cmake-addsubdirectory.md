CMake **subdirectory** concept

---

```markdown
# CMake `add_subdirectory` Concept — Modular Project Structure

## Overview

In **CMake**, the `add_subdirectory()` command is used to include and process CMake configurations from another folder within your project.  
This enables **modular project design** by breaking down a large codebase into smaller, manageable components — each with its own `CMakeLists.txt` file.

### Why Use `add_subdirectory`?

1. **Modularity**  
   Organize your code into separate folders such as `src/`, `tests/`, `dev/`, `examples/`, etc.
   
2. **Separation of Concerns**  
   Each folder has its own `CMakeLists.txt` responsible for building that component, avoiding a cluttered root CMake file.
   
3. **Reusability**  
   Components can be reused across different projects without major restructuring.

4. **Scalability**  
   Makes it easier to maintain and extend large projects by isolating build logic for different parts.

---

## Basic Structure

A typical project using `add_subdirectory` might look like this:

```

project-root/
│
├── CMakeLists.txt           # Root CMake file
├── src/
│   ├── CMakeLists.txt       # Build logic for main source code
│   ├── main.cpp
│   └── utils.cpp
│
├── tests/
│   ├── CMakeLists.txt       # Build logic for tests
│   └── test\_main.cpp
│
└── dev/
├── CMakeLists.txt       # Build logic for development tools
└── tool.cpp

````

---

## Example: Root `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyProject)

# Set common settings
set(CMAKE_CXX_STANDARD 17)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(dev)
````

---

## Example: `src/CMakeLists.txt`

```cmake
# Create an executable from source files
add_executable(my_app
    main.cpp
    utils.cpp
)

# Optional: Add include directories
target_include_directories(my_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

---

## Example: `tests/CMakeLists.txt`

```cmake
# Create a test executable
add_executable(my_tests
    test_main.cpp
)

# Link tests with the main app library or source files
target_link_libraries(my_tests PRIVATE my_app)
```

---

## Key Points to Remember

* **Relative Paths:**
  Paths in `add_subdirectory()` are relative to the directory containing the `CMakeLists.txt` file where the command is called.

* **Independent Builds:**
  Each subdirectory has its own build scope, variables, and targets but can still share global settings from the root.

* **Order Matters:**
  If a subdirectory depends on targets from another, add it **after** the dependency in the root CMake file.

---

## References

* [CMake Official Documentation — add\_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html)
* [Modern CMake Examples](https://cliutils.gitlab.io/modern-cmake/)

```


