#include "childs.hpp"

void identify(Base& p) {
    try {
        A &derivedA = dynamic_cast<A&>(p);
        std::cout << "Of Type: Class A\n";
        (void)derivedA;
    } catch(...) {
        try {
            B &derivedB = dynamic_cast<B&>(p);
            std::cout << "Of Type: Class B\n";
            (void)derivedB;
        } catch(...) {
            try {
                C &derivedC = dynamic_cast<C&>(p);
                std::cout << "Of Type: Class C\n";
                (void)derivedC;
            } catch(...) {
                std::cout << "Of Type: Unknown\n";
            }
        }
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Of Type: Class A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Of Type: Class B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Of Type: Class C\n";
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
    Base *base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}

/*
🤓 When should you use dynamic_cast?
When you're working with inheritance
And need to check the real type at runtime
Like identifying which subclass you're working with (e.g. in a game engine, GUI system, etc.)
If you already know the type, don’t use dynamic_cast. Use static_cast.
*/

