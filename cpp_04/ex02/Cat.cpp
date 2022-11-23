
/* Copyright 2022 The fdaumas Athors*/
#include "Cat.hpp"

Cat::Cat() : Animal() {

  std::cout << "Default constructor of Cat" << std::endl;
  this->type = "Cat";
  this->_brain = new Brain();
}

Cat::Cat(const Cat &cat) {

  std::cout << "Copy constructor Cat" << std::endl;
  *this = cat;
}

Cat::~Cat() {

  delete this->_brain;
  std::cout << "Destructor Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {

  if (this == &cat)
    return (*this);
  std::cout << "Copy assignememt operator of cat called" << std::endl;
  this->type = cat.type;
  this->_brain = new Brain(*cat._brain);
  return (*this);
}

void Cat::makeSound() const{

  std::cout << "UwU i want " << _brain->getIdea(0) << std::endl;
}

std::string Cat::getType() const {
  return this->type;
}