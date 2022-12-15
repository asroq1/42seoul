/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:30:40 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/15 17:50:58 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int nb_animals = 2;
	Animal *zoo[nb_animals];

	// SUBJECT
	std::cout << "t1" << std::endl;
	for (int i = 0; i < nb_animals; i++)
	{
		if (i % 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
		std::cout << std::endl;
	}
	std::cout << "t2" << std::endl;

	for (int i = 0; i < nb_animals; i++)
	{
		delete zoo[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// DEEP COPY
	// Cat cat;
	// Cat copy;

	// cat.setIdeas(1, "bonsoir");
	// copy = cat;
	// std::cout << "Original: " << cat.getIdeas(1) << std::endl;
	// std::cout << "Copy: " << copy.getIdeas(1) << std::endl;
	// copy.setIdeas(1, "salut !");
	// std::cout << "Original: " << cat.getIdeas(1) << std::endl;
	// std::cout << "Copy: " << copy.getIdeas(1) << std::endl
	// 		  << std::endl;
	// Animal *new_cat = new Cat();
	// new_cat->makeSound();
	// std::cout << std::endl;
	// delete new_cat;
	return 0;
}