# CMake

CMake is the most common build system used with C++.

The previous sentence is a lie. The lie is not about CMake being the most common. No, the lie is
about CMake being a build system. Most people say CMake is a build system, but in truth CMake is a
meta build system. It is a program that creates a build system that is used to compile your code.

Because it is a meta build system, and because CMake also is ancient (circa 1999), CMake is one of
the most frustrating things you are likely to encounter. The CMake syntax has changed a lot over
time, to the point that people talk about "modern CMake" as a different program than the original
CMake. But above and beyond that, CMake has its own behaviors and order of operations that are not
well documented or easily understood by newcomers. These behaviors are such that even if you fully
understand how to compile C++ code using g++ and Makefiles, CMake can be frustratingly obnoxious to
work with - you know what you want to do but you can't convince CMake to do it for you. That is
CMake's double-edged sword: CMake sits between you and the compiler so it can hide many compilation
complexities, but CMake sits between you and the compiler so it can prevent you from doing what you
want.

Let's first talk about how CMake works. If you understand the way in which CMake works, then you are
more knowledgeable than 99% of developers and you can probably work through any CMake problems you
encounter. The typical CMake workflow looks like this:
- create a build directory that CMake will use
- run the `cmake` command (with some command line arguments we will discuss later) to generate a
  build system
- use this generated build system to actually build your code

It is important to take note that the process to generate the build system is distinct from the
process of actually building (compiling) your code. When working with CMake, certain things are done
at generation time, and other things are done at build time. One of the main sources of confusion
with CMake is thinking that something you tell CMake to do happens at build time, when in fact it
happens at generation time.

If CMake generates a build system, what build system does it generate? By default, on macOS and Linux
CMake will generate a `make` build system unless told to do something else. On Windows, CMake will
generate a Visual Studio build system by default (if Visual Studio is installed). But CMake supports
several other build systems that you can ask for - ninja and Xcode are popular build systems that CMake
supports.

When running CMake to generate a build system, the one required parameter is a path to the directory
that contains the top-level CMakeLists.txt file. All CMake configuration starts in one or more
CMakeLists.txt files. It is extremely common for the root directory of a code repository contains a
CMakeLists.txt file, os a very common way to build C++ code with CMake is:
```
cd cool_new_cpp_code
mkdir build
cd build
cmake ..
make
```

This series of terminal commands navigates to a code repository, creates a `build` directory, and inside
this build directory executes CMake (telling it to look for a CMakeLists.txt file in the root directory
of the code repository). Since we are on macOS or Linux, CMake generated a make build system (wrote a
Makefile, along with a bunch of other supporting files). After cmake generated the make build system,
we just have to type `make` to build the project.

In this directory we have a copy of the hello main.cpp file from chapter 1. We also have a complete,
but extremely simple CMakeLists.txt file. These two files are a complete example of a CMake-based
C++ project.

The CMakeLists.txt has the three required elements to direct CMake to create a build system for a
command line executable. First is the declaration `cmake_minimum_required` which must always be the
first line of any top-level CMakeLists.txt file. This tells CMake that this project requires a
version of CMake that is at least as new as the version listed. This is required because CMake's
syntax has evolved so much over the last 20+ years that newer CMakeLists.txt files will not work
with older versions of CMake. This is a continual and ongoing problem, because CMake itself
continues to evolve.

The second required element in a top-level CMakeLists.txt file is the project declaration. This
declaration takes a parameter which is the project name. The name doesn't matter - it's just a name.
Here we declare a project whose name is the same as the name of the executable we are building (hello).

The third element finally declares that we want to build an executable (and not a library, for example)
whose name will be `hello` and which comprises one source file `main.cpp`.

That's it, for a minimal CMakeLists.txt. There is a ton of additional complexity and options that
you will see in CMakeLists.txt files, but this is the simple version.

## Exercise

Build this project. Follow the typical steps outlined above: create a build directory, run cmake,
and then run the generated build system. Observe when done how you have a lot of CMake files littering
the build directory, but the build directory also contains the `hello` executable. Run it, to prove
it was compiled correctly.

