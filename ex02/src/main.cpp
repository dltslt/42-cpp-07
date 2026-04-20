/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:59:32 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 15:27:11 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

namespace {
#define MAX_VAL 750

bool testsProjectMain()
{
	std::cout << "#### TESTS FROM PROJECT PAGE\n\n";
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return (false);
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	return (true);
}
}

int main()
{
	// int * a= new int();
	// std::string *str = new std::string();
	// std::cout << "a: " << *a << " | str: " << *str << '\n';
	if (!testsProjectMain())
		return (1);
	Array<std::string> one;
	std::cout << sizeof (one) << std::endl;
	one[-1]; // C++ does implicit conversions
	return (0);
}
