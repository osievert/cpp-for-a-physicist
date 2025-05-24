# VS Code

Visual Studio Code is a free, open-source code editor that runs on Linux, macOS, and Windows. It is
a good code editor for C++ programming. This is an ever-so-brief primer on how to use VS Code.

## Installation

To install VS Code, go to the
[Visual Studio Code download page](https://code.visualstudio.com/Download)
and download the installer for your platform. Follow the instructions to install it.

Once you have installed VS Code, install the shell integration by running the command cmd+shitt+p or
ctrl+shift+p (on Windows) and typing "Shell Command: Install 'code' command in PATH". This will
install the `code` command in your shell's PATH, allowing you to open VS Code from the terminal by
typing

```
code .
```
This will open the current directory as a workspace in VS Code.

## Extensions

VS Code has a rich ecosystem of extensions that can enhance your C++ programming experience. Some
popular extensions for C++ programming include:
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools): Provides C/C++ language support, including IntelliSense, debugging, and code navigation.
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools): Provides CMake support, including CMake configuration, build, and debugging.
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb): Provides LLDB support for debugging C++ code.

I personally do not use the CMake Tools extension, but I do use the C/C++ extension. The CMake Tools
extension attempts to make it easy to use CMake from within VS Code, but I find it easier to use
CMake from the terminal. The extension tries to do things for you, automatically, but it often fails
to do them correctly, and creates an opaque layer that makes it hard to understand what is going on.
I prefer to use CMake directly from the terminal, and then use VS Code to edit the code and debug
it. You are, of course, free to do anything you like, but if you use the CMake Tools extension and
end up being confused, I recommend you try using CMake directly from the terminal instead.

## Debugging

VS Code has a built-in debugger that can be used to debug C++ code. To use the debugger, you need to
create a launch configuration. To do this, open the debug view by clicking on the debug icon in the
left sidebar, or by pressing `Ctrl+Shift+D` (or `Cmd+Shift+D` on macOS). Then click on the gear icon
to create a launch configuration. Select "C++ (GDB/LLDB)" as the environment, and VS Code will
create a `launch.json` file in the `.vscode` directory of your workspace. You can then edit this
file to configure the debugger. The default configuration should work for most cases, but you can
customize it to suit your needs. For example, you can specify the program to debug, the arguments to
pass to the program, and the working directory. You can also specify environment variables to set
when debugging. Once you have configured the debugger, you can start debugging by clicking on the
green play button in the debug view. This will start the debugger and run your program. You can then
set breakpoints, step through the code, and inspect variables in the debug view.

## Keyboard Shortcuts

VS Code has a rich set of keyboard shortcuts. A few of the most useful ones:
- `Ctrl+P` (or `Cmd+P` on macOS): Quick open file by name.
- `Ctrl+Shift+P` (or `Cmd+Shift+P` on macOS): Open the command palette to run commands.
- `Ctrl+Shift+F` (or `Cmd+Shift+F` on macOS): Open the search view to search for text in files.
- `Ctrl+J` (or `Cmd+J` on macOS): Toggle the appearance of the integrated terminal.
