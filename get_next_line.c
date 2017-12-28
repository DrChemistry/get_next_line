#include <unistd.h>
#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
  static char *save;
  char        *str;
  char        *buffer;

  while (read(fd, buffer, BUFF_SIZE))
  {
    printf("%s\n", buffer);
  }
  return (-1);
}
