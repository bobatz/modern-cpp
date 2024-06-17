## Building manually.

In this example, we compile `main.cpp` by linking the `tools` library.

Compile `tools.cpp` to an object file.
```
c++ -std=c++17 -c tools.cpp -o tools.o
```

Create a static library file containing the object file.
```
ar rcs libtools.a tools.o
```

Compile `main.cpp` while linking to the library file.  
- The `-L .` flag specifies to search the current directory for the library file.
- The `-ltools` flag links to the tools library.
```
c++ -std=c++17 main.cpp -L . -ltools -o main
```

## Building with CMake

The build process above becomes difficult with larger projects. Instead of compiling the project manually, we can specify and execute the exact same steps using a `CMakeLists.txt` file.

```
mkdir build
cd build
cmake ..
make
```
