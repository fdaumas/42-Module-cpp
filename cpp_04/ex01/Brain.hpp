#ifndef _BRAIN_H_
# define _BRAIN_H_

#include <iostream>

class Brain {
public:
  Brain();
  Brain(const Brain& brain);
  ~Brain();
  Brain& operator = (const Brain& brain);
  std::string idea[100];
};

#endif