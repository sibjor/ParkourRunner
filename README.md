# ParkourRunner

## Important 

- [Exporting with emscripten](https://wiki.libsdl.org/SDL3/README/emscripten)
- [SDL GPU API](https://wiki.libsdl.org/SDL3/CategoryGPU)
- [clock_t C++](https://en.cppreference.com/w/c/chrono/clock_t)
- [SDL_GetTicks](https://wiki.libsdl.org/SDL3/SDL_GetTicks)


## Strategy

- All objects derives from "Root" class, defined in "central.hpp"
- Objects are placed inside vectors for grouped benefits
- A vector of objects can easily be cleaned or updated etc...
- "enum classes" contain integers used for categorizing contexts. 
    Such integers should activate or remove certian context.
    Preferably, "switch cases" are used for steering such content
- The "Color" enum class should store hexadecimal values of respective color.
- A classic "gameloop" is avoided because of web compability, read: [emscripten](#important)
- 

## Stuff I've learnt:


```cpp
// Avoid double deletion by setting pointers to nullptr after deletion.
// This ensures that delete nullptr is a no-op and prevents undefined behavior.
delete obj;
obj = nullptr;

// Use smart pointers like std::unique_ptr or std::shared_ptr to manage memory
// automatically and avoid manual delete calls.
#include <memory>
std::unique_ptr<Example> smartObj = std::make_unique<Example>();

// Prefer stack allocation over heap allocation when possible.
// Stack allocation is faster and automatically managed.
Example stackObj;

// Always ensure destructors in base classes are virtual if polymorphism is used.
// This ensures derived class destructors are called properly.
class Base {
public:
    virtual ~Base() {
        // Base class cleanup
    }
};

class Derived : public Base {
public:
    ~Derived() {
        // Derived class cleanup
    }
};

// Example of polymorphism with proper destructor handling
Base* basePtr = new Derived();
delete basePtr; // Calls both Derived::~Derived() and Base::~Base()


// Only accessable in their scope
// You must qualify the enumerator with the enum class name to use it.
// No implicit conversion
// Strongly typed
// unlike enum (int), you can use other types
enum class Color {
    Red,
    Green,
    Blue
};
Color c = Color::Red; 

```