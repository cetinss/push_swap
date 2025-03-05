/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:28:56 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/05 14:21:54 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int 			index;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
int	ft_stacksize(t_stack *lst);
t_stack	*ft_stacknew(int content);
int validate_arguments(char **argv);
void	ft_free_str(char **str);
void	ft_free_stack(t_stack **stack);

#endif