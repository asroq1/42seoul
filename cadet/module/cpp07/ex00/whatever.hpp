/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:49:01 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/03 17:57:13 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &a, T &b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> T min(T &a, T &b) {
    if (a > b)
        return b;
    else
        return a;
}

template <typename T> T max(T &a, T &b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif
