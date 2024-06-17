Compile `tools.cpp` to an object file.
```
c++ -c tools.cpp -o tools.o
```
Create a static library file containing the object file.
```
ar rcs libtools.a tools.o
```
Compile `main.cpp` while linking to the library file.  
- The `-L .` flag specifies to search the current directory for the library file.
- The `-ltools` flag links to the tools library.
```
c++ main.cpp -L . -ltools -o main
```
