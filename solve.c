/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:19:37 by hdo               #+#    #+#             */
/*   Updated: 2022/08/21 14:19:38 by hdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check a number against column and row
int	v1(char **container, int row, int column, int input)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 9)
	{
		if (container[row][x] == input)
			return (0);
		x++;
	}
	while (y < 9)
	{
		if (container[y][column] == input)
			return (0);
		y++;
	}
	return (1);
}

// check a number against a box
int	v2(char **container, int row, int column, int input)
{
	int	x;
	int	y;
	int	start_collumn;
	int	start_row;

	x = 0;
	y = 0;
	start_row = row - row % 3;
	start_collumn = column - column % 3;
	while (y < 3)
	{
		while (x < 3)
		{
			if (container[y + start_row][x + start_collumn] == input)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// fill the grid with solved solution
int	solve_sudoku(char **temp, int row, int column)
{
	char	input;

	input = '1';
	if (row == 8 && column == 9)
		return (1);
	if (column == 9)
	{
		row++;
		column = 0;
	}
	if (temp[row][column] > '0')
		return (solve_sudoku(temp, row, column + 1));
	while (input <= '9')
	{
		if (v2(temp, row, column, input) && v1(temp, row, column, input))
		{
			temp[row][column] = input;
			if (solve_sudoku(temp, row, column + 1))
				return (1);
		}
		temp[row][column] = '.';
		input++;
	}
	return (0);
}
