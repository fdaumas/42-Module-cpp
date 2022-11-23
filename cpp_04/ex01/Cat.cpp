
/* Copyright 2022 The fdaumas Athors*/
#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {

  std::cout << "Default constructor of Cat" << std::endl;
  this->type = "Cat";
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

  std::cout << "UwU" << std::endl;
}

std::string Cat::getIdea(unsigned int index) const {

  if (index > 99)
    return (NULL);
  return (_brain->idea[index]);
}

void Cat::setIdea(unsigned int index, std::string idea) {

  if (index > 99)
    return ;
  _brain->idea[index] = idea;
}
