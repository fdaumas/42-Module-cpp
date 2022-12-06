#ifndef _BASE_H_
# define _BASE_H_

class Base {
	public:
		virtual ~Base() {}
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif