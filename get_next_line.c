#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
  static char *save;
  char        *str;
  char        *buffer;
  int         x;
  int         i;

  if (!(buffer = malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (-1);
  i = 0;
  if (save)
  {
    if (cp_end(save, str, &i) == 1)
    {
      str[i] = '\0';
      *line = str;
      return (0);
    }
  }
  if (!(str = malloc(sizeof(char) * BUFF_SIZE + 1)))
  return (-1);
  while (read(fd, buffer, BUFF_SIZE))
  {
    x = 0;
    while (buffer[x] && buffer[x] != '\n')
        str[i++] = buffer[x++];
    if (buffer[x] == '\n')
    {
      str[i] = '\0';
      *line = str;
      return (0);
    }
    if (!(str = re_alloc(str, i)))
      return (-1);
  }
  return (-1);
}
