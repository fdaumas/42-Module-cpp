
/* Copyright 2022 The fdaumas Athors*/

#ifndef CPP_04_EX00_CAT_HPP_
# define CPP_04_EX00_CAT_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

 public:

  Cat();
  Cat(const Cat &cat);
  ~Cat();
  Cat& operator = (const Cat &cat);
  void makeSound() const;
  std::string getIdea(unsigned int index) const ;
  void setIdea(unsigned int index, std::string idea);
private:
  Brain *_brain;

};

#endif
