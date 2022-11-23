
/* Copyright 2022 The fdaumas Athors*/

#ifndef CPP_04_EX00_ANIMAL_HPP_
# define CPP_04_EX00_ANIMAL_HPP_

#include <iostream>
#include <string>

class Animal {

 public:

  Animal();
  Animal(const Animal &animal);
  virtual ~Animal();
  Animal& operator = (const Animal &animal);
  virtual void makeSound() const;
  std::string getType() const;

 protected:

  std::string type;

};

#endif
