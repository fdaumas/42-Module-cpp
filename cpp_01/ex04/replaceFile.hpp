#include <iostream>

class replaceFile {
private:
	std::string _old_string;
	std::string _new_string;
	std::string _s1;
	std::string _s2;
public:
	replaceFile(char *path, std::string s1, std::string s2);
	~replaceFile(void);
	void set_old_string(FILE* fd);
	bool ft_strncmp(std::string src, std::string s1, int len);
	void old_to_new(int len);
	void new_to_file(char *path);
	std::string get_old_string(void) const;
	std::string get_new_string(void) const;

};