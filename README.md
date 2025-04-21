## CMake Project with OpenCV

This repository is a **step-by-step guide** on setting up a **C++ project** using CMake.  
It also demonstrates **OpenCV integration** for simple image display.  

---

## 📂 Project Structure
MyProject/ │-- CMakeLists.txt # CMake build configuration │-- include/ # Header files │ │-- helper.h │ │-- utils.h │-- src/ # Source files │ │-- main.cpp │ │-- helper.cpp │ │-- utils.cpp │ │-- image_view.cpp # OpenCV-based program │-- sample.jpg # Test image (for OpenCV) │-- build/ # Created when running CMake │-- README.md # This documentation

Step 1: Configure CMakeLists.txt

We create two executables:

    MyExecutable → Main application
    ImageViewer → OpenCV-based image viewer


### Build and Run
#### 1. Create a Build Directory
```bash
mkdir build
cd build
```

#### 2. Run CMake
```bash
cmake ..
make
```
### Run Executables

#### Run the main application:
```bash
./MyExecutable
```

#### Run the OpenCV Image Viewer:
```bash
./ImageViewer
```

#### Expected Output
```bash
Main Application

Hello from main!
Hello from helperFunction!
Hello from utilsFunction!
```

OpenCV Image Viewer

A window opens showing sample.jpg.# hello_cmake
