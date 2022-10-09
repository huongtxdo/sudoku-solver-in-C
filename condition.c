/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:13:48 by hdo               #+#    #+#             */
/*   Updated: 2022/08/21 14:13:48 by hdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// calculate string's length
int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

// check string
int	check_char(char c)
{
	if ((c >= '0' && c <= '9') || c == '.')
	{
		return (1);
	}
	return (0);
}

// check arguments
int	check_argv(char **argv)
{
	int	index;
	int	str_index;

	index = 1;
	str_index = 0;
	while (index < 10)
	{
		if (ft_strlen(argv[index]) != 9)
		{
			return (0);
		}
		while (argv[index][str_index] != '\0')
		{
			if (check_char(argv[index][str_index]) == 0)
			{
				return (0);
			}
			str_index++;
		}
		index++;
	}
	return (1);
}
