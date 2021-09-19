/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:38:58 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/17 23:18:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *arr, int n)
{
	int i;
	char c;

	i = 0; 
	
	while (i < n)
	{
		c = arr[i] + 48;
		write(1, &c ,1);
		i++;
	}		
	
}

//i는 값을 +1해서 다음 뎁스로 넘겨주기 위해서 넣어줌 얘가 없으면 내 머리론 힘듦
void	ft_print_recursive(int n, int depth, int *arr, int i)
{	
	if (depth >= n)
	{
		ft_print(arr, n);	
		return;
	}
	while (i <= 9)
	{
		arr[depth] = i;
		i++;
		ft_print_recursive(n, depth + 1 , arr, i);
	}
}

void	ft_print_combn(int n)
{ 
	int i;
	int arr[10];
	
	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	ft_print_recursive(n, 0, arr, 0);
}

int main()
{
	ft_print_combn(2);
	return 0;
}