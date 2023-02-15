/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:11:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/16 11:50:47 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Construct Called" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
	std::cout << "Brain Copy Assignment Called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destruct Called" << std::endl;
}

Brain &Brain::operator=(const Brain &ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = ref._ideas[i];
		}
	}
	return *this;
}
