/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:57:53 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/02 18:14:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

class iter {
  private:
    /* data */

  public:
    iter();
    iter(const iter &ref);
    ~iter();

    iter &operator=(const iter &ref);

    template <typename T>
    T iters(T *arr, unsigned int length, void (*f)(T &arr)) {
        for (int i = 0; i < length; i++) {
            f(arr[i]);
        }
    }
};

#endif
