/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:30:20 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/28 17:56:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

int main(int argc, char **argv) {
    Convertor convertor;
    if (argc != 2) {
        std::cout << "Wrong input argc error" << std::endl;
        return 1;
    }
    std::string s = static_cast<std::string>(argv[1]);
    convertor.setValue(s, argv[1]);
    return 0;
}