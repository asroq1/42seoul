/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:07:43 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/16 12:21:05 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	// protected:
public:
	std::string _ideas[100];
	Brain();
	Brain(const Brain &ref);
	~Brain();

	Brain &operator=(const Brain &ref);
};

#endif
