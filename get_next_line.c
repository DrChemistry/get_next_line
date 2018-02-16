#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void feed_up(char *save, char **line)
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

int get_next_line(const int fd, char **line)
{
  static char *save;
  char        *buff;
  int         x;
  int         tmp;

  if (!save && !(save = ft_strnew(BUFF_SIZE + 1)))
    return (-1);
  x = 0;
  if (save[0] != '\0')
  {
    if ((x = ft_findchar(save, '\n')) > -1)
    {
      if (feed_up(save, line, x, tmp) == -1)
        return (-1);
      return (1);
    }
  }
  tmp = 0;
  while ((tmp = read(fd, buff, BUFF_SIZE)))
  {
    if (!(save = ft_strcat(buff, save)))
      return (-1);
    if ((x = ft_findchar(save, '\n') > -1))
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
  }
  if (tmp == 0 && (x = ft_findchar(save, '\n') > -1)
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
  else if (tmp == 0)
    return (0);
  return (-1);
}
