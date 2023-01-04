/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:50:15 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/04 16:55:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T> class Array {
  private:
    T *_data;
    unsigned int _size;

  public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array &ref);
    Array &operator=(const Array &ref);
    T &operator[](unsigned int n);
    const T &operator[](unsigned int n) const;
    Array &operator<<(std::ostream &os);

    unsigned int size() const;
};

template <typename T> Array<T>::Array() {
    this->_size = 1;
    this->_data = new T[this->_size];
}

template <typename T> Array<T>::Array(unsigned int n) {
    this->_size = n;
    this->_data = new T[n];
}

template <typename T> Array<T>::~Array() { delete[] this->_data; }

template <typename T> Array<T>::Array(const Array &ref) {
    this->_size = ref._size;
    this->_data = new T[ref._size];
    for (unsigned int i = 0; i < ref._size; i++) {
        this->_data[i] = ref._data[i];
    }
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &ref) {
    if (this != &ref) {
        this->_size = ref._size;
        delete[] this->_data;
        this->_data = new T[ref._size];
        for (unsigned int i = 0; i < ref._size; i++) {
            this->_data[i] = ref._data[i];
        }
    }
    return *this;
}

template <typename T> const T &Array<T>::operator[](unsigned int n) const {
    if (n >= this->_size) {
        throw std::exception();
    }
    return this->_data[n];
}

template <typename T> T &Array<T>::operator[](unsigned int n) {
    if (n >= this->_size) {
        throw std::exception();
    }
    return this->_data[n];
}

template <typename T> unsigned int Array<T>::size() const {
    return this->_size;
}
#endif
