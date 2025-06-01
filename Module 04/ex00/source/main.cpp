#include "../Inc/Animal.hpp"
#include "../Inc/Cat.hpp"
#include "../Inc/Dog.hpp"

// int main(int argc, char const *argv[])
// {
//     const Animal *animal = new Cat;
//     animal->makeSound();
//     delete animal;
    
//     // Cat zoro;
//     // zoro.makeSound();

//     Dog riko;
//     riko.makeSound();

//     return 0;
// }

int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // // std::cout << j->getType() << " " << std::endl;
    // // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); // will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // delete meta;
    delete j;
    // delete i;
    return 0;
}




/*
when we inherit from a base class the child class gets the base class 
members and when we use a base class pointer to the child class that
pointer is only pointing to he is part (base),
so if we wanna access child class members we need to mark virtual
to the methods in base class that we wanna override.

* const pointer can't access none const methods


*/