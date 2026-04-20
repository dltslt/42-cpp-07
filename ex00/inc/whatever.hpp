/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:11:59 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 22:52:52 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/*
	REMEMBER
	- templates create version for every (used?) datatype on compile time
	- the datatype must support all operators used by the function template
	- explicit calling is possible (but here useless): min<int>()
*/

template <typename T> void swap(T& left, T& right)
{
	T tmp = left; // this is a copy operation, like classes call copy ctor
	left = right;
	right = tmp;
}

template <typename T> T min(const T& one, const T& two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

template <typename PLACEHOLDER>
PLACEHOLDER max(const PLACEHOLDER& one, const PLACEHOLDER& two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

#endif
