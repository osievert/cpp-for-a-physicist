# Resources

This guide is not meant to be an exhaustive training series that turns you into a C++ expert. It is
designed to give you a taste of what C++ is, enough that maybe you can work with some C++ code when
you have to. Enough that you can get some C++ code someone else wrote to compile on your system.
Enough that you can write a Python extension in C++.

Here are some helpful resources that you can use to continue to learn about C++.

If you are interested in more formally learning the C++ programming language, there are many
books that can help. Unfortunately, most of the C++ literature describes what I call C++old. However,
this book by Bjarne Stroustrup, the creator of C++, is pretty recent and covers so-called modern C++:

- https://www.amazon.com/Tour-2nd-Depth-Bjarne-Stroustrup/dp/0134997832

Scott Meyers has written extensively about C++, and I would highly recommend his books as well, although
Scott is retired now and so his books are not up to date with the most recent versions of C++.

Here are a couple of introductory C++ books that might be good places to learn more about how
to program C++:

- https://www.amazon.com/Primer-5th-Stanley-B-Lippman/dp/0321714113/ref=tmm_pap_swatch_0?_encoding=UTF8&qid=1689832540&sr=8-1
- https://nostarch.com/cppcrashcourse

When working with C++, there is no better online language reference than https://en.cppreference.com/w/ .
Prefer it in all your google searches for information about the C++ language.

Matt Godbolt's [Compiler Explorer](https://godbolt.org/) is the best place to play with C++ in a
[REPL](https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop)-like environment. Here you can
write some simple C++ code, compile it, and run it. You can also view the machine code that the compiler
emitted. This turns out to be quite helpful in understanding just how smart the compiler is, and what kinds
of optimizations it can make while compiling your code.

Once you know hte basics of C++, there are a lot of advanced topics to learn. The [ISO C++ Core
Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main) is a great source of
do's and don'ts for how to use the C++ language. For example it advises you on how to avoid older
language constructs that are still valid for backwards compatibility but which are discouraged from
being used in new code.

Herb Sutter is active in the C++ community. He writes a blog, [Sutter's Mill](https://herbsutter.com/)
that often focuses on interesting C++ topics. Again, something to refer to once you know the C++
language moderately well.

The annual C++ conference, CppCon, publishes to
[YouTube](https://www.youtube.com/channel/UCMlGfpWw-RUdWX_JbLCukXg) and includes talks on introductory
topics as well as advanced C++ topics.

The [GNU Make documentation](https://www.gnu.org/software/make/manual/) is a useful when you are
writing a Makefile and want to know how to express a certain concept.

Likewise, the [CMake documentation](https://cmake.org/documentation/) can be helpful in similar ways.

And, of course, Google and Stack Overflow are your friends.
