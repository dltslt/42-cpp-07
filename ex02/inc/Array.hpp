/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweghofe <mweghofe@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:06:50 by mweghofe          #+#    #+#             */
/*   Updated: 2026/04/20 16:38:21 by mweghofe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

// template <class T> // is equivalent
template <typename T> class Array
{
  private:
	unsigned int size_; // subject demands unsigned int for ctor
	T* element_;
	T* createArray();
	void copyArray(const Array&);
	// --
	class OutOfBounds : public std::exception // TODO check standard exceptions!! out_of_range
	{
		public: const char* what() const throw();
	};
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
