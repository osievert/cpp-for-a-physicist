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
- the person's name is passed on the command line after the program name. When called as `./greet Josh`
  the program should respond with `Hello, Josh`.
- if no name is given on the command line, print the original `Hello, world`.
