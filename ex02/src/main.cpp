/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:59:32 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 23:48:32 by mweghofe         ###   ########.fr       */
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
	std::cout << "  test size " << valPos << std::endl;
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
	std::cout << "  test size " << static_cast<unsigned int>(val) << std::endl;
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

void testsDeepCopy()
{
	std::cout << "\n#### DEEP COPY TESTS\n\n";
	std::cout << "  copy constructor for a{10,20,30} with b(a), b[1] = 42\n";
	Array<int> a(3);
	a[0] = 10; a[1] = 20; a[2] = 30;
	Array<int> b(a);
	b[1] = 42;
	std::cout << "a | b for [0,1,2]:    " << a[0] << " | " << b[0] << "    "
		<< a[1] << " | " << b[1] << "    " << a[2] << " | " << b[2] << '\n';
	std::cout << "\n  copy assignment for c{11,22,33} with b(a), d[1] = 44\n";
	Array<int> c(3);
	c[0] = 11; c[1] = 22; c[2] = 33;
	Array<int> d(3);
	d = c;
	d[1] = 44;
	std::cout << "c | d for [0,1,2]:    " << c[0] << " | " << d[0] << "    "
		<< c[1] << " | " << d[1] << "    " << c[2] << " | " << d[2] << '\n';
	std::cout << "\n  self assignment e{42,24}\n";
	Array<int> e(2);
	e[0] = 42; e[1] = 24;
	e = e;
	std::cout << e[0] << " " << e[1] << "\n";
	std::cout << "\n  different size assignment m(7){0} n(2){42,24}\n";
	Array<int> m(7), n(2);
	n[0] = 42, n[1] = 24;
	std::cout << "m[0-6] before assignment: "
		<< m[0] << m[1] << m[2] << m[3] << m[4] << m[5] << m[6] << std::endl;
	m = n;
	std::cout << "m[0-1] after assignment: " << m[0] << m[1] << std::endl;
	try
	{
		std::cout << "m[2-6] after assignment: " << std::endl;
		std::cout << m[2] << m[3] << m[4] << m[5] << m[6] << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
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
	testsDeepCopy();
	return (0);
}
