#include <stdio.h>
#include <stdbool.h>
#include "graph.h"
#include "bfs.h"

void process_edge(int u, int v);
void process_vertex_early(int v);
void process_vertex_late(int v);

int main(void) {
  graph g;
  read_graph(&g, false);
  print_graph(&g);

  bfs_data data;
  init_bfs(&g, &data);
  data.process_edge = process_edge;
  data.process_vertex_early = process_vertex_early;
  data.process_vertex_late = process_vertex_late;

  bfs(&g, &data, 0);

  deinit_graph(&g);
}

void process_edge(int u, int v) {
  printf("Found edge (%d,%d)\n", u, v);
}

void process_vertex_early(int v) {
  printf("Found vertex %d\n", v);
}

void process_vertex_late(int v) {
  printf("Done processing vertex %d\n", v);
}
