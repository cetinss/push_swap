/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:33:24 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 21:02:54 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_stacklast(*lst);
	last->next = new;
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->content = content;
	new->index = -1; 
	new->next = NULL;
	return (new);
}

int	ft_stacksize(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
