
/* Copyright 2022 The fdaumas Athors*/

#ifndef CPP_04_EX00_DOG_HPP_
# define CPP_04_EX00_DOG_HPP_
#include "Animal.hpp"

class Dog : public Animal {

 public:

  Dog();
  Dog(const Dog &dog);
  ~Dog();
  Dog& operator = (const Dog &dog);
  void makeSound() const;

};

#endif
