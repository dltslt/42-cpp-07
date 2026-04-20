/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:06:50 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 21:40:08 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

// template <class T> // is equivalent
template <typename T> class Array
{
  private:
	unsigned int size_; // subject demands unsigned int for ctor
	T* element_;
	T* createArray();
	void copyArray(const Array&);
  public:
	unsigned int size() const;
	Array(unsigned int);
	T& operator[](unsigned int);
	// --
	Array();
	Array(const Array&);
	~Array();
	Array& operator=(const Array&);
};

# include "Array.tpp"

#endif
