/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_optimized.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:45:16 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 12:04:41 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

/*
** get_bit:
**  'index' değerinin bit_num. bit'inin 0 veya 1 olduğunu döndürür.
*/
static int	get_bit(int index, int bit_num)
{
	return ((index >> bit_num) & 1);
}

/*
** find_max_index:
**  Stack'teki en büyük index değerini bulur.
**  Örn: 5 eleman varsa en büyük index genelde 4 olur.
*/
static int	find_max_index(t_stack *stack)
{
	int	max_i;

	max_i = 0;
	while (stack)
	{
		if (stack->index > max_i)
			max_i = stack->index;
		stack = stack->next;
	}
	return (max_i);
}

/*
** is_stack_sorted:
**  A tamamen sıralı (artan index) mı ve B boş mu kontrol eder.
**  Tam sıralıysa 1, değilse 0 döndürür.
*/
static int	is_stack_sorted(t_stack *a, t_stack *b)
{
	if (b) /* B'de eleman varsa sıralama tamam değildir */
		return (0);
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

/*
** lsd_pass:
**  Belirli bir 'bit' için A'daki her elemanı kontrol eder.
**  Bit = 0 ise B'ye push, Bit = 1 ise A içinde tutmak için rotate yapar.
**  Döngü bittikten sonra B'ye gidenleri tekrar A'ya 'pa' ile taşır.
*/
static void	lsd_pass(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	i;

	size = ft_stacksize(*a);
	i = 0;
	while (i < size)
	{
		if (get_bit((*a)->index, bit) == 1)
			ft_ra(a);
		else
			ft_pb(a, b);
		i++;
	}
	while (*b)
		ft_pa(a, b);
}

/*
** ft_radix_optimized:
**  1) En büyük index'in ihtiyaç duyduğu bit sayısını hesaplar (max_bit).
**  2) 0'dan max_bit'e kadar LSD turu yapar.
**  3) Her tur sonunda, A sıralı ve B boş mu diye bakar (erken çıkış).
**  4) Küçük stack'lerde gereksiz turları atlayarak hamle sayısını azaltır.
*/
void	ft_radix_optimized(t_stack **a, t_stack **b)
{
	int	max_i;
	int	max_bit;
	int	bit;

	max_i = find_max_index(*a);
	max_bit = 0;
	while ((max_i >> max_bit) != 0)
		max_bit++;
	bit = 0;
	while (bit < max_bit)
	{
		lsd_pass(a, b, bit);
		if (is_stack_sorted(*a, *b))
			break ;
		bit++;
	}
}