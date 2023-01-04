/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:57:53 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/04 16:59:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *arr, size_t length, void (*f)(T &arr)) {
    for (size_t i = 0; i < length; i++) {
        f(arr[i]);
    }
}

template <typename T>
void iter(const T *arr, size_t length, void (*f)(const T &arr)) {
    for (size_t i = 0; i < length; i++) {
        f(arr[i]);
    }
}

template <typename T> void print(const T &obj) {
    std::cout << "[" << obj << "] ";
}

template <typename T> void increaotr(T &obj) { obj = obj + 1; }

#endif
