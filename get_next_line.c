#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

int	feed_up(char *save, char **line, int x, int tmp)
{
	if (!(line[0] = malloc(sizeof(char) * x + 1)))
		return (-1);
	line[0][x] = '\0';
	tmp = x;
	while (--x >= 0)
		line[0][x] = save[x];
	while (save[++tmp])
		save[++x] = save[tmp];
	save[++x] = '\0';
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save;
	char		buff[BUFF_SIZE + 1];
	int			x;
	int			tmp;

	if (!save && !(save = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (save[0] != '\0')
		if ((x = ft_findchar(save, '\n')) > -1)
			return (feed_up(save, line, x, tmp) == -1 ? -1 : 1);
	while ((tmp = read(fd, buff, BUFF_SIZE)))
	{
		buff[tmp] = '\0';
		if (!(save = ft_strjoin(buff, save)))
			return (-1);
		if ((x = ft_findchar(save, '\n') > -1))
			return (feed_up(save, line, x, tmp) == -1 ? -1 : 1);
	}
	if (tmp == 0 && (x = ft_findchar(save, '\n') > -1))
		return (feed_up(save, line, x, tmp) == -1 ? -1 : 1);
	else if (tmp == 0)
		return (0);
	return (-1);
}
