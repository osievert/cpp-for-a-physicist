# Make

Make is a very old program, created in the late 1970s. Being old enough to retire now, make shows
its age in its awkward syntax and many behavioral quirks, but at the same time it is possible to do
simple things very simply with make. We will show you a few.

At its heart, make is a framework within which you define rules, which are actions to perform, and
the dependencies between rules. Every rule has an input, and an output. Dependencies are specified
using these inputs and outputs.

Make rules are placed into a `Makefile` (note capital `M`). To execute a build with make, simply
open a terminal in a directory with a Makefile, and type `make`. This will execute the default rules
defined by the Makefile. You can specify a specific rule to run by passing it as a command line
parameter like `make fun` which will run the `fun` rule.

That is a bit of a white lie. When you type `make fun` you are not GUARANTEED to run the fun rule.
First, the inputs to the fun rule are checked. If those inputs are not newer than the output of the
fun rule, then the fun rule is not executed. No need to. If the inputs have not changed, then why
bother running the rule, because the output won't be any different. In make, this is what allows
incremental compilation, which can save a ton of time in a large project.

Take a look at the Makefile in chapter 1. It defines one rule named `hello`. This rule is a word
that is left-justified in the file (there are no spaces to the left of the word `hello`).
Immediately following the rule name is a colon (`:`). To the right of the colon are the input files
that the hello rule depends on. In this case, a single file `main.cpp`. More than one input file can
be specified here. If more than one file is specified, they are separated by a space character.

On the next line you see the action that this rule runs - a call to the `g++` compiler. This command
is only executed if the rule's input (the file `main.cpp``) is newer than the rule's output. What
is the rule's output? It is a file whose name is the same as the name of the rule. In this case, a
file named `hello`. Every rule can have only one output, for the purposes of dependency management.
But rule actions can create as many files as they want, and can call as many actions (commands) as
they want.

Every rule's actions / commands are simply commands that are available in your terminal window. Anything
you can type in a terminal window, can be a command. This is one of the things that makes make so
powerful. Instead of defining a finite set of commands you can run, make is infinitely extensible
because any command you can run, can be put into a Makefile. That means that you can use make for
almost any purpose you want. The only restriction is whether the command is installed on your computer.
And there lies the double-edged sword. You can do almost anything in make, but you have to ensure
that all the programs being called are already installed, and make provides you with no help there.

You might notice that the command in the chapter 1 Makefile is not left-justified like the rule name
`hello:` is. The command is indented a few spaces. In fact, make is very particular about this. All
the commands that comprise a rule must be indented with one tab character. Not spaces, but a tab.
This is a very arcane syntax that is extremely error prone. Because you can't see a tab, any more
than you can see a space character, you can't tell whether a Makefile is properly formed by looking
at it. If make fails to run properly and gives you some very unintelligible errors, one of the first
places to look is to ensure that all rule commands are indented, and indented with a tab and not spaces.
Sometimes editors, like Visual Studio Code, recognize when you are editing a Makefile and help you
do the right thing in regards to tabs and spaces.

What I described above is the essence of make. Make has a lot more features, for example you can
define variables and program limited conditionals. All the additional features build upon this
foundation of input files, rules, and output files.

There is one particular feature that is worth mentioning here - a way to defeat make's dependency
management. Let's say you have a rule that you always want to run. To do that, you define a
so-called phony rule in your Makefile. A phony rule is a rule that is preceded with the line
`.PHONY: <rule name>`. This indicates to make that it should not use file timestamps to determine
whether to run a rule, and instead should always run the rule. Here is an example:

```
.PHONY: say
say:
    echo "cows say 'moo'"
```

The `.PHONY` line tells make to ignore modification timestamps even if a file named say exists.
You can often get away without declaring a rule as phony, and just giving your rule no dependencies,
but it is considered good practice to always declare rules whose name does not correspond to a file
on disk as phony.

## Exercise 1

For the first part of this exercise, open the chapter 1 Makefile and delete the tab to the left of
the command in the `hello` rule. Save the file, then in a terminal window in the `1-hello-world`
directory run `make` and observe the error.

Next insert a couple space characters to the left of the hello command. Notice how the spaces
cause the Makefile to appear to be well-formed. Save the file, then in a terminal run `make` again.
Notice how make again fails to run successfully.

Finally, replace the spaces before the hello command with a single tab character. Save the file, then
run `make` one more time, and notice how it runs successfully.

## Exercise 2

With the Makefile in its original condition, type `make` in a terminal window in the `1-hello-world`
directory. This may or may not call g++ to compile the main.cpp file into the `hello` executable,
depending on whether you had already typed `make` previously to build the hello executable.

Type `make` again. This time, you should NOT see g++ being called, because the modification timestamp
on the `hello` program is newer than the modification timestamp on the `main.cpp` file.

Next, open the hello world `main.cpp` source file in an editor. Add an empty line to the bottom of the
file, then save it. Then go back to your terminal and type `make`. Observe how g++ is called this time,
because the modification timestamp on the main.cpp file was newer than the modification timestamp on
the `hello` executable.

Type `make` again. This time, you should NOT see g++ being called, because the modification timestamp
on the `hello` program is newer than the modification timestamp on the `main.cpp` file.

Finally, delete the `hello` executable and then type `make` one more time. Notice that it calls g++
to rebuild the hello executable, since it didn't exist.

## Exercise 3

Revert all your changes to the chapter 1 Makefile, restoring it to its original state. Then add a new
rule to this Makefile. Add the rule above the hello rule. Call the rule `clean` and make it a phony
rule. This rule should have one command, which is to remove the hello executable: `rm hello`. Remember
to indent the command with a single tab character.

Now go to your terminal window and type `make`. Notice how the clean rule is executed, and not the
hello rule. That is because the first rule defined in the Makefile is the default rule that is executed
if no other rule is given. It doesn't make sense for the clean rule to be the default, so go back to the
Makefile and move the clean rule so it is below the hello rule. Run `make again` and notice that the
hello rule is run.

Now that we have two rules, and the hello rule is the default, how do you call the clean rule? With
`make clean` of course. Do that and notice how the hello executable is removed. Now if you type `make hello`
or simply just `make` notice how the hello executable is rebuilt.

Add a third rule to your Makefile. This rule will be named `run` and it will also be a phony rule.
Make this rule depend on the `hello` file, and give it the command `./hello`. Save the Makefile, and
return to your terminal. Type `make run` and notice how the hello executable is run and prints
`Hello, world`. But now, run `make clean` to delete the executable. Then type `make run` again. What
do you think will happen? There is no executable named `hello` to run? That's ok. Because you made
the run rule depend on the hello executable file, and because make knows how to create the `hello`
executable file, when you type `make run` make fill first call the hello rule, and will then call the
run rule. In this way, you can build up long and complex chains of dependencies.



