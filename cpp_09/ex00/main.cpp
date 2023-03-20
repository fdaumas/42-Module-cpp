#include <iostream>
#include <algorithm>
#include <ostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

bool error(std::string & line) {
	std::cout << "Error: bad input => " << line << std::endl;
	return false;
}

bool verif_line(std::string & line) {
	int index = 0, verif = 0;
	while (index < 4) {
		if (line[index] < '0' || line[index] > '9')
			return error(line);
		++index;
	}

	if (line[index] != '-')
		return error(line);
	++index;

	while (index < 7) {
		if (line[index] < '0' || line[index] > '9')
			return error(line);
		verif = verif * 10 + line[index] - '0';
		++index;
	}
	if (verif > 12)
			return error(line);
	verif = 0;

	if (line[index] != '-')
		return error(line);
	++index;

	while (index < 10) {
		if (line[index] < '0' || line[index] > '9')
			return error(line);
		verif = verif * 10 + line[index] - '0';
		++index;
	}
	if (verif > 31)
			return error(line);
	verif = 0;

	if (line[index] != ' ')
		return error(line);
	++index;
	
	if (line[index] != '|')
		return error(line);
	++index;
	
	if (line[index] != ' ')
		return error(line);
	++index;
	
	double multiplier = atof(line.substr(13).c_str());
	if (multiplier > 1000) {
		std::cout << "Error: too large number" << std::endl; 
		return false;
	}
	if (multiplier < 0) {
		std::cout << "Error: not a positive number" << std::endl; 
		return false;
	}
	while (line[index] >= '0' && line[index] <='9')
		index++;
	while(line[index] != '\0')
	{
		if (line[index] == ' ')
			index++;
		else 
			return error(line);
	}
	return true;
}

int main (int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Bad arguments" << std::endl;
		return 1;
	}
	std::ifstream infile_data("data.csv");
	if (infile_data.fail())
	{
		std::cerr << "Failed to access " << "data.csv" << std::endl;
		return 1;
	}
	std::string line, date;
	std::getline(infile_data, line);
	
	std::map<int, double> btc_price;
	while (std::getline(infile_data, line)) {
		date = line.substr(0, 10);
		date.erase(std::find(date.begin(), date.end(), '-'));
		date.erase(std::find(date.begin(), date.end(), '-'));
		btc_price.insert(std::pair<int, double>(atoi(date.c_str()), atof(line.substr(11).c_str())));
	}
	infile_data.close();

	std::ifstream infile_input(argv[1]);
	if (infile_input.fail())
	{
		std::cerr << "Failed to access " << argv[1] << std::endl;
		return 1;
	}

	std::getline(infile_input, line);
	int research, multiplier;
	while (std::getline(infile_input, line)) {
		if (!verif_line(line))
			continue ;
		multiplier = atof(line.substr(13).c_str());
		date = line.substr(0, 10);
		date.erase(std::find(date.begin(), date.end(), '-'));
		date.erase(std::find(date.begin(), date.end(), '-'));
		research = atoi(date.c_str());
		std::map<int, double>::iterator it = btc_price.begin();
			while (it != btc_price.end() && it->first < research)
				++it;
			if (it == btc_price.begin()) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue ;
			}
			if (it->first  == research) {
				std::cout << line.substr(0,10)  << " => " << multiplier << " = " << it->second * multiplier <<std::endl;
			}
			else {
				--it;
				std::cout << line.substr(0,10)  << " => " << multiplier << " = " << it->second * multiplier <<std::endl;
			}
	}
	return 0;
}
