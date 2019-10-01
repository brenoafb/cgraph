#include <stdio.h>
#include <stdbool.h>
#include "graph.h"
#include "search.h"

void process_edge(int u, int v);
void process_vertex_early(int v);
void process_vertex_late(int v);

int main(void) {
  graph g;
  read_graph(&g, false);
  print_graph(&g);

  search_data data;
  init_search_data(&g, &data);
  data.process_edge = process_edge;
  data.process_vertex_early = process_vertex_early;
  data.process_vertex_late = process_vertex_late;

  printf("BFS\n");
  bfs(&g, &data, 0);

  init_search_data(&g, &data);

  printf("\nDFS\n");
  dfs(&g, &data, 0);

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
