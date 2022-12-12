/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:06:15 by bpoetess          #+#    #+#             */
/*   Updated: 2022/12/12 23:58:00 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <memory>
#include <iterator>
#include <stdexcept>

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
			size_t	allocatedElements;
			size_t	constructedElements;
			T*		array;

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
					T& operator*() const
					{
						return *ptr;
					}

			};
			
			size_type	capacity() const
			{
				return (this->allocatedElements);
			}
			size_type	size() const
			{
				return (this->constructedElements);
			}
			size_type	max_size() const
			{
				return (std::numeric_limits<difference_type>::max());
			}
			bool 		empty() const
			{
				if (this->constructedElements > 0)
					return (true);
				return (false);
			}
	
			void	reserve(size_type new_cap)
			{
				T*			ptrTmp;
				Allocator	alloc;
		
				if (new_cap <= this->size())
					return ;
				if (new_cap > max_size())
					throw (std::length_error ("length_error"));
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
						throw (e);
					}
				}
				for(size_t i = 0; i < this->constructedElements; i++)
					alloc.destroy(this->array + i);
				alloc.deallocate(this->array, this->capacity());
				this->array = ptrTmp;
				this->allocatedElements = new_cap;
			}
			void resize( size_type count )
			{
				this->resize(count, T());
			}
			void resize( size_type count, T value = T() )
			{
				Allocator	alloc;

				if (count == this->allocatedElements)
					return ;
				if (count > this->allocatedElements)
					reserve (count);
				else
				{
					for (size_t i = count; i < this->constructedElements; i++)
						alloc.destroy(this->array + i);
				}	
				for (size_t i = this->constructedElements; i < count; i++)
					this->array[i] = value;
				this->constructedElements = count;
			}
			
			void	clear()
			{
				Allocator	alloc;

				for(size_t i = 0; i < this->constructedElements; i++)
					alloc.destroy(this->array + i);
				this->constructedElements = 0;
			}

			reference at( size_type pos )
			{
				if (!(pos < size()))
					throw (std::out_of_range ("out of range"));
				return (&this->array[pos]);
			}

			vector<T> &operator=(vector<T> const &obj)
			{
				Allocator	alloc;

				this->allocatedElements = 0;
				this->constructedElements = 0;
				this->array = 0;
				this->clear();
				this->reserve(obj.allocatedElements);
				for(size_t i = 0; i < obj.constructedElements; i++)
				{
					try
					{
						alloc.construct(this->array + i, obj.array[i]);
					}
					catch(const std::exception& e)
					{
						for(size_t j = 0; j < i; j++)
							alloc.destroy(this->array + j);
						alloc.deallocate(this->array, obj.allocatedElements);
						this->array = 0;
						this->allocatedElements = 0;
						this->constructedElements = 0;
						throw (e);
					}
				}
				return (*this);
			}

			vector(vector<T> &originVector)
			{
				*this = originVector;
			}

			vector()
			{
				this->allocatedElements = 0;
				this->constructedElements = 0;
				this->array = 0;
				std::cout << "this is c++ feature" << std::endl;
			}

			~vector()
			{
				Allocator	alloc;

				this->clear();
				if (this->array)
				alloc.deallocate(this->array, this->capacity());
			}
	
	};
}

#endif