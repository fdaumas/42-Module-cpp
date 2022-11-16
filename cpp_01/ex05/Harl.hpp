#include <iostream>

class Harl {
public:
	Harl(void);
	~Harl(void);

	void(Harl::*farr[4])(void);
	void complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};
