/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:51:28 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/02 17:54:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

whatever::whatever() {}
whatever::whatever(const whatever &ref) { *this = ref; }
whatever::~whatever() {}

whatever &whatever::operator=(const whatever &ref) {
    (void)ref;
    return *this;
}