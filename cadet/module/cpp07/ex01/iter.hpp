/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:57:53 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/03 18:11:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *arr, int length, void (*f)(T &arr)) {
    for (int i = 0; i < length; i++) {
        f(arr[i]);
    }
}

template <typename T> void print(T &obj) { std::cout << "[" << obj << "] "; }

#endif
