/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:15 by bpoetess          #+#    #+#             */
/*   Updated: 2022/12/10 20:49:25 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <memory>
#include <iterator>

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
			int	constructedElements;
			T*	array;

		public:
			typedef	T			value_type;
			typedef	Allocator	allocator_type;
			typedef	value_type&	reference;
			typedef	std::size_t		size_type;
			typedef	std::ptrdiff_t	difference_type;
			typedef	typename	Allocator::pointer 			pointer;
			typedef	typename	Allocator::const_pointer	const_pointer;

			struct iterator
			{
				private:
					T* ptr;
				
				public:
					T& operator*() const;
					
			};
			
			size_type	capacity() const;
			size_type	size() const;
			size_type	max_size() const;
	
			void	reserve(size_type new_cap);

			vector(vector &originVector);
			vector();
			~vector();
	
	};

	template<class T, class Allocator>
	T& vector<T, Allocator>::iterator::operator*() const
	{
		return *ptr;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector()
	{
		this->allocatedElements = 0;
		this->constructedElements = 0;
		this->array = 0;
		std::cout << "this is c++ feature" << std::endl;
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
	{
		return (this->constructedElements);
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
	{
		return (this->allocatedElements);
	}
	
	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
	{
		return (std::numeric_limits<difference_type>::max());
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::reserve(typename vector<T, Allocator>::size_type new_cap)
	{
		T*			ptrTmp;
		Allocator	alloc;

		if (new_cap >= this->size())
			return ;
		ptrTmp = alloc.allocate(new_cap);
		for(size_t i = 0; i < this->constructedElements; i++)
		{
			try
			{
				alloc.construct(ptrTmp + i, this->array[i]);
			}
			catch(const std::exception& e)
			{
				for(size_t j = 0; j < i; j++)
					alloc.destroy(ptrTmp + j);
				alloc.deallocate(ptrTmp, new_cap);
				throw;
			}
		}
		for(size_t i = 0; i < this->constructedElements; i++)
			alloc.destroy(this->array[i]);
		alloc.deallocate(this->array, this->size());
		this->array = ptrTmp;
		this->allocatedElements = new_cap;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(vector &originVector)
	{
		(void) originVector;
		this->allocatedElements = originVector.allocatedElements;
		this->constructedElements = originVector.constructedElements;
		this->array = originVector.array;
		std::cout << "entered coping constructor" << std::endl;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::~vector()
	{}

}

#endif