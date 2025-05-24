# C++ Old vs New

C++ is a very old language, but in the last decade it has evolved quite a lot. Modern C++ doesn't
look muchlike C++old. This section illustrates some of the differences, so when you look at C++
you can read it whether it is old or new.

## Type declarations

C++old, like C, is a statically-typed language that makes you declare your data types explicitly,
for example
```
int a;
double b;
std::string c;
```

Modern C++ is the same, under the hood: static data types. But modern C++ allows the programmer to
tell the compiler "please infer this data type for me" using the `auto` keyword. Using `auto`, when
the type is unambiguous, the compiler will replace the keyword `auto` with the inferred type and
continue the compilation process. When the type is ambiguous, the compiler stops with an error.
Examples:
```
auto a = 3;
auto b = 3.14;
auto c = std::string("hello, world");
```

You will notice that in each of the three usages of `auto` above, the line of code not only declared
a variable, but it initialized it with `= <something>` as well. This is required, and it is a good
thing. Un-initialized variables are a common source of program errors. By using `auto` we not only
offload a bit of congitive load to the compiler, but we avoid a common programming mistake.

## Brace Initialization

The examples above initialize variables using values on the right of an equals sign `=`. Modern C++
uses *brace initialization* which can omit the `=`. Examples:
```
auto a = uint32_t {3};
auto b {3.14f};  // b is a float because 3.14f is a float
auto c = std::string {"hello, world"};
```

The reasons modern C++ prefers brace initialization include:
- some forms of initialization can't be done with an equals sign
- the equals sign invites implicit type conversion

Implicit type conversion happens when the compiler has a value of one type, and it needs to assign
that to a variable which is a different type. For many such type conversions, the compiler has rules
that it follows to convert one type into another type. Implicit type conversion is generally thought
to be a problem, not an advantage, because
- It happens implicitly, behind the scenes. It is not obvious looking at the source code that a type
  conversion is happening
- Implicit type conversions are mysterious, and it is not uncommon for an unexpected conversion to
  happen.

Brace initialization never performs implicit type conversion.

Simple structs can be brace initialized, which elminates the need for constructors. Example:
```
struct Foo
{
    int a {0};
    double b {0.0};
};

auto foo = Foo {1, 1.0};
```

## Trailing Return Type

Modern C++ allows the return type of a function to be placed to the right of the function
declaration. The keyword `auto` makes another appearance here - like in variable declarations,
`auto` is used in the place where you would historically put the return type in C++old. Examples of
C++old function declarations:
```
int foo();
double bar();
std::vector<std::pair<std::string, int>> baz();
```
Examples of modern C++:
```
auto foo() -> int;
auto bar() -> double;
auto baz() -> std::vector<std::pair<std::string, int>>;
```

Reasons to use trailing return type syntax include:
- There are some forms of function declaration that must use trailing return type.
- For complicated types, this often makes the function name easier to read

## Class member initialization

In C++old, class members are always initialized in the class constructor. Modern C++ allows class
members to be initialized at the site of declaration. This is preferred for a couple of reasons:
- As with brace-initialization, it ensures that class members are always initialized.
- In classes that support multiple construction methods, it ensures consistent initialization.

An example of member initialization in a C++old class:
```
class Foo
{
public:
    Foo() { a = 1; b = 3.14; }
    Foo(int a) : a(a) {}
    static auto create() -> Foo {
        Foo f;
        f.a = 2;
        f.b = 3.14;
        return f;
    }
protected:
    int a;
    double b;
};
```
Notice that b is not always initialized. Notice that a is not consistenly initialized. By contrast,
here is how modern C++ initializes class members:
```
class Foo
{
public:
    Foo() = default;
    Foo(int a) : a(a) {}
    static auto create() -> Foo { return {}; }
protected:
    int a {1};
    double b {3.14};
};
```

There are several things to notice here. First, a and b are always initialized to a consistent value
no matter how a class instance is constructed. Second, becuase initialization is simplified, there
is no need for a custom default constructor so we ask the compiler to create a default one. Third,
in the static factory method `create()` we can simply return a default-initialized class instance
with `{}`. This syntax is useful to indicate "I want to return a default value". Because the
compiler knows the return type (`Foo`) the programmer need not even specify the type here. You could
explicitly say here
```
    static auto create() -> Foo { return Foo {}; }
```
but that is not necessary.
