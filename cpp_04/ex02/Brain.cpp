#include "Brain.hpp"

Brain::Brain() {

  this->setIdea();
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
    this->_idea[i] = brain._idea[i];
  return (*this);
}

void Brain::setIdea() {
  std::string ideaBase[] = {"food", "play", "sleep", "cuddle", "run", "go out"};
  int random = std::rand() % 6;
  for (int i = 0; i < 100; i++) {
    _idea[i] = ideaBase[random];
    random = std::rand() % 6;
  }
}

std::string Brain::getIdea(unsigned int index) const {
  return (_idea[index]);
}