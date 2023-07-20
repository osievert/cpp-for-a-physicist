# Build systems

Similar to Java, but unlike Python, C++ is a compiled language. You must compile the source code
into an executable binary before you can run the code. The development process looks like:
- write C++ source code in one or more source files
- compile the source code, using a build system
- run the compiled code
- repeat until the code runs as expected

To compile code means to read the source code and translate that into machine code - the actual
hardware instruction set of the computer.

In the C++ world, compiled code can take a couple of forms. You can compile your code into an
executable - a program that you can run. This program might be a command line executable that you
use in a terminal, or the program might open a Window and provide a graphical user interface. You can
also compile C++ code into a library. A library is a collection of compiled code that doesn't
have a main function and so cannot be executed by itself. Libraries are linked with 
compiled code that defines a main function in order to produce an executable.

## Libraries

Libraries are not a required part of the build process. In the hello-world example, we did not first
compile that source into a library and then create an executable from the library. Instead we just
compiled that source code directly into an executable. We could have created a function called
`greet()` which printed to std::cout, compiled that function into a library, and then linked that
library with our `main()` function to create the hello executable. But that seems like a lot to do
for such a simple program.

So when should code be compiled into a library, and when should it be compiled into an executable?
Libraries give you some choices about how you organize, build, and share your code. Your `main()`
function is always compiled into an executable, but if you are building a complicated program, then
it is common to break down your program into several parts, each of which is a library that is
linked together with the `main()` function into the final executable. You might do that just to
manage the complexity of your code base, but there are other reasons that a program might be broken
down into libraries. Perhaps each of the libraries in your program is authored by a different
person. Perhaps the source code for each of these libraries is stored and managed each in its own
github repository, and the authors of these libraries don't know each other, and don't know you. In
this sort of a situation, the library authors still need to be able to compile their code and make
sure it works correctly. They don't know you exist and so can't rely on you to do this for them.
This is a common situation where a library is used. Each author organizes their source code and
creates a build system that produces a library. They can link that library with their own test
program to make sure the library works as intended. But you can also link your own `main()` function
with those libraries to create your program.

There are two kinds of
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
