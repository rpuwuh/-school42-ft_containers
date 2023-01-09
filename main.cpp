/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:34:56 by bpoetess          #+#    #+#             */
/*   Updated: 2022/12/30 21:42:14 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.cpp"
#include <vector>

int	main(int argc, char **argv)
{
	ft::vector<int>	vec1;
	ft::vector<int>	vec2(vec1);
	
	(void)		argc;
	(void)		argv;
	std::cout << vec1.size() << std::endl;
	std::cout << vec1.capacity() << std::endl;
	return (0);
}
