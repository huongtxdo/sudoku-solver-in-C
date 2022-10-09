#include <unistd.h>
#include <stdlib.h>

int	check_argv(char **argv);
int	solve_sudoku(char **temp, int row, int column);

// fill container
char	**fill_input(char **argv)
{
	char	**container;
	int		container_index;
	int		index;
	int		argv_index;

	container = (char **)malloc(sizeof(*argv) * 9);
	index = 0;
	argv_index = 0;
	container_index = 0;
	while (index < 9)
	{
		container[index] = (char *)malloc(sizeof(char) * 10);
		while (argv[index + 1][argv_index] != '\0')
		{
			container[index][argv_index] = argv[index + 1][argv_index];
			argv_index++;
		}
		container[index][9] = '\0';
		index++;
		argv_index = 0;
	}
	return (container);
}

// main function
int	main(int argc, char **argv)
{
	char	**container;
	int		index;

	if (argc != 10 || check_argv(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	index = 0;
	container = fill_input(argv);
	if (solve_sudoku(container, 0, 0) == 1)
	{
		while (index < 9)
		{
			write(1, container[index], 9);
			write(1, "\n", 1);
			index++;
		}
		return (1);
	}
	write(1, "Error\n", 6);
	return (0);
}
