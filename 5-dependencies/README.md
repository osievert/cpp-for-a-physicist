# Dependencies

It is rare that any code, in any language, is a completely stand-alone entity that has no
dependencies. Unfortunately, C++ has particularly poor support for dependencies. In this chapter we explore the ways that dependencies are often managed in C++.

## Option 1: System-wide Dependency Management

If you are working on a linux operating system, you may be able to manage dependencies
through the operating system itself. Every linux distribution comes with a capable
package manager that allows sufficiently-privileged users to install and manage packages,
and most linux package managers have tens of thousands of available packages to choose from. 

It is likely that your dependencies are supported by this operating system package management system. If so, then you simply need to install your dependent packages using your operating system package manager, and then your build system will find those dependencies automatically at build time.

Sometimes, even though your operating system package manager has installed a dependency, you may
have to give your build system hints to help it locate the installed packages. We did not talk about
this in the build system chapter, but it is common for make-based build systems to also use
autoconf, which helps with this problem. Make build systems that use autoconf come with a
`configure` script that configures the build system before you actually build. Often, these
`configure` scripts allow you to specify the location of dependencies that are not automatically
found.

For example, if your program depends on the curl package, but your build system can't find it,
You might give the configure script a hint like this:
```
./configure --with-curl=/usr/extra/curl
```

## Option 2: Project-specific Dependency Management

If your operating system does not have a package manager, or if your package is not available in your operating system's package manager, then you will have to manually deal with your project depednencies.

If your make-based build system does not use autoconf and does not have a `configure` script, you
may have to manually edit your Makefile(s) to supply those hints.

CMake has the ability to automatically download and compile dependencies, but in practice this
feature is seldom used. If your project uses CMake, and it uses this feature, that is great. You
don't have to do anything special to satisfy your project dependencies. You might not even know that
you have such a dependency and that CMake is doing that for you. This CMake feature is nice, but
just know that these kinds of dependencies are hidden from you, so don't use this feature if you
need to read and/or modify the dependency code.

To manually manage dependencies, you will have to download every dependncy, build it locally, and
install it locally. You will have to do this for every dependency in your project and for every
dependency your dependencies have. It can become quite a burden if you have a lot of dependencies.
For each dependency, once it has been downloaded, built, and installed, you will have to give hints
to your build system for how to find each one. Unless you did a system-wide install of the dependency,
in which case it is possible your build system might find the dependency without any hint.

If you are running on a virtual machine or in a container environment, it is common to install all dependencies into the system. But otherwise, it is considered bad form to do that, because the dependencies of your current project may be in conflict with the dependenices of another project, so system-wide
installations can prevent you from working on any other project. It is also possible that you do not
have the privileges requried to install packages system-wide. Either way, sometimes people create
a drectory under their user, specific to a project, where they install all of that project's dependencies.
You will hear people refer to this as a "sysroot". Using a sysroot like this can simplify the management of all your project's dependencies, because you only have to look in one place to both see what is installed and it can make it easier to give hints to your build system.

## Exercise

Build the CMake project in this directory. CMake will download a library and include that in the build process. Examine how this is done. Where is the source for the mazegen library?


