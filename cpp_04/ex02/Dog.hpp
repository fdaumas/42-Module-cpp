
/* Copyright 2022 The fdaumas Athors*/

#ifndef CPP_04_EX00_DOG_HPP_
# define CPP_04_EX00_DOG_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

 public:

  Dog();
  Dog(const Dog &dog);
  ~Dog();
  Dog& operator = (const Dog &dog);
  virtual void makeSound() const;
  virtual std::string getType() const;
private:
  Brain *_brain;
};

#endif
