#include <iostream>
#include <map>

class Harl {
public:
	Harl(void);
	~Harl(void);

	void complain(std::string level);
	void put_bad_level(void);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};