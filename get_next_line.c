#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
  static char *save;
  char        *str;
  char        *buffer;

  if (!(buffer = malloc(sizeof(char) * BUFF_SIZE + 1)))
    return (-1);
  while (read(fd, buffer, BUFF_SIZE))
  {
    printf("%s\n", buffer);
  }
  return (-1);
}
