# Libraries

Let's talk a little more about libraries. There are two projects in this directory, one which
creates a static library which is integrated into an application, and one which creates a dynamic
library which is integrated into an aplication.

## Static

In the `static` directory is a Makefile and a couple of source files:
- `main.cpp` contains the application's `main()` function
- `greet.h` is the header file for the library
- `greet.cpp` is the implementation source file for the library

To build this project, change your current working directory in a terminal to the `static` directory
and type `make`. If you look at the Makefile, you will see there are four rules defined - three of
which builds the project and one cleans the build products:
- the `app` rule builds the final application. This rule depends on two files, `main.cpp`
  and `libgreet.a`, the latter of which is a static library.
- the `libgreet.a` rule builds the static library. This rule depends on one file, `greet.o`, which
  is the object file produced from compiling `lib.cpp`
- the `greet.o` rule compiles the library source. This rule depends on one file, `lib.cpp`,
  which is the library implementation source file.
- the `clean` rule is a phony rule which, when executed, removes the application and the
  intermedia build products `libgreet.a` and `greet.o`.

To run this application, simply execute `./app` in the `static` directory.

## Dynamic

In the `dynamic` directory is a Makefile and a couple of source files (same files as are in the
`static` directory):
- `main.cpp` contains the application's `main()` function
- `greet.h` is the header file for the library
- `greet.cpp` is the implementation source file for the library

In this directory, however, the Makefile builds a dynamic library instead of a static library, which
is built by the `libgreet.so` rule. If you study this example closely, you can see some other subtle
differences in how the application is built in the `app` rule.

To run this application, simply execute `./app` in the `dynamic` directory.

## Naming

It is conventional to name libraries with names beginning with `lib`. In this case, `libgreet.a` and
`libgreet.so`. This naming convention is relied on by the build system. You can see in the dynamic
Makfile how the library is referenced in the `app` build rule with the phrase `-l greet`. The `-l` here
is a command line argument that preceeds a library, and the `greet` that follows is a reference to the
file `libgreet.so`. Note that neither the `lib` prefix nor the `.so` suffix is listed here.

When using the `-l` option to link a library, you need to also use the `-L` option to tell the compiler
what directory (directories, really, because you can use the `-L` option multiple times) in which to
look for libraries to link. In this Makefile, we use the form `-L.` which means "look in . (the current
directory) for library files".

## Discovering Dynamic Dependencies

When you build an app using static libraries, the machine code of the static library is included into
the executable file. After compiling, you can't tell that a static library was used. Everything is
integrated into the one executable file.

But when you build an app using dynamic libraries, the end result is different. You still have to link
the dynamic library into the app, but the machine code is not incorporated into the application file.
Instead, the machine code stays in the dynamic library. This means that the application is more complicated -
it comprises more than one file. In complicated apps that are built with dynamic libraries, you might have
a dozen dynamic libraries to manage. If you misplace one of those dynamic libraries, the app will fail to
run. If you place one of those dynamic libraries in the wrong directory, the app will fail to run.

If you encounter a situation where an application won't run because of a missing dynamic library, you
will see an error telling you which library can't be found. You can query the application to understand
what dynamic libraries on which the application depends. On macOS you do this with `otool -L <application>`.
On linux you do this with `ldd <application>`. On windows you can use `dumpbin /dependents <application>`.
This works for dynamic libraries as well as applications.

## Exercise

Change the `app` rule in `static/Makefile` to link the static library with the `-l` syntax that the
dynamic Makefile uses. Don't forget to also use the `-L` option. Ensure that you can still compile the
app after this change.

Change the `app` rule in `dynamic/Makefile` to reference the dynamic library by name instead of using
the `-l` approach. Ensure that you can still compile the app after this change.

Examine the dependencies of the `static/app` application using otool or ldd. Notice that the application
depends on a couple system libraries, but there is no sign of `libgreet.a` as a dependency. That is expected
since the machine code of `libgreet.a` has already been included in the application.

Examine the dependencies of the `dynamic/app` application using otool or ldd. Notice that the application
depends on a couple system libraries and also depends on `libgreet.so`. That is expected.

Examine the dependencies of some prebuilt applications on your system, using otool or ldd. For example,
you can type `which ls` to find the location of the ls command. See what dependencies it has. Type
`which bash` to find the location of the bash command. See what dependencis it has. Otool and ldd can
be used on any file.
