/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:43:37 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/20 10:58:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &ref);
	~Cat();

	Cat &operator=(const Cat &ref);
	void makeSound() const;
	std::string getIdeas(int q) const;
	void setIdeas(int q, std::string str);
};

#endif
