# cpp-for-a-physicist

## C++ information for a physicist

If you are a recent physics graduate, you have probably used many programming languages in your
education. You likely learned to program using Java. I'm sorry. You almost certainly have been
exposed to Python, which is an exceptional language that is both easy to learn and extremely
powerful. You might have had to do some work in matlab, which is also a very nice environment (but
is quickly being eclipsed by Python + numpy as the defacto standard for scientific computing). But
sooner or later, you are going to be exposed to C++, which is without a doubt the most complex and
complicated programming language you are ever going to have to deal with. This guide is meant to
take some of the sting out of that. It will make C++ less mysterious, giving you the knowledge and
tools to be able to successfully work with C++ code.

## Introduction

C++ is a very old language - at the time of this writing about as old as the average physicist.
First conceived in 1979, C++ has continuously evolved over the last 44 years, the last 30 or so as
an ISO standard. In the last decade, the pace of C++ evolution has been dramatic. You will hear
people talk about so-called "modern C++". Modern C++ is C++ that uses the C++11 or newer language
standard. C++11, the version of C++ released in 2011, is considered to be the dividing line between
the modern C++ syntax which looks a lot like other modern programming languages like swift and
kotlin, and the before-times that I like to call "C++old". This evolution in syntax (and capability)
is a double-edged sword. It has allowed C++ to stay relevant in the modern world, but it is also one
of the reasons C++ is difficult to work with. Because the language standards committee has kept a
strong policy of backwards compatibility, 40-year-old C++ code will still compile and run today next
to modern C++ code. But side-by-side, these hardly look like the same programming language. This
guide will show you both the old language and the new. It will give you tips on how to deal with old
C++ code, and show you how to write new C++ code.

Because C++ is such an old language, it is plagued by two other ghosts of Christmas Past:
- multiple compiler implementations
- lack of a standard build tool
This guide covers both of these in detail.

## Assumptions

This guide is written for a reader who already knows how to program in a language other than C++. It
assumes you already know basic programming constructs. This guide is not a comprehensive course in
C++ programming. For that you should look elsewhere. This guide has a smattering of information
about the C++ language itself, but it is geared towards giving you the context and tools to deal
with C++ code as a thing you must use in the context of a larger project, as opposed to a guide on
how to become a C++ expert.

This guide also assumes you are working on a macOS or Linux computer. If you are working on a
Windows computer, I am sorry, because your life is destined to be harder than everyone else's. But,
much respect to you for choosing the hard road just to prove you can. People obviously use Windows
for C++ programming, and the Windows programming tools like Visual Studio are exceptional. But the
C++ code you are likely to encounter in the physics world is probably hostile towards Windows. My
best suggestion is to use the [Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/about)
which will let you follow this guide and avoid some Windows-specific pitfalls.

## Prerequisites

To get the most out of this guide, you will need a C++ compiler. On Linux I recommend using g++,
which is probably already installed on your system but if not is an easy package-manager call away
(for example on ubuntu you can call `sudo apt install build-essential`). On macOS I recommend
installing Xcode through the App Store.

You may be interested in the [Visual Studio Code](https://code.visualstudio.com/) editor. It runs on
Linux, macOS, and Windows, and is a good, free, platform-neutral code editing environment that has a
ton of extensions for many programming languages and tons of non-programming things.

You will need the [CMake](https://cmake.org/) meta-build system.

## Guide

The rest of this guide is contained in these chapters:

1. [Hello, world.](1-hello-world/README.md)
2. [Build systems](2-build-systems/README.md)
   - [Makefiles](2-build-systems/make/README.md)
   - [CMake](2-build-systems/cmake/README.md)
3. C++old versus C++new
4. C++ and Python
5. Compiler errors
6. C++ metaprogramming
6. Resources




