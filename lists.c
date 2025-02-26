/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:28:14 by sencetin          #+#    #+#             */
/*   Updated: 2025/02/26 21:32:30 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int	ft_lstsize(t_stack *lst)
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

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}
