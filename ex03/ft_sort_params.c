/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 02:44:21 by jceia             #+#    #+#             */
/*   Updated: 2020/12/05 02:56:49 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
			return (1);
		if (*s2 > *s1)
			return (-1);
		s1++;
		s2++;
	}
	if (*s1 > 0)
		return (1);
	if (*s2 > 0)
		return (-1);
	return (0);
}

void	ft_sort_int_tab(char **strs, int size)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(strs[j], strs[j + 1]) > 0)
			{
				s = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = s;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	**params;
	int		index;
	int		size;

	params = argv + 1;
	size = argc - 1;
	ft_sort_int_tab(params, size);
	index = 0;
	while (index < size)
	{
		ft_putstr(params[index]);
		ft_putstr("\n");
		index++;
	}
	return (0);
}
