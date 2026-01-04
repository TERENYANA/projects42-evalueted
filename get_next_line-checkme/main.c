#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*string;

	string = NULL;
	fd = open("./test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	string = get_next_line(fd);
	while (string != NULL)
	{
		printf("%s", string);
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
	return (0);
}