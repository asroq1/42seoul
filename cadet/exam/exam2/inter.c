/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:30:37 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/11 18:14:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//Assignment name  : inter
//Expected files   : inter.c
//Allowed functions: write

//Write a program that takes two strings and displays, without doubles, the
//characters that appear in both strings, in the order they appear in the first
//one.

//The display will be followed by a \n.

//If the number of arguments is not 2, the program displays \n.

//Examples:

//$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
//padinto$
//$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
//df6ewg4$
//$>./inter "nothing" "This sentence hides nothing" | cat -e
//nothig$
//$>./inter | cat -e
//$

#include <unistd.h>

//int main(int argc, char *argv[])
//{
//	int used[255] = {0, };
//	int i = 0;
//	int j = 0;

//	if (argc == 3)
//	{
//		while (argv[1][i])
//		{
//			j = 0;
//			while (argv[2][j])
//			{
//				if (used[(int)argv[1][i]] == 0 && argv[1][i] == argv[2][j])
//				{
//					write(1, &argv[1][i], 1);
//					used[(int)argv[1][i]] = 1;
//				}
//				j++;
//			}
//			i++;
//		}
//	}
//	write(1, "\n", 1);
//	return (0);
//}

//int main(int argc, char *argv[])
//{
//	int used[255] = {0};
//	int i = 0;
//	int j = 0;

//	if (argc == 3)
//	{
//		while (argv[1][i])
//		{
//			j = 0;
//			while (argv[2][j])
//			{
//				if (used[(int)argv[1][i]] == 0 && argv[1][i] == argv[2][j])
//				{
//					write(1, &argv[1][i], 1);
//					used[(int)argv[1][i]] = 1;
//				}
//				j++;
//			}
//			i++;
//		}
//	}
//	write(1, "\n", 1);
//	return (0);
//}

//int main(int argc, char *argv[])
//{	
//	int used[255] = {0};
//	int i = 0;
//	int j = 0;

//	if (argc == 3)
//	{
//		while (argv[1][i])
//		{
//			j = 0;
//			while (argv[2][j])
//			{
//				if (used[(int)argv[1][i]] == 0 && argv[1][i] == argv[2][j])
//				{
//					write(1, &argv[1][i], 1);
//					used[(int)argv[1][i]] = 1;
//				}	
//				j++;	
//			}
//			i++;
//		}
//	}
//	return (0);
//}

//int main(int argc, char *argv[])
//{
//	int used[255] = {0};
//	int i = 0;
//	int j = 0;

//	if (argc == 3)
//	{
//		while (argv[1][i])
//		{
//			j = 0;
//			while (argv[2][j])
//			{
//				if (used[(int)argv[1][i]] == 0 && argv[1][i] == argv[2][j])
//				{
//					write(1, &argv[1][i], 1);
//					used[(int)argv[1][i]] = 1;
//				}
//				j++;
//			}
//			i++;
//		}	
//	}
//	write(1, "\n", 1);
//	return (0);
//}

int main(int argc, char *argv[])
{
	int used[255] = {0};
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (used[(int)argv[1][i]] == 0 && argv[1][i] == argv[2][j])
				{
					write(1, &argv[1][i], 1);
					used[(int)argv[1][i]] = 1;
				}
				j++;
			}
			i++;
		}		
	}	
	write(1, "\n", 1);
	return (0);
}
