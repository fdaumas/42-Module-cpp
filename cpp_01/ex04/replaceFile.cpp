#include "replaceFile.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>

replaceFile::replaceFile(char *path, std::string s1, std::string s2) {
	this->_s1 = s1;
	this->_s2 = s2;
	FILE* fd = std::fopen(path, "r");
	if(!fd) {
		std::perror("File opening failed");
		std::exit (EXIT_FAILURE);
	}
	set_old_string(fd);
	std::fclose(fd);
}

replaceFile::~replaceFile() {
}

bool replaceFile::ft_strncmp(std::string src, std::string s1, int len) {
	int index = 0;

	while (src[index] && index < len) {
		if (src[index] != s1[index])
			return (false);
		index++;
	}
	if (s1[index])
		return (false);
	return (true);
}

void replaceFile::old_to_new(int len) {
	int index = 0;
	char c[2];

	c[1] = '\0';
	while (this->_old_string[index]) {
		if (ft_strncmp(&this->_old_string[index], this->_s1, len)) {
			this->_new_string.append(this->_s2);
			index += len;
		}
		else {
			c[0] = this->_old_string[index];
			this->_new_string.append(c);
			index++;
		}
	}
}

void replaceFile::new_to_file(char *path) {
	FILE* fd = std::fopen(std::strcat(path, ".replace"), "w");

	if(!fd) {
		std::perror("File opening failed");
		std::exit (EXIT_FAILURE);
	}

	int index = 0;
	while (this->_new_string[index]) {
		std::fputc(this->_new_string[index], fd);
		index++;
	}
	std::fclose(fd);
}

void replaceFile::set_old_string(FILE *fd) {
	char c[2];

	c[1] = '\0';
	while ((c[0] = (std::fgetc(fd))) != EOF) {
		this->_old_string.append(c);
	}
	this->_old_string.append("\0");
	if (std::ferror(fd)) {
		std::cout << "error when reading" << std::endl;
		std::exit (1);
	}
}

std::string replaceFile::get_old_string(void) const {return (this->_old_string);};

std::string replaceFile::get_new_string(void) const {return (this->_new_string);};
