#include "../Inc/Animal.hpp"
#include "../Inc/Cat.hpp"
#include "../Inc/Dog.hpp"
#include "../Inc/WrongAnimal.hpp"
#include "../Inc/WrongCat.hpp"
#include "../Inc/Brain.hpp"

int main()
{
    const int size = 4;
    Animal *animals[size];

    std::cout << "\nfilling the array:\n\n";
    for (int i = 0; i < size; i++) {
        if (i < size/2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    std::cout << "\ntesting makeSound:\n\n";
    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\ntesting deep copy:\n\n";  ////
    Cat cat_a;
    cat_a.setBrainIdea(0, "waah chi frmaja daba\n");
    std::cout << "cat_a idea: " << cat_a.getBrainIdea(0);
    Cat cat_b(cat_a);
    std::cout << "cat_b idea copied: " << cat_b.getBrainIdea(0);
    cat_b.setBrainIdea(0, "aa dryat jayat ndir fiha cute\n");
    std::cout << "cat_b idea new: " << cat_b.getBrainIdea(0);
    std::cout << "cat_a idea: " << cat_a.getBrainIdea(0);


    std::cout << "\ndestructor logs:\n\n";
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}

