
/* Copyright 2022 The fdaumas Athors*/

#include "Animal.hpp"

Animal::Animal() {

  std::cout << "Default contructor Animal" << std::endl;
  this->type = "";
}

Animal::Animal(const Animal &animal) {

  std::cout << "Copy constructor Animal" << std::endl;
  *this = animal;
}

Animal::~Animal() {

  std::cout << "Destrucor Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {

  if (this == &animal)
    return (*this);
  std::cout << "Copy assignememt operator of animal called" << std::endl;
  this->type = animal.type;
  return (*this);
}

void Animal::makeSound() const{

  std::cout << "wrong Animal" <<std::endl;
}

std::string Animal::getType() const {

  return (type);
}
