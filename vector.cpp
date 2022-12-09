/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:15 by bpoetess          #+#    #+#             */
/*   Updated: 2022/12/09 17:06:47 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <memory>

#ifndef VECTOR_CPP
# define VECTOR_CPP

namespace ft
{
	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
		private:
			int	allocatedElements;
			int	filledElements;
			T*	array;

		public:
			typedef	T value_type;
			typedef	Allocator allocator_type;
			typedef	value_type& reference;
			typedef	typename	Allocator::pointer pointer;
			typedef	typename	Allocator::const_pointer const_pointer;
			typedef	std::size_t size_type;
			typedef	std::ptrdiff_t difference_type;
			int	getFilledElements();
			int	getCount();
			vector(vector &originVector);
			vector();
			~vector();
	
	};

	template<
		class T,
		class Allocator
	>
	vector<T, Allocator>::vector()
	{
		this->allocatedElements = 0;
		this->filledElements = 0;
		this->array = 0;
		std::cout << "this is c++ feature" << std::endl;
	}

	template<
		class T,
		class Allocator
	>
	int	vector<T, Allocator>::getFilledElements()
	{
		return (this->filledElements);
	}

	template<
		class T,
		class Allocator
	>
	int	vector<T, Allocator>::getCount()
	{
		return (this->allocatedElements);
	}

	template<
		class T,
		class Allocator
	>
	vector<T, Allocator>::vector(vector &originVector)
	{
		(void) originVector;
		this->allocatedElements = originVector.allocatedElements;
		this->filledElements = originVector.filledElements;
		this->array = originVector.array;
		std::cout << "entered coping constructor" << std::endl;
	}

	template<
		class T,
		class Allocator
	>
	vector<T, Allocator>::~vector()
	{}

}

#endif