Solution for the **`libopenpose.so.1.7.0` not found** error during dynamic linking:

---

````markdown
# 🐛 Fix: `libopenpose.so.1.7.0` Not Found at Runtime

## ❓ Context

While compiling and running a custom `.cu` file (`01_test.cu`) that uses OpenPose, the binary compiled successfully using:

```bash
nvcc 01_test.cu -o test_gvirtus \
  -I/home/openpose/include \
  -I${GVIRTUS_HOME}/include \
  -L/home/openpose/build/src/openpose -lopenpose \
  -lgflags -lglog -lprotobuf \
  `pkg-config --cflags --libs opencv4` \
  -std=c++11
````

However, on executing the compiled binary, the following error occurred:

```bash
./test_gvirtus: error while loading shared libraries: libopenpose.so.1.7.0: cannot open shared object file: No such file or directory
```

---

## ✅ Why This Happens

This error occurs when the Linux dynamic linker (`ld.so`) cannot find the required shared library (`libopenpose.so.1.7.0`) at runtime.

### 🔍 Common Causes

* OpenPose was built **locally**, not installed system-wide
* The `.so` file resides in a **custom build directory**
* That directory is **not included in `LD_LIBRARY_PATH`**

---

## 🛠️ Solution: Use `LD_LIBRARY_PATH`

You must tell the dynamic linker where to find the `.so` file using the `LD_LIBRARY_PATH` environment variable.

---

## 🧩 Step-by-Step Fix

### 1. 🔎 Locate the compiled `.so` file

Run:

```bash
find /home/openpose/build -name "libopenpose.so*"
```

Expected output:

```
/home/openpose/build/src/openpose/libopenpose.so.1.7.0
```

---

### 2. 🧠 Set `LD_LIBRARY_PATH` in your session

```bash
export LD_LIBRARY_PATH=/home/openpose/build/src/openpose:$LD_LIBRARY_PATH
```

This adds the folder containing `libopenpose.so` to your dynamic linker search path.

---

### 3. 🧪 Use `ldd` to verify linkage

`ldd` = "list dynamic dependencies" — shows what libraries your binary uses and whether they are found.

```bash
ldd ./test_gvirtus | grep openpose
```

Expected result:

```
libopenpose.so.1.7.0 => /home/openpose/build/src/openpose/libopenpose.so.1.7.0
```

If you still see `=> not found`, then `LD_LIBRARY_PATH` is not set correctly.

---

### 4. ▶️ Run your binary

```bash
./test_gvirtus
```

It should now work without the shared library error.

---

## ✅ Recommended: Add to Your Script

To avoid repeating this manually, add this line to your `entrypoint.sh`, `.bashrc`, or run script:

```bash
export LD_LIBRARY_PATH=/home/openpose/build/src/openpose:$LD_LIBRARY_PATH
```

---

## ✅ Summary

| Step        | Action                                              |
| ----------- | --------------------------------------------------- |
| Build       | Use `-L` to link OpenPose library path              |
| Runtime fix | Set `LD_LIBRARY_PATH` to include OpenPose build dir |
| Verify      | Use `ldd` to check if `.so` is resolved             |
| Persist     | Export the variable in your startup or run script   |

---

