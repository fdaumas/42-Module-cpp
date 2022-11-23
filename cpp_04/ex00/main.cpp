#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{

  const Animal* meta = new Animal();
  std::cout << "-_-_-" << std::endl;
  const Animal* j = new Dog();
  std::cout << "-_-_-" << std::endl;
  const Animal* i = new Cat();
  std::cout << "-_-_-" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << "-_-_-" << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << "-_-_-" << std::endl;
  i->makeSound();
  std::cout << "-_-_-" << std::endl;
  j->makeSound();
  std::cout << "-_-_-" << std::endl;
  meta->makeSound();
  std::cout << "-_-_-" << std::endl;
  delete meta;
  std::cout << "-_-_-" << std::endl;
  delete i;
  std::cout << "-_-_-" << std::endl;
  delete j;
  std::cout << "-_Wrong_-" << std::endl;
  const WrongAnimal* wrong = new WrongCat();
  wrong->makeSound();
  delete wrong;
  return 0;
}