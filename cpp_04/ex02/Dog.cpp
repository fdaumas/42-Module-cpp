/* Copyright 2022 The fdaumas Athors*/
#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain) {

  std::cout << "Default constructor of Dog" << std::endl;
  this->type = "Dog";
}

Dog::Dog(const Dog &dog) {

  std::cout << "Copy constructor dog" << std::endl;
  *this = dog;
}

Dog::~Dog() {

  delete this->_brain;
  std::cout << "Destructor Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {

  if (this == &dog)
    return (*this);
  std::cout << "Copy assignememt operator of dog called" << std::endl;
  this->type = dog.type;
  this->_brain = new Brain(*dog._brain);
  return (*this);
}

void Dog::makeSound() const {

  std::cout << "Bark Bark i want " << _brain->getIdea(0) << std::endl;
}

std::string Dog::getType() const {
  return this->type;
}
