#include "Array.hpp"

int main () {
	Array<int> * array = new Array<int>(50);
	Array<int> * array_cp = new Array<int>();
	array_cp->test();
	array_cp = array;
	array_cp->test();
	delete array_cp;
	delete array;
}