#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
  std::srand(std::time(nullptr));
  Animal* lol[6];
  std::cout << "-_-_-" << std::endl;
  for (int i = 0; i < 3; i++) {
    lol[i] = new Dog();
  }
  std::cout << "-_-_-" << std::endl;
  for (int i = 0; i < 3; i++) {
    lol[i + 3] = new Cat();
  }
  std::cout << "-_-_-" << std::endl;
  lol[0]->makeSound();
  lol[3]->makeSound();
  std::cout << "-_-_-" << std::endl;
  for (int i = 0; i < 6; ++i) {
    delete lol[i];
  }
  std::cout << "-_-_-" << std::endl;
  Cat *litleKity = new Cat();
  std::cout << "-_-_-" << std::endl;
  Cat *copy_litleKity = new Cat(*litleKity);
  std::cout << "-_-_-" << std::endl;
  litleKity->makeSound();
  copy_litleKity->makeSound();
  std::cout << "-_-_-" << std::endl;
  delete litleKity;
  std::cout << "-_-_-" << std::endl;
  delete copy_litleKity;
  return 0;
}
