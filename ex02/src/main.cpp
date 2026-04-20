/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:59:32 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 22:57:52 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

namespace
{
#define MAX_VAL 750

bool testsProjectMain()
{
	std::cout << "#### TESTS BASED ON MAIN FROM PROJECT PAGE\n\n"
			  << "  creating two <int> arrays for " << MAX_VAL << " elements\n";
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	std::cout << "  filling both arrays with (same) random numbers\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		std::cout << "  testing copy operator with new arrays in separate scope\n";
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << "  checking if both original arrays have same values stored\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (false);
		}
	}
	std::cout << "  accessing array with negative index (implicit cast!)\n";
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "  accessing array with MAX_VALUE (out of bounds by one)\n";
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "  some prints from BOTH arrays, must be same:"
			  << "\n0:\t" << numbers[0] << " | " << mirror[0]
			  << "\n231:\t" << numbers[231] << " | " << mirror[231]
			  << "\n584:\t" << numbers[584] << " | " << mirror[584] << std::endl;
	std::cout << "  overwriting content of one array\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "  some prints from BOTH arrays, must be different now:"
			  << "\n0:\t" << numbers[0] << " | " << mirror[0]
			  << "\n231:\t" << numbers[231] << " | " << mirror[231]
			  << "\n584:\t" << numbers[584] << " | " << mirror[584] << std::endl;
	delete[] mirror;
	return (true);
}

void testsConstruction()
{
	std::cout << "\n#### TESTING CONSTRUCTION\n\n";
	Array<std::string> one;
	std::cout << sizeof(one) << std::endl;
	try
	{
		one[0];
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "[0] but array is empty\n"
				  << "error: " << e.what() << std::endl;
	}
	try
	{
		one[-1];
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "[-1] implicit conversion to number greater size\n"
				  << "error: " << e.what() << std::endl;
	}
	unsigned int valPos = 1234567890;
	try
	{
		Array<int> two(valPos);
		std::cout << "test size " << valPos << ": all good" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "size " << valPos << ": " << e.what() << std::endl;
	}
	int val = -123456789;
	try
	{
		Array<int> two(val);
		std::cout << "test size " << val << ": all good" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "size " << val << ": " << e.what() << std::endl;
	}
	Array<char> three(23);
	Array<double> four(99);
}

} // namespace

int main()
{
	// int * a= new int();
	// std::string *str = new std::string();
	// std::cout << "a: " << *a << " | str: " << *str << '\n';
	if (!testsProjectMain())
		return (1);
	testsConstruction();
	return (0);
}
