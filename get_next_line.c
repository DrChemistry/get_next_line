#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char *re_alloc(char *str, int i)
{
  char  *dest;
  int   x;

  if (!(dest = malloc(sizeof(char) * i + BUFF_SIZE + 1)))
    return (NULL);
  x = -1;
  while (++x < i)
    dest[x] = str[x];
    free(str);
  return (dest);
}

char  *concatenate(char *src, char *buff)
{
  int x;
  int b;
  char  *dest;

  x = 0;
  while (src[x])
    ++x;
  if (!(dest = malloc(sizeof(char) * (x + BUFF_SIZE + 1))))
    return (NULL);
  x = 0;
  b = 0;
  while (src[x])
    dest[b++] = src[x++];
  x = 0;
  while (buff[x])
    dest[b++] = buff[x++];
  dest[b] = 0;
  free(src);
  return (dest);
}

int check_car(char *save, char c)
{
  int x;

  x = 0;
  while (save[x])
  {
    if (save[x] == c)
    return (x);
    ++x;
  }
  return (-1);
}

char  *ft_cpto(char *save, char *dest, int c)
{
  int  x;

  x = 0;
  if (!(dest = malloc(sizeof(char) * c + 1)))
    return (NULL);
  while (x < c)
  {
    dest[x] = save[x];
    ++x;
  }
  dest[x] = 0;
  return (dest);
}

void destroy_last(char *save, int tmp)
{
  int x;

  x = 0;
  while (x < tmp)
  save[x++] = 0;
  x = 0;
  while (save[++tmp])
    save[x++] = save[tmp];
  save[x] = 0;
}

int get_next_line(const int fd, char **line)
{
  static char *save;
  char        *buffer;
  int         x;
  int         tmp;

  if (!save)
  {
    if (!(save = malloc(sizeof(char) * 2)))
      return (-1);
    save[0] = 0;
  }
  else
  {
    if ((tmp = check_car(save, '\n')) != -1)
      {
        if (!(line[0] = ft_cpto(save, line[0], tmp)))
          return (-1);
        destroy_last(save, tmp);
        return (0);
      }
  }
  if (!(buffer = malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (-1);
  while ((x = read(fd, buffer, BUFF_SIZE)))
  {
    buffer[x] = 0;
    if (!(save = concatenate(save, buffer)))
      return (-1);
    if ((tmp = check_car(save, '\n')) != -1)
      {
        if (!(line[0] = ft_cpto(save, line[0], tmp)))
          return (-1);
        destroy_last(save, tmp);
        free(buffer);
        return (0);
      }
  }
  free(save);
  return (-1);
}
