
/* Copyright 2022 The fdaumas Athors*/

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

  std::cout << "Default contructor WrongAnimal" << std::endl;
  this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {

  std::cout << "Copy constructor WrongAnimal" << std::endl;
  *this = animal;
}

WrongAnimal::~WrongAnimal() {

  std::cout << "Destrucor WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {

  if (this == &animal)
    return (*this);
  std::cout << "Copy assignememt operator of Wronganimal called" << std::endl;
  this->type = animal.type;
  return (*this);
}

void WrongAnimal::makeSound() const{

  std::cout << "wrong WrongAnimal" <<std::endl;
}

std::string WrongAnimal::getType() const {

  return (type);
}
