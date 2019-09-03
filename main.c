#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

int main(void) {
  graph g;
  read_graph(&g, false);
  print_graph(&g);
  deinit_graph(&g);
}

