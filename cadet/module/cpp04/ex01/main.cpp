/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:30:40 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/20 11:31:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int n = 2;
	Animal *animals[n];

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	Cat *cat = new Cat();
	std::cout << "------------------------" << std::endl;
	Cat *copy = new Cat();

	cat->setIdeas(1, "It's Friday daskim");
	*copy = *cat;

	std::cout << std::endl;
	std::cout << "Original : " << cat->getIdeas(1) << std::endl;
	std::cout << "Copy : " << copy->getIdeas(1) << std::endl;
	std::cout << std::endl;

	copy->setIdeas(1, "salut !");
	std::cout << "Original : " << cat->getIdeas(1) << std::endl;
	std::cout << "Copy : " << copy->getIdeas(1) << std::endl;
	std::cout << std::endl;

	delete cat;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;

	delete copy;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;

	Animal *new_cat = new Cat();
	new_cat->makeSound();
	std::cout << std::endl;
	delete new_cat;

	// Cat cat;
	// cat.setIdeas(1, "It's Friday daskim");
	// std::cout << "------------------------" << std::endl;
	// Cat copy(cat);

	// std::cout << std::endl;
	// std::cout << "Original : " << cat.getIdeas(1) << std::endl;
	// std::cout << "Copy : " << copy.getIdeas(1) << std::endl;
	// std::cout << std::endl;

	// copy.setIdeas(1, "No It's Monday bro!");
	// std::cout << "Original : " << cat.getIdeas(1) << std::endl;
	// std::cout << "Copy : " << copy.getIdeas(1) << std::endl;
	// std::cout << std::endl;

	return 0;
}