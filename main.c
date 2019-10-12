#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "graph.h"
#include "stack.h"
#include "search.h"
#include "path.h"

void process_edge(int u, int v);
void process_vertex_early(int v);
void process_vertex_late(int v);
void topological_sort(graph *g);
void read_labels(FILE *fp, int labels[], int n);

stack s;
search_data data;

int main(void) {
  graph g;
  read_graph(&g, true, true);
  int labels[g.nvertices];
  FILE *fp= fopen("g1.txt", "r");
  read_labels(fp, labels, g.nvertices);
  // print_graph(&g);

  topological_sort(&g);

  int order[g.nvertices];

  printf("\n");
  for (int i = 0; i < g.nvertices; i++) {
    order[i] = pop_stack(&s);
    printf("%d\n", labels[order[i]]);
  }


  /*
  path_data data;
  init_path_data(&data, 0);
  dijkstra(&g, &data);

  printf("Shortest distances from vertex 0:\n");
  for (int i = 0; i < g.nvertices; i++) {
    printf("%d: %d\n", i, data.distance[i]);
  }
  */

  deinit_graph(&g);
}

void process_edge(int u, int v) {
  // printf("Found edge (%d,%d)\n", u, v);
  int class = edge_classification(&data, u, v);
  if (class == BACK) {
    printf("Warning: found back edge (not a DAG)\n");
  }
}

void process_vertex_early(int v) {
  // printf("Found vertex %d\n", v);
  return;
}

void process_vertex_late(int v) {
  // printf("Done processing vertex %d\n", v);
  push_stack(&s, v);
}

void topological_sort(graph *g) {
  init_stack(&s);
  init_search_data(g, &data);
  data.process_edge = process_edge;
  data.process_vertex_early = process_vertex_early;
  data.process_vertex_late = process_vertex_late;

  for (int i = 0; i < g->nvertices; i++) {
    if (!data.discovered[i]) {
      dfs(g, &data, i);
    }
  }

  print_stack(&s);
}

void read_labels(FILE *fp, int labels[], int n) {
  if (!fp) return;

  int x, y;
  for (int i = 0; i < n; i++) {
    fscanf(fp, "%d %d", &x, &y);
    labels[x] = y;
  }
}
