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
  while (read(fd, buffer, BUFF_SIZE))
  {
    x = 0;
    if (!str && !(str = malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (-1);
    while (buffer[x] && buffer[x] != '\n')
        str[i++] = buffer[x++];
    write(1, "n", 1);
    if (buffer[x] == '\n')
    {
      str[i] = '\0';
      *line = str;
      return (0);
    }
  }
  return (-1);
}
