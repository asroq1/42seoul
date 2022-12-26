/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:30:40 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/21 11:10:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // const Animal *meta = new Animal();
    const Animal *j = new Dog();
    std::cout << std::endl;

    const Animal *i = new Cat();
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;

    i->makeSound(); // will output the cat sound!
    j->makeSound();
    // meta->makeSound();

    std::cout << std::endl;

    delete j;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;

    return 0;
}