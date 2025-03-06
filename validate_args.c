/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:41:16 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 14:26:08 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int     i;
	int     sign;
	long    result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int is_number(const char *num)
{
    int     i;
    long    tmp;

    i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    tmp = ft_atol(num);
    if (tmp > 2147483647 || tmp < -2147483648)
        return (0);
    return (1);
}

static int has_duplicates(char **splitted)
{
	int i;
	int j;

	i = 0;
	while (splitted[i])
	{
		j = i + 1;                   
		while (splitted[j])
		{
			if (ft_atoi(splitted[i]) == ft_atoi(splitted[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	*join_args(char **argv)
{
	char	*joined;
	char	*temp;
	char	*temp2;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (argv[i])
	{
		temp = ft_strjoin(joined, " ");
		free(joined);
		temp2 = ft_strjoin(temp, argv[i]);
		free(temp);
		joined = temp2;
		i++;
	}
	return (joined);
}

int validate_arguments(char **argv)
{
    char	*all_args;
	char	**splitted;
	int		i;
    
    i = 0;
    all_args = join_args(argv);
    splitted = ft_split(all_args, ' ');
    free(all_args);
    while (splitted[i])
    {
        if (!is_number(splitted[i]))
            error_exit(splitted);
        i++;
    }
    if (has_duplicates(splitted))
        error_exit(splitted);
    ft_free_str(splitted);
    return (1);
}
