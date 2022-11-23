
/* Copyright 2022 The fdaumas Athors*/
#include "Cat.hpp"

Cat::Cat() : Animal() {

  std::cout << "Default constructor of Cat" << std::endl;
  this->type = "Cat";
}

Cat::Cat(const Cat &cat) {

  std::cout << "Copy constructor Cat" << std::endl;
  *this = cat;
}

Cat::~Cat() {

  std::cout << "Destructor Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {

  if (this == &cat)
    return (*this);
  std::cout << "Copy assignememt operator of cat called" << std::endl;
  this->type = cat.type;
  return (*this);
}

void Cat::makeSound() const{

  std::cout << "UwU" << std::endl;
}