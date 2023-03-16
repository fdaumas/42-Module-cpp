#include <iostream>
#include <algorithm>
#include <ostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

int main (int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Bad arguments" << std::endl;
	}
	(void)argv;
	std::ifstream infile("data.csv");
	std::string line, date;
	std::getline(infile, line);
	
	std::map<int, double> btc_price;
	while (std::getline(infile, line)) {
		date = line.substr(0, 10);
		date.erase(std::find(date.begin(), date.end(), '-'));
		date.erase(std::find(date.begin(), date.end(), '-'));
		btc_price.insert(std::pair<int, double>(atoi(date.c_str()), atof(line.substr(11).c_str())));
	}
	std::cout << std::fixed << std::setprecision(5);
	for (std::map<int, double>::iterator it = btc_price.begin(); it != btc_price.end(); ++it)
		std::cout << "key = " << it->first << " value = " << it->second <<std::endl;
	return 0;
}
