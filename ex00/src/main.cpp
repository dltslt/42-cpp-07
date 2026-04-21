/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:13:54 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/21 15:44:10 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

/*
	NOTE ON FUNCTION CALLING
	calling ::min() looks for the min() declared in GLOBAL namespace
		while ignoring any other locally declared functions of same name
	using just min() is unqualified lookup
		checks local scope first, then moves to outer scope(s)
*/

int main()
{
	std::cout << "##### SUBJECT TESTS\n\n";
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << "\n##### SOME MORE TESTS\n\n";
	a = -42;
	b = 42;
	double d1 = 42.24, d2 = 24.42;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << max(a, b) << std::endl;
	std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
	std::cout << "min( d1, d2 ) = " << min(d1, d2) << std::endl;
	std::cout << "max( d1, d2 ) = " << max(d1, d2) << std::endl;
	std::cout << "swapping d1&d2...\n";
	swap(d1, d2);
	std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
	std::cout << "\n##### GENERAL DANGLING POINTER RISK\n\n";
	const std::string& ref = std::string("a life-extended temporary object");
	std::cout << "some temporary objects receive an extended life time. "
			  << "such as this <" << ref << ">\n";
	const std::string& alias = ::max(ref, std::string("dangling reference"));
	std::cout << "others like <alias> hold a dangling reference and are UB\n";
	const int& dont = ::max(int(24), int(42));
	std::cout << "this is also true for references to simple types like <int>\n";
	int okay = ::max(int(24), int(42));
	std::cout << "this one is safe - it is not a reference, the type is a copy:"
			  << " <" << okay << ">\n";
	(void)alias;
	(void)dont;
	return (0);
}
