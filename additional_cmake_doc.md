Documenting the `CMAKE_INSTALL_PREFIX` behavior using your **GVirtuS** and **OpenCV** scenarios as examples. It’s structured to be both beginner-friendly and useful for future reference.

---

````markdown
# 📦 Understanding `CMAKE_INSTALL_PREFIX` in CMake Projects

This guide explains how to use the `CMAKE_INSTALL_PREFIX` variable in CMake to control where your project installs files. This is especially useful for Docker builds, isolated environments, or working without `sudo`.

---

## 🔧 What is `CMAKE_INSTALL_PREFIX`?

By default, when you run:

```bash
cmake ..
make -j$(nproc)
make install
````

CMake installs files into:

```
/usr/local/
```

This includes:

* Binaries → `/usr/local/bin`
* Libraries → `/usr/local/lib`
* Headers → `/usr/local/include`

This **requires root access** and may pollute your system.

---

## ✅ How to Install into a Local Directory

To avoid writing to system directories, tell CMake where to install:

```bash
cmake -DCMAKE_INSTALL_PREFIX=/your/custom/path ..
make -j$(nproc)
make install
```

Now everything is installed inside `/your/custom/path`.

---

## 📁 Directory Structure After Install

| Installed Item | Path                             |
| -------------- | -------------------------------- |
| Binaries       | `/your/custom/path/bin`          |
| Libraries      | `/your/custom/path/lib`          |
| Headers        | `/your/custom/path/include`      |
| Configs        | `/your/custom/path/etc` (if any) |

---

## 🧪 Runtime Setup

If your app uses shared libraries installed in a custom path, set this:

```bash
export LD_LIBRARY_PATH=/your/custom/path/lib:$LD_LIBRARY_PATH
```

For GVirtuS:

```bash
export GVIRTUS_HOME=/home/GVirtuS
export LD_LIBRARY_PATH=$GVIRTUS_HOME/lib:$GVIRTUS_HOME/lib/frontend:$LD_LIBRARY_PATH
```

---

## 📘 Examples

### ✅ Example 1: GVirtuS (No root, Docker-safe)

```bash
cd /home/GVirtuS
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/home/GVirtuS ..
make -j$(nproc)
make install
```

This installs all GVirtuS libraries, binaries, and headers inside `/home/GVirtuS`.
---

## 💡 When to Use This?

| Scenario                       | Use Custom Prefix? |
| ------------------------------ | ------------------ |
| Building in Docker or CI       | ✅ Yes              |
| No root access                 | ✅ Yes              |
| You want a system-wide install | ❌ No (use default) |
| Installing multiple versions   | ✅ Yes              |

---

## ✅ Summary

Using `CMAKE_INSTALL_PREFIX` gives you full control over where your project installs — making builds safer, portable, and reproducible.

For projects like **GVirtuS**, **OpenCV**, or any C++/CUDA tools, always consider isolating the install using this technique.

---

## 🛠 Tip for Testing

To keep builds even cleaner:

```bash
cmake -DCMAKE_INSTALL_PREFIX=$PWD/local-install ..
```
Everything stays inside the project folder under `./local-install`.
---

