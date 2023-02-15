/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/22 14:18:35 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Bureaucrat citizen(150, "citizen");
    Bureaucrat president(1, "president");
    Form form("form", 50, 50);

    std::cout << citizen << std::endl;
    std::cout << president << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl;

    citizen.signForm(form);
    std::cout << citizen << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl;

    president.signForm(form);
    std::cout << president << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl;

    return (0);
}
