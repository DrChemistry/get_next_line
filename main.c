#include "get_next_line.h"

int get_next_line(const int, char **);

int main(int ac, char **av)
{
  char *line;
  get_next_line(0, &line);
  return (0);
}
