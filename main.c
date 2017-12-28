#include <stdio.h>
#include <stdlib.h>
int get_next_line(const int, char **);

int main(int ac, char **av)
{
  char **line;
  line = malloc(sizeof(char *) * 1);
  get_next_line(0, line);
  printf("%s\n", line[0]);
  return (0);
}
