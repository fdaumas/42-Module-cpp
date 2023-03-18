#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
int main( int ac, char *av[] )   {

    std::size_t found;
    std::string line;
    std::string str;
	std::string first_arg;
	std::string filename = first_arg + ".replace";

    if ( ac != 4 )    {

        std::cout << "You must launch the program like this : < ./sed file s1 s2 >" << std::endl;
        return 1;
    }
    if ( strlen( av[2] ) == 0 )    {

        std::cout << "You cannot have empty str1" << std::endl;
        return 1;
    }
    std::ifstream myFile ( av[1] );
    if ( !myFile.is_open() )  {

        std::cout << "Can't open file " << av[1] << std::endl;
        return 1;
    }
    else   {

        while ( std::getline( myFile, line ) )  {

            str.append( line + '\n' );
        }
    }
    found = str.find( av[2] );
    while ( found != std::string::npos )   {

        str.erase( found, strlen( av[2] ) );
        str.insert( found, av[3] );
        found = str.find( av[2], found + 1,  strlen( av[2] ) );
    }
    myFile.close();
	std::ofstream out(filename.c_str());
    if (!out.is_open()) {

        std::cout << "Can't open file" << av[1] << ".replace" << std::endl;
        return 1;
    }
    else    {
        out << str;
    }
    out.close();
    return 0;
}
