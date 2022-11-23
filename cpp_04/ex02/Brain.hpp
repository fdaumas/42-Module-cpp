#ifndef _BRAIN_H_
# define _BRAIN_H_

#include <iostream>

class Brain {
public:
  Brain();
  Brain(const Brain& brain);
  ~Brain();
  Brain& operator = (const Brain& brain);
  void setIdea();
  std::string getIdea(unsigned int index) const;
private:
  std::string _idea[100];
};

#endif