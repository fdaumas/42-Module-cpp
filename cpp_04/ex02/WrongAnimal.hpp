
/* Copyright 2022 The fdaumas Athors*/

#ifndef CPP_04_EX00_WRONGANIMAL_HPP_
# define CPP_04_EX00_WRONGANIMAL_HPP_

#include <iostream>
#include <string>

class WrongAnimal {

 public:

  WrongAnimal();
  WrongAnimal(const WrongAnimal &animal);
  ~WrongAnimal();
  WrongAnimal& operator = (const WrongAnimal &animal);
  void makeSound() const;
  std::string getType() const;

 protected:

  std::string type;

};

#endif
