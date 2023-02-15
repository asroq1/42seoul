/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:43:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/15 13:45:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &ref);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &ref);
	void makeSound() const;
	std::string getType() const;
};

#endif
