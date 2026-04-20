/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 02:18:05 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 11:03:45 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* array, const unsigned long len, void (*f)(const T&))
{
	for (unsigned long i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void iter(T* array, const unsigned long len, void (*f)(T&))
{
	for (unsigned long i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void prtArr(const T& type)
{
	std::cout << type << '\n';
}

#endif
