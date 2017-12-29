#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
int get_next_line(const int, char **);

int ft_strlen(char *str)
{
  int x;

  while (str[x])
  ++x;
  return (x);
}

int main(int ac, char **av)
{
  char **line;
  int fd;
  line = malloc(sizeof(char *) * 1);
  if (ac == 2)
  {
    fd = open(av[1], O_RDONLY);
  }
  else
    fd = 0;
  while (get_next_line(fd, line) == 0)
  {
    printf("%s\n", line[0]);
    free(line[0]);
  }
  return (0);
}
