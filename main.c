/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:34:56 by bpoetess          #+#    #+#             */
/*   Updated: 2022/05/15 02:08:12 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

namespace ft
{
	class vector
	{
		private:
			int	count;
			int	filledElements;

		public:
			int	getFilledElements();
			int	getCount();
			vector(vector &originVector);
			vector();
			~vector();
	
	};

	vector::vector()
	{
		this->count = 0;
		this->filledElements = 0;
		std::cout << "this is c++ feature" << std::endl;
	}

	int	vector::getFilledElements()
	{
		return (this->filledElements);
	}

	int	vector::getCount()
	{
		return (this->count);
	}

	vector::vector(vector &originVector)
	{
		(void) originVector;
		this->count = originVector.count;
		this->filledElements = originVector.filledElements;
		std::cout << "entered coping constructor" << std::endl;
	}

	vector::~vector()
	{}

}

int	main(int argc, char **argv)
{
	ft::vector	vec1;
	ft::vector	vec2(vec1);
	
	(void)		argc;
	(void)		argv;
	std::cout << vec1.getFilledElements() << std::endl;
	std::cout << vec1.getCount() << std::endl;
	return (0);
}
