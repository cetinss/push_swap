/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:41:16 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/04 20:49:05 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_number(const char *str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int has_duplicates(char **argv, int count)
{
	int i;
	int j;

	i = 1;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int validate_arguments(char **argv)
{
    int i = 1;
    
    while (argv[i])
    {
        if (!is_number(argv[i]))
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        i++;
    }
    if (has_duplicates(argv, i))
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    return (1);
}
