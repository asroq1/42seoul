/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:50:57 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/02 19:54:35 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void	*ptr, int value, size_t n)
{
	
	return (0);
}

int main() {
  char* pch;
  char str[] = "Example string";
  pch = (char*)memchr(str, 'p', strlen(str));

  if (pch != NULL)
    printf("'p' found at position %d.\n", pch - str + 1);
  else
    printf("'p' not found.\n");

  return 0;
}