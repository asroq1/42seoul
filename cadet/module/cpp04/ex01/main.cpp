/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:30:40 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/16 17:09:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	// int n = 2;
	// Animal *animals[n];

	// for (int i = 0; i < n; i++)
	// {
	// 	if (i % 2 == 0)
	// 		animals[i] = new Cat();
	// 	else
	// 		animals[i] = new Dog();
	// 	std::cout << std::endl;
	// }

	// for (int i = 0; i < n; i++)
	// {
	// 	delete animals[i];
	// 	std::cout << std::endl;
	// }

	// Cat *cat = new Cat();
	// Cat *copy = new Cat();

	// cat->setIdeas(1, "It's Friday daskim");
	// *copy = *cat;

	// std::cout << std::endl;
	// std::cout << "Original : " << cat->getIdeas(1) << std::endl;
	// std::cout << "Copy : " << copy->getIdeas(1) << std::endl;
	// std::cout << std::endl;

	// copy->setIdeas(1, "salut !");
	// std::cout << "Original : " << cat->getIdeas(1) << std::endl;
	// std::cout << "Copy : " << copy->getIdeas(1) << std::endl;
	// std::cout << std::endl;

	// delete cat;
	// delete copy;

	// Animal *new_cat = new Cat();
	// new_cat->makeSound();
	// std::cout << std::endl;
	// delete new_cat;

	// system("leaks a.out");

	Cat cat;
	cat.setIdeas(1, "It's Friday daskim");
	Cat copy(cat);

	std::cout << std::endl;
	std::cout << "Original : " << cat.getIdeas(1) << std::endl;
	std::cout << "Copy : " << copy.getIdeas(1) << std::endl;
	std::cout << std::endl;

	copy.setIdeas(1, "salut !");
	std::cout << "Original : " << cat.getIdeas(1) << std::endl;
	std::cout << "Copy : " << copy.getIdeas(1) << std::endl;
	std::cout << std::endl;

	// delete cat;
	// delete copy;
	return 0;
}