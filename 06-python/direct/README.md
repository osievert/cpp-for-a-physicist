# Direct Python Extension

A python module can be written in C++ without anything else other than the Python distribution. To
do so, create a C++ module implementation file. An example module file
[foomodule.cpp](foomodule.cpp) is in this directory.

It is recommended you do all your python work in a virtual environment. That prevents this work from
affecting anything else you are doing on this computer. To create a python virtual environment, open
a terminal window in this directory and type

```
python3 -m venv venv
```

This will create a virtual environment in the `venv` subdirectory of this directory. To enter the
virtual environment, type this in the terminal window:

```
source ./venv/bin/activate
```

To build this extension, open a terminal in this directory and ask the python setuptools to build the
extension:

```
python3 setup.py build
```

The python setuptools will compile the extension and place a dynamic library in a directory named
something like `build/lib.macosx-13-arm64-cpython-311/foo.cpython-311-darwin.so`. This is the python
extension. It is a dynamic library (see chapter 3 for more details on libraries).

Once you have compiled the C++ code into a Python extension module, you can test it. To do that, you
have to tell python where to find the dynamic library (because the library has not been installed yet).
The file `test_manual.py` shows how to do this, by modifying the python `sys.path`. Ensure the path
that is specified in `test_manual.py` matches where Python built the extension module on your system,
and update the path if necessary. Then in the terminal window, type

```
./test_manual.py
```

and you should see a comparison of string length calculations, one by the `foo` module you just built,
and one by the builtin python `len()` function.

Using setuptools you can also install the python extension you just built. Type

```
python3 setup.py install
```

to install the extension. Now that the extension has been installed (into the virtual environment, if
you created one) you no longer need to modify the python `sys.path` to import the module. The script
`test_install.py` shows how you can use the `foo` extension module after it has been installed. You simply
have to `import foo` like you would with any other python module. Type

```
./test_install.py
```

to run this script. Notice that it prints the same thing that `test_manual.py` did.

To clean up after all of this, you can:
- delete the `venv` virtual environment
- delete the `build` directory, where the extension was built
- delete the `dist` and `Foo.egg-info` directories used by the installer
- exit the virtual environment by typing `deactivate`

A couple of things to note about all of this:
- The C++ functions are enclosed in an `extern "C"` block. This tells the compiler that the
  functions have C linkage, meaning that even though this is a C++ file the function
  declarations should be compiled as C code. Python extension functions must be C functions,
  although the function implementations can be C++.
- In this example, everythig was implemented in the single file `foomodule.cpp` but there
  is no reason why the extension C++ code can't be spread out across several files. There
  is no reason why the extension module can't link in other static or dynamic libraries.
- This example shows the minimal set of code to interact with Python. That includes a
  `PyInit_<modulename>` funciton that is the module initialization function called by Python
  when you import the module, a `PytModuleDef` struct that defines basic metadata about the Python module, a `PyMethodDef` array that defines the functions the module provides, and the
  `foo_bar` function definition itself. It seems like a lot of boilerplate, and it is, but
  each piece is required and serves a purpose.
- More info about this method of extending python can be found here:
    - https://docs.python.org/3/extending/extending.html
    - https://docs.python.org/3/extending/building.html#building
