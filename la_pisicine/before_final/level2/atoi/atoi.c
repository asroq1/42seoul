/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:25:45 by hyunjung          #+#    #+#             */
/*   Updated: 2021/10/01 07:47:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// atoi() 함수의 원리는 매개변수로 들어온 문자열을 앞에서 부터 읽어서, "공백" or "숫자가아닌문자" 가 올때까지 숫자로 변환을 해주는 원리 입니다.

// 그렇기 때문에 "2019BlockDMask" 가 들어오면 앞에서부터 2,0,1,9 읽다가 "B"가 오니까 2019까지 반환하게 되는것입니다.



// 또한 atoi 함수가 표현할수 있는 수의 MAX와 MIN이 정해져 있으므로 오버플로우와 언더플로우를 조심해야합니다.

// ex) atoi("999999999999999999999") //오버플로

// ex) atoi("-99999999999999999999") //언더플로

// --1234

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int val = 0;
	
	while (str[i] != 0)
	{
		if(str[i] == '-')
		{
			sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			val = val * 10 + (str[i] - '0'); 
			i++;
		}
		return (val * sign);	
	}	
	return 0;
}

int main()
{
	printf("mine : %d\n", ft_atoi("-124abc"));
	printf("real : %d\n", atoi("-124abc"));
}