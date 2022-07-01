/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 19:23:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack_data
{
	int	*arr;
	int	length;
	int	total;
}	t_stack_data;

/* utils.c */
int				ft_isspace(char c);
void			occur_error(int err);
void			free_str(char **str);
int				compare_command(const char *str1, const char *str2);

/* validter.c */
int				check_input(t_stack_data *stack);
void			check_duplicate(t_stack_data *stack);
void			free_arr(char **arr);
void			input_validater(t_stack_data *stack, char *argv[]);
int				check_numbers(const char *str);

/* stack.c */
void			get_stack(t_stack_data *stack);
void			get_a(t_stack_data *stack, int n);
void			get_b(t_stack_data *stack, int length);

/* sort.c */
void			small_command(t_stack_data *a, t_stack_data *b);
void			large_command(t_stack_data *a, t_stack_data *b);
void			a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i);
void			b_to_a(t_stack_data *b, t_stack_data *a);
void			sort_b(t_stack_data *b, int size);

/* sort_utils.c */
int				get_top(t_stack_data *stack);
int				get_mid(t_stack_data *stack);
int				get_bot(t_stack_data *stack);
void			sort_two_three(t_stack_data *stack);

/* array.c */

void			indexing_arr(t_stack_data *a);
void			sort_stack(t_stack_data *a, t_stack_data *b);

/* command.c */
int				sa(t_stack_data *a);
int				sb(t_stack_data *b);
int				ss(t_stack_data *a, t_stack_data *b);
int				pa(t_stack_data *a, t_stack_data *b);
int				pb(t_stack_data *a, t_stack_data *b);

/* command_rot.c */
int				ra(t_stack_data *a);
int				rb(t_stack_data *b);
int				rr(t_stack_data *a, t_stack_data *b);

/* command_rerot.c */
int				rra(t_stack_data *a);
int				rrb(t_stack_data *b);
int				rrr(t_stack_data *a, t_stack_data *b);

/* command_utils.c */
int				swap(t_stack_data *from);
int				push(t_stack_data *from, t_stack_data *to);
int				reverse_rotate(t_stack_data *from);
int				rotate(t_stack_data *from);

/* checker.c */
void			check_command(t_stack_data *a, t_stack_data *b);
char			*get_command(int fd);
void			command_bonus(t_stack_data *a, t_stack_data *b, char *command);
void			print_result(t_stack_data *a, t_stack_data *b);

/* bonus_cmd.c */
int				bonus_sa(t_stack_data *a);
int				bonus_sb(t_stack_data *b);
int				bonus_ss(t_stack_data *a, t_stack_data *b);
int				bonus_pa(t_stack_data *a, t_stack_data *b);
int				bonus_pb(t_stack_data *a, t_stack_data *b);
int				bonus_ra(t_stack_data *a);
int				bonus_rb(t_stack_data *b);
int				bonus_rr(t_stack_data *a, t_stack_data *b);
int				bonus_rra(t_stack_data *a);
int				bonus_rrb(t_stack_data *b);
int				bonus_rrr(t_stack_data *a, t_stack_data *b);

/* GNL */
# if OPEN_MAX <= 12800
#  define ARRAY_MAX 12800
# endif
# define BUFFER_SIZE 42

char			*get_next_line(int fd);
char			*ft_get_lstr(int fd, char *lstr);
char			*ft_get_line(char *lstr);
char			*ft_reset_lstr(char *lstr);
char			*gnl_strjoin(char *s1, char *s2);
#endif 