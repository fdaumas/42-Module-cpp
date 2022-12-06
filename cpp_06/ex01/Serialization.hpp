#ifndef _SERIALIZATION_H_
# define _SERIALIZATION_H_

# include "Data.hpp"
# include <iostream>
# include <stdint.h>

uintptr_t   serialize(Data *ptr);
Data*       deserialize(uintptr_t raw);

#endif