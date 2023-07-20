# Hello, World

The canonical programming introduction - a full (but simple) program that prints the text "Hello, world".

This example shows some basic elements of C++:
- On line 1, an include statement. Like in the C programming language, to
  use an external type (whether part of your own app, part of a library you
  are integrating, or part of the C++ standard library), you need to import
  the data types and function declarations into your own code.
- On line 3, the beginning of the `main` function. Like c, and unlike Java
  and Python, C++ applications must have a main entry point. In C++, like
  in c, this main function returns an integer.
- On line 5, printing the phrase "Hello, world". In this version we see
  the use of the C++ iostream system. The iostream system is nested within
  the `std` namespace, and we see the `cout` stream referenced explicitly
  inside the std namespace. The `<<` characters indicate that the quoted
  string to the right is streamed into the cout. That is how you use a C++
  stream.
- On line 6, the program ends with the return statement, sending the integer
  exit code zero.

But how do you build and run this example? There are a dozen or more ways to compile C++ code - we
will talk about two of them in the next chapter. But for now, a simple Makefile is provided. In a
terminal window, change your working directory to this directory and simply type `make`. If your
pre-requisites are installed, an executable program `hello` will be created.

To run this example, simply execute it from your terminal: `./hello`.

## File Names

Let's pause for a minute and talk about file names. In Java, source files always have the file name
extension `.java`. In Python, source files always have the file name extension `.py`. But the C++
community hates consistency like that. If you're not careful, that kind of consistency could end up
making a language easy to use, and no one wants that. So in C++, source files can have a number of
file name extensions. The most common extension is `.cpp`, but you will see `.cc` and `.cxx` as
well. Sometimes you will see `.cp` or `.c++` but those are thankfully more rarely used.

You will also see a number of different file name extensions for C++ header files. `.h` and `.hpp`
are most common, but you might come across `.hxx` or `.hh` as well.

Of all the different variations, `.cpp` and `.h` are most common.

Bottom line, the C++ community has done the world a disservice by allowing all these variations,
because all they do is make things more confusing and complicated, for no real benefit. It means you
will have to be on the lookout for almost a dozen different file name extensions, and if you are
especially unlucky you will have to deal with C++ code that inconsistently uses all of them.

## Directory Structure

Java build tools have over time adopted a very rigid directory structure. If you follow the Java
gospel, then the Java build tools will grace you with an easy build process. If you don't follow
the Java gospel then you are excommunicated and not allowed to program Java.

Python has a few of its own conventions / requirements regarding directory structure, mostly around
how Python modules are defined.

In C++, though, there are no rules. Rules are for people who want things to be easy, and I think we
have adequately established that C++ programmers are allergic to easy. So in C++, put your files
wherever you want. Put them all in one directory. Separate them into different directories. Place a
few files under your couch cushions if you like. Source code file organization in C++ is the wild,
wild west. The C++ community says this is an advantage because it gives developers choice, and
choice is a good thing. But one person's choice is another person's confusion. When you are
presented with some C++ code, the first thing you will have to do is figure out how the author
decided to organize their code. Luckily, there are a handful of principled approaches to this that
you will often see used. The most common approach is to put C++ header files into a directory named
`include` and put C++ source files into a directory called `src`. The theory behind this approach is
that someone can look at the header files in the include directory and get a good idea of how to use
the code, because header files define the interface of the code. Doing this also make it easier to
install a library - libraries in C++ must be accompanied by their header files, and collecting
those into a single directory (or a single directory tree) makes that easier to manage.

The other directory structure you are likely to see has source files and header files beside each
other in the same directory. The advantage of this approach is that files that are focused on the
same thing (like a header file and its implementation, for example `foo.h` and `foo.cpp`) are stored
adjacent to each other in the same directory. Needless to say, this approach foregoes the advantages
of the approach described in the previous paragraph. 

## Exercise

Modify the sample to take a command line argument - the name of the person to greet. To do this, you
will need to know how command line arguments work in C and C++.

The `main()` function as written in the existing example takes no arguments, but in fact the main
function signature is `int main(int argc, char *argv[])`.

The first function parameter (`argc`) contains the number of command line arguments passed to the
program. The first argument is always the name of the program itself, so if you send no command line
arguments when you call a program, argc will be `1`.

The second function parameter (`argv`) is an "array of pointers to char" which is the formal way
to say an array of C strings. There are `argc` C strings in this array. The value of `argv[0]`
(the first string) is the name of the program.

This main function is a carry over from C, and so it uses these C data types. C is a very simple
programming language that makes safety the responsibility of the programmer. If you try to access
more `argv` strings than were passed, your program is ill defined and will likely crash. So when
you are programming with C arrays, you need to do so defensively.

With all of this said, here are the detailed instructions of this exercise:
- modify the existing main.cpp to greet a specific person
- the person's name is passed on the command line after the program name. When called as `./hello Josh`
  the program should respond with `Hello, Josh`.
- if no name is given on the command line, print the original `Hello, world`.
