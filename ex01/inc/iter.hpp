/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 02:18:05 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 23:14:15 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/*
	ITER
	expects that pointer and len match
	no pointer for array or f will silently return
	as this is not in any live use, no further headers are being included
		thus, no exceptions thrown
*/

template <typename T>
void iter(T* array, const unsigned long len, void (*f)(const T&))
{
	if (array == NULL || f == NULL)
		return ;
	for (unsigned long i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void iter(T* array, const unsigned long len, void (*f)(T&))
{
	if (array == NULL || f == NULL)
		return ;
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
