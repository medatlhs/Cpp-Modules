#include "childs.hpp"

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "of type: class A\n";
    } catch(...) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "of type: class B\n";
        } catch(...) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "of type: class C\n";
            } catch(...) { }
        }
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "of type: class A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "of type: class B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "of type: class C\n";
}

Base *generate(void) {
    std::srand(time(0));
    switch (std::rand()%3) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
        default: return nullptr;
    }
}

int main() {
    // Base *base = generate();

    // identify(base);
    // identify(*base);

    // delete base;

    Base *b = new A;

    return 0;
}

/*
🤓 When should you use dynamic_cast?
When you're working with inheritance
And need to check the real type at runtime
Like identifying which subclass you're working with (e.g. in a game engine, GUI system, etc.)
If you already know the type, don’t use dynamic_cast. Use static_cast.
*/

