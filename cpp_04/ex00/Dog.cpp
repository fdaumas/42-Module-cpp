/* Copyright 2022 The fdaumas Athors*/
#include "Dog.hpp"

Dog::Dog() : Animal() {

  std::cout << "Default constructor of Dog" << std::endl;
  this->type = "Dog";
}

Dog::Dog(const Dog &dog) {

  std::cout << "Copy constructor dog" << std::endl;
  *this = dog;
}

Dog::~Dog() {

  std::cout << "Destructor Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {

  if (this == &dog)
    return (*this);
  std::cout << "Copy assignememt operator of dog called" << std::endl;
  this->type = dog.type;
  return (*this);
}

void Dog::makeSound() const {

  std::cout << "Bark Bark" << std::endl;
}
