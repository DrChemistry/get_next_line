#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int get_next_line(const int, char **);

int main(int ac, char **av)
{
  char **line;
  int fd;
  int tmp;

  line = malloc(sizeof(char *) * 1);
  if (ac == 2)
    fd = open(av[1], O_RDONLY);
  else
    fd = 0;
  tmp = 0;
  //printf("%d\n", fd);
  while ((tmp = get_next_line(fd, line)) > 0)
  {
    printf("%s\n", *line);
    free(line[0]);
  }
  //printf("[%i]\n", tmp);
  free(line);
  return (0);
}
