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

  std::cout << "Bark Bark" << std::endl;
}

std::string Dog::getIdea(unsigned int index) const {

  if (index > 99)
    return (NULL);
  return (_brain->idea[index]);
}

void Dog::setIdea(unsigned int index, std::string idea) {

  if (index > 99)
    return ;
  _brain->idea[index] = idea;
}