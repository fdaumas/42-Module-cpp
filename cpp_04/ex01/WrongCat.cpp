
/* Copyright 2022 The fdaumas Athors*/
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {

  std::cout << "Default constructor of WrongCat" << std::endl;
  this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &cat) {

  std::cout << "Copy constructor WrongCat" << std::endl;
  *this = cat;
}

WrongCat::~WrongCat() {

  std::cout << "Destructor WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {

  if (this == &cat)
    return (*this);
  std::cout << "Copy assignememt operator of Wrongcat called" << std::endl;
  this->type = cat.type;
  return (*this);
}

void WrongCat::makeSound() const{

  std::cout << "Wrong UwU" << std::endl;
}