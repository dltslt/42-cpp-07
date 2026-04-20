/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:13:26 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 21:48:14 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Array.hpp"

// -----------------------------------------------------------------------------
// EXCEPTION
// -----------------------------------------------------------------------------

// template <typename T>
// const char* Array<T>::OutOfBounds::what() const throw()
// {
// 	return ("Index to access array is out of bounds.");
// }

// -----------------------------------------------------------------------------
// IMPLEMENTATION
// -----------------------------------------------------------------------------

template <typename T>
Array<T>::Array(unsigned int n)
	: size_(n)
	, element_(NULL)
{
	element_ = createArray();
}
template <typename T>
unsigned int Array<T>::size() const
{
	return (size_);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= size_)
		throw (std::out_of_range("Index to access array is out of bounds."));
	return (element_[i]);
}

// TODO maybe those could just be in a namespace as well.. test later when it works
template <typename T>
T* Array<T>::createArray()
{
	try
	{
		return (new T[size_]);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		size_ = 0;
		return (NULL);
	}
}

template <typename T>
void Array<T>::copyArray(const Array& other)
{
	for (unsigned int i = 0; i < size_; i++)
		element_[i] = other.element_[i];
}

// -----------------------------------------------------------------------------
// OCF
// -----------------------------------------------------------------------------

template <typename T>
Array<T>::Array()
	: size_(0)
	, element_(NULL)
{}

template <typename T>
Array<T>::Array(const Array& other)
	: size_(other.size_)
	, element_(NULL)
{
	element_ = createArray();
	copyArray(other);
}

template <typename T>
Array<T>::~Array()
{
	delete[] element_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	size_ = other.size_;
	T* tmp = createArray();
	copyArray();
}
