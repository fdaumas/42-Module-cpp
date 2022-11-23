#include "Brain.hpp"

Brain::Brain() {

  std::cout << "Constructor Default Brain" << std::endl;
}

Brain::Brain(const Brain &brain) {

  std::cout << "Constructor copy Brain" << std::endl;
  *this = brain;
}

Brain::~Brain() {

  std::cout << "Destructor Brain" << std::endl;
}

Brain& Brain::operator = (const Brain& brain) {
  if (this == &brain)
    return (*this);
  for (int i = 0; i < 100; i++)
    this->idea[i] = brain.idea[i];
  return (*this);
}