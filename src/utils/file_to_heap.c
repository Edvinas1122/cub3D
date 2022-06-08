#include "utils.h"

static char	*read_line(int fd)
{
	char	*c;
	char	*tmp;
	char	*buf;
	ssize_t	ct;

	ct = 1;
	buf = ft_calloc(1, 1);
	while (42)
	{
		c = ft_calloc(2, 1);
		ct = read(fd, c, 1);
		if (*c == '\n' || ct == 0)
		{
			free(c);
			break;
		}
		tmp = ft_strjoin(buf, c);
		free(buf);
		free(c);
		buf = tmp;
	}
	if (!ct)
		return (NULL);
	return (buf);
}

/*
	Opens file by name or path/name and returns a list
	address to a copied file on an allocated memory segment in
	RAM in a list structure, delimited by newline
*/
t_list	**file_to_heap(char *name)
{
	t_list	**file;
	char	*row;
	int		fd;

	fd = open(name, O_RDONLY);
	if (!fd)
		exit(0);
	file = ft_calloc(1, sizeof(t_list *));
	row = read_line(fd);
	while (row)
	{
		ft_lstadd_back(file, ft_lstnew(row));
		row = read_line(fd);
	}
	return (file);
}
