#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{

  const Animal* j = new Dog();
  std::cout << std::endl;
  const Animal* i = new Cat();
  std::cout << "-_-_-" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << "-_-_-" << std::endl;
  i->makeSound();
  std::cout << std::endl;
  j->makeSound();
  std::cout << "-_-_-" << std::endl;
  delete i;
  std::cout << "-_-_-" << std::endl;
  delete j;
  Dog* lol = new Dog[25];

  for (int i = 0; i < 25; i++) {
    lol[i].makeSound();
    lol[i].setIdea(0, "IM HANGRY AS FUCK");
  }
  std::cout << lol[16].getIdea(0) << std::endl;

  std::cout << "-_-_-" << std::endl;
  Dog* cp = new Dog(lol[19]);
  std::cout << "-_-_-" << std::endl;
  delete [] lol;
  std::cout << "-_-_-" << std::endl;
  std::cout << cp->getIdea(0) << std::endl;
  std::cout << "-_-_-" << std::endl;
  delete cp;
  return 0;
}
