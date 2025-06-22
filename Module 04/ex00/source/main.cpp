#include "../Inc/Animal.hpp"
#include "../Inc/Cat.hpp"
#include "../Inc/Dog.hpp"
#include "../Inc/WrongAnimal.hpp"
#include "../Inc/WrongCat.hpp"

int main()
{
    std::cout << "Creating Base Animal : \n";
    const Animal* animal_1 = new Animal;
    std::cout << "Animal -> type: " << animal_1->getType() << std::endl;
    animal_1->makeSound();
    delete animal_1;

    std::cout << "\nCreating Cat via Animal pointer :\n";
    const Animal* animal_2 = new Cat;
    std::cout << "Cat -> type: " << animal_2->getType() << std::endl;
    animal_2->makeSound();
    delete animal_2;

    std::cout << "\nCreating Dog via Animal pointer :\n";
    const Animal* animal_3 = new Dog;
    std::cout << "Dog -> type: " << animal_3->getType() << std::endl;
    animal_3->makeSound();
    delete animal_3;

    std::cout << "\nCreating Base WrongAnimal :\n";
    const WrongAnimal* animal_4 = new WrongAnimal;
    std::cout << "WrongAnimal -> type: " << animal_4->getType() << std::endl;
    animal_4->makeSound();
    delete animal_4;

    std::cout << "\nCreating WrongCat via WrongAnimal pointer :\n";
    const WrongAnimal* animal_5 = new WrongCat;
    std::cout << "WrongCat -> type: " << animal_5->getType() << std::endl;
    animal_5->makeSound();
    delete animal_5;

    return 0;
}
