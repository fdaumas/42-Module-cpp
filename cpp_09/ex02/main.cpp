#include <algorithm>
#include <bits/types/clock_t.h>
#include <iomanip>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iterator>
#include <list>
#include <ostream>
#include <vector>
#include <iostream>

bool issorted(std::list<int> & list1)
{
	bool result = true;
	std::list<int>::iterator it = list1.begin();
	it++;
	for (std::list<int>::iterator it1 = list1.begin(); it != list1.end(); ++it, ++it1)
	{
		if (*it1 > *it)
			result = false;
	}
	return result;
}

std::list<int> list_sort(std::list<int> list_base)
{
	if (list_base.size() <= 1)
		return list_base;
	std::list<int>::iterator it = list_base.begin();
	std::advance(it, list_base.size() / 2);
	std::list<int> list1;
	list1.splice(list1.begin(), list_base, list_base.begin(), it);
	std::list<int> list2;
	list2.splice(list2.begin(), list_base, list_base.begin(), list_base.end());
	std::list<int> sorted1;
	std::list<int> sorted2;
	sorted1 = list_sort(list1);
	sorted2 = list_sort(list2);
	sorted1.merge(sorted2);
	return sorted1;
}

void vector_splice(std::vector<int> & vector1, std::vector<int> & vector2, std::vector<int>::iterator it_start, std::vector<int>::iterator it_end)
{
	vector1.insert(vector1.begin(), it_start, it_end);
	vector2.erase(it_start, it_end);
}

void vector_merge(std::vector<int> & vector1, std::vector<int> & vector2)
{
	std::vector<int>::iterator it_vector1 = vector1.begin();
	std::vector<int>::iterator it_vector2 = vector2.begin();
	for (;it_vector2 != vector2.end(); ++it_vector2)
	{
		while(it_vector1 != vector1.end() && *it_vector1 < *it_vector2)
			++it_vector1;
		vector1.insert(it_vector1, *it_vector2);
		it_vector1 = vector1.begin();
	}
}

std::vector<int> vector_sort(std::vector<int> vector_base)
{
	if (vector_base.size() <= 1)
		return vector_base;
	std::vector<int>::iterator it = vector_base.begin();
	std::advance(it, vector_base.size() / 2);
	std::vector<int> vector1;
	vector_splice(vector1, vector_base, vector_base.begin(), it);
	std::vector<int> vector2;
	vector_splice(vector2, vector_base, vector_base.begin(), vector_base.end());
	std::vector<int> sorted1;
	std::vector<int> sorted2;
	sorted1 = vector_sort(vector1);
	sorted2 = vector_sort(vector2);
	vector_merge(sorted1, sorted2);
	return sorted1;
}

int main (int argc, char *argv[])
{
	clock_t start, end;
	std::list<int> list1;
	for (int index = 1; index < argc; ++index)
	{
		std::list<int>::iterator it = std::find(list1.begin(), list1.end(), atoi(argv[index]));
		if (it != list1.end())
		{
			std::cout << "Error: doublon" << std::endl;
			return 1;
		}
		list1.push_back(atoi(argv[index]));
	}
	if (issorted(list1))
	{
		std::cout << "already sort" << std::endl;
		return 0;
	}
	start = clock();
	std::list<int> result = list_sort(list1);
	end = clock();
	std::cout << "before:  ";
	for (std::list<int>::iterator it = list1.begin(); it !=list1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << "After:   ";
	for (std::list<int>::iterator it = result.begin(); it !=result.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << result.size() 
		<< " elements with std::list<int> : " << ((float)(end - start)*0.000001)
		<< "us" << std::endl;
	std::vector<int> vector1;
	for (int index = 1; index < argc; ++index)
		vector1.push_back(atoi(argv[index]));
	std::vector<int> result_vector;
	start = clock();
	result_vector = vector_sort(vector1);
	end = clock();
	std::cout << "Time to process a range of " << result_vector.size() 
		<< " elements with std::vector<int> : " << ((float)(end - start)*0.000001)
		<< "us" << std::endl;
	// for (std::vector<int>::iterator it = result_vector.begin(); it != result_vector.end() ; ++it)
	// 	std::cout << *it << " ";
	return 0;
}
