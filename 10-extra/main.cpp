#include <cstdint>
#include <iostream>
#include <vector>

struct Rectangle
{
    double x {0.0};  // <- this is the modern initialization syntax
    double y = 0.0;  // <- older initialization syntax, but still valid
    double width {}; // <- {} means "default initialize", which is 0.0 for double
    double height = 0;

    // Stick to the rule of zero (no constructor, destructor, assignment, or copy operators, move
    // constructor, move assignment) if you can. No need for these, here, because this is just a
    // simple data struct:

    // Rectangle() {}
    // ~Rectangle() {}
    // Rectangle(const Rectangle& rhs) {}
    // Rectangle(const Rectangle&& rhs) {}
    // Rectangle& operator=(const Rectangle& rhs) { return *this; }
    // Rectangle& operator=(const Rectangle&& rhs) { return *this; }
};

// a "function template" is how generic programming is done in c++, here with a generic type T. To
// use this struct, you must specify T (well, there are some situations where the compiler can infer
// it).

template <typename T>
struct Vector
{
    T* ptr {nullptr};
    size_t size {0};
};

void create_some_vectors_for_no_reason()
{
    auto v1 = Vector<int> {};    // Creates a default-constructed Vector of type int
    auto v2 = Vector<double> {}; // Creates a default-constructed Vector of type double
}

// Stupid function that creates a reference.

auto foo(std::vector<Rectangle>& data) -> std::vector<Rectangle>&
{
    return data;
}

auto create_data() -> std::vector<Rectangle> 
{
    // When creating an object inside a function, return that object by value. This is simple to
    // program, and is also the fastest / most efficient approach. The compiler detects this
    // situation and eliminates the copy that would normally happen when returning a value from a
    // function (this is called "return value optimization" or RVO).

    auto data  = std::vector<Rectangle> {{}}; // create a vector with one (default) item
    auto data2 = std::vector<Rectangle>(3);
    auto data3 = std::vector<int> {3, 4, 5};
    auto data4 = std::vector<Rectangle> {}; // create an empty vector
    auto ptr   = &data;                     // ptr is a pointer
    auto copy  = data;                      // copy is a value (a copy of data)
    auto copy2 = foo(data);                 // copy2 is also a copy (not a reference)!

    data.resize(17);
    data[10].width = 4.0;
    data[10] = Rectangle {1.0, 2.0, 3.0, 4.0};

    data2[2].width = 4.0;
    data2.push_back(Rectangle {1.0, 2.0, 3.0, 4.0});
    data2.push_back(Rectangle {});
    data2.push_back({});
    std::cout << "data2.size() = " << data2.size() << std::endl;

    return data; // returns by value <- this is very efficient in C++, even if data is large (RVO)
}

void copy_data(std::vector<Rectangle>& recipient, std::vector<Rectangle>& donor)
{
    recipient = donor;
}

void move_data(std::vector<Rectangle>& recipient, std::vector<Rectangle>&& donor)
{
    recipient = std::move(donor);
}

// This could have been:
//   void do_something(std::vector<Rectangle>* data)
//   void do_something(std::vector<Rectangle> data)
// but prefer to pass heavyweight objects by reference (&) when you can.

void do_something(std::vector<Rectangle>& data)
{
    data.clear();
    std::cout << "data size: " << data.size() << std::endl;
    // ...
}

int main()
{
    Rectangle r;
    Rectangle r2(r);
    Rectangle r3 = r;
    auto data = create_data(); // auto means data has whatever type create_data() returns
    std::cout << "data size: " << data.size() << std::endl;
    do_something(data);
    std::cout << "data size: " << data.size() << std::endl;
    do_something(data);
}

