/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:35:44 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 11:05:39 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <sstream>
#include <iostream>

void initInt(int& num)
{
	num = 0;
}

void initStr(std::string& str)
{
	static short cnt = 1;
	std::ostringstream oss;
	oss << cnt;
	str = "number " + oss.str();
	cnt += 1;
}

void increaseIntByTwo(int& num)
{
	num += 2;
}

void clearStr(std::string& str)
{
	str.clear();
}

int main()
{
	const unsigned long size = 10;
	int arrInt[size];
	std::string arrStr[size];
	std::cout << ">>> created an INT array & STRING array both of size "
		<< size << '\n';
	std::cout << ">>> initializing both arrays... printing results\n";
	iter(arrInt, size, initInt);
	iter(arrInt, size, prtArr);
	iter(arrStr, size, initStr);
	iter(arrStr, size, prtArr);
	std::cout << ">>> changing INT array, everything +2\n";
	iter(arrInt, size, increaseIntByTwo);
	iter(arrInt, size, prtArr);
	std::cout << ">>> changing INT array, first half +2\n";
	iter(arrInt, size * 0.5, increaseIntByTwo);
	iter(arrInt, size, prtArr);
	std::cout << ">>> clearing 75% of STR array\n";
	iter(arrStr, size * 0.75, clearStr);
	iter(arrStr, size, prtArr);
	return (0);
}
