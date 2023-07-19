# Build systems

Similar to Java, but unlike Python, C++ is a compiled language. You must compile the source code
into an executable binary before you can run the code. The development process looks like:
- write C++ source code in one or more source files
- compile the source code
- run the compiled code
- repeat until the code runs as expected

## Libraries

Before talking about build systems, let's talk about libraries, which are one of the things a build
system creates and manages.

C++ can be compiled directly into an application, or it can be compiled into a library which is
subsequently linked into an application. The term "compile" means to read the source code and
translate it into native machine code. If this machine code is an executable file, there is no need
to do anything more, but it is possible to compile C++ source code into binary machine code that is
not executable. When that happens, the file that is produced is a library. There are two kinds of
libraries that C++ can produce:
- a static library
- a dynamic (sometimes called shared) library

Static libraries have the suffix `.a` (`.lib` on Windows). They contain machine code that must be
linked into an executable to be used. After linking, the relevant machine code will be directly
incorporated into the application and the static library is no longer needed.

Dynamic libraries have the suffix `.so` on Linux, `.dylib` on macOS, and `.dll` on Windows. Dynamic
libraries also participate in the linking process to create an executable. However, in contrast to
static libraries, dynamic libraries must always accompany the executable. The machine code of a
dynamic library is not incorporated into the executable.

Because they are not needed after linking, static libraries are simpler to use than dynamic
libraries, and for that reason the industry is rapidly moving away from dynamic libraries. The only
reasons to use a dynamic library now are:
- legacy code that was written before the industry realized static libraries are superior
- in certain situations to satisfy arcane and hostile intellectual property licensing requirements
- in certain integration scenarios like extending Python with C++

## Object Files

In the interest of simplicity, the previous section skipped over a detail that you should be aware
of. The actual C++ build process has the following steps:
- C++ source code is read and translated into machine code that is stored in object files (one
  object file per C++ source code file)
- Library object files are aggregated into static or dynamic libraries.
- Application object files are linked with libraries to create an executable file.

Object files have the extension `.o` on all platforms.

## Build Systems

Now that you know about object files and libraries and executables, we can talk about build systems.
Build systems are responsible for compiling source code into object files, assembling object files
into libraries, and linking application object files with libraries to produce executables.

Modern build systems do this by managing the dependencies of all these things, and only recompiling /
relinking things that have changed since the last time the code was built. This is called
incremental building or incremental compilation, and is an important part of a build system because
compilation can take a long time.

Next, take a look at the `make` subdirectory for an introduction to building with make.

After that, read the `cmake` subdirectory for an introduction to building with cmake.
