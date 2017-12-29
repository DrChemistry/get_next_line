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

int get_next_line(const int fd, char **line)
{
  static char *save;
  char        *str;
  char        *buffer;
  int         x;
  int         i;
  int         b;

  if (!(buffer = malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (-1);
  if (!(str = malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (-1);
  i = 0;
  x = 0;
  b = 0;
  if (save)
  {
    while (save[x] && save[x] != '\n')
    str[i++] = save[x++];
    if (save[x] == '\n')
    {
      str[i] = '\0';
      *line = str;
      return (0);
    }
    else
      free(save);
  }
  while (read(fd, buffer, BUFF_SIZE))
  {
    x = 0;
    while (buffer[x] && buffer[x] != '\n')
        str[i++] = buffer[x++];
    str[i] = '\0';
    if (buffer[x] == '\n')
    {
      if (buffer[x + 1] != '\0')
      {
        if (!(save = malloc(sizeof(char) * ft_strlen(buffer) - x)))
          return (-1);
        while (buffer[++x])
          save[b++] = buffer[x];
        save[b] = '\0';
      }
      *line = str;
      free(buffer);
      return (0);
    }
    if (!(str = re_alloc(str, i)))
      return (-1);
  }
  return (-1);
}
