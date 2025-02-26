/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:11:04 by sencetin          #+#    #+#             */
/*   Updated: 2025/02/26 21:50:32 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		ft_basic_sort(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		ft_radix(stack_a, stack_b);
}

static	void	ft_get_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**split;
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i++]);
		str = ft_strjoin(str, " ");
	}
	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
	{
		new = ft_lstnew(ft_atoi(split[i++]));
		//indeksleri -1'den başlat
		ft_lstadd_back(stack, new);
	}
	ft_double(*stack);
	// integer check
	// 12 karakterden büyük mü check
	ft_free_str(split);
	free(str);
	ft_index(stack);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_get_stack(stack_a, argc, argv);
	if (ft_check_sort(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	// ft_double(*stack_a); gereksiz bir eleman olabilir bu
	ft_stack_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0); 
}
