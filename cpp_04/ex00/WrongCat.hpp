
/* Copyright 2022 The fdaumas Athors*/

#ifndef CPP_04_EX00_WRONGCAT_HPP_
# define CPP_04_EX00_WRONGCAT_HPP_
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

 public:

  WrongCat();
  WrongCat(const WrongCat &cat);
  ~WrongCat();
  WrongCat& operator = (const WrongCat &cat);
  void makeSound() const;

};

#endif
