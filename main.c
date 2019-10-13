#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#include "stack.h"
#include "search.h"
#include "path.h"

#define MAXLEN 1024

void process_edge(int u, int v);
void process_vertex_early(int v);
void process_vertex_late(int v);
void topological_sort(graph *g);
void read_labels_file(int labels[], char *names[], int n, FILE *fp);

stack s;
search_data data;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./%s [graph file] [labels file]\n",
	   argv[0]);
  }

  char *graph_file = argv[1];
  char *labels_file = argv[2];
  graph g;
  FILE *fp = fopen(graph_file, "r");

  if (!fp) {
    printf("Error reading graph file %s\n", graph_file);
    return 1;
  }

  read_graph_file(&g, true, true, fp);

  fclose(fp);
  fp = fopen(labels_file, "r");

  if (!fp) {
    printf("Error reading labels file %s\n", labels_file);
    return 2;
  }

  int labels[g.nvertices];
  char names[g.nvertices][MAXLEN];
  read_labels_file(labels, g.nvertices, names, fp);

  fclose(fp);

  topological_sort(&g);

  int order[g.nvertices];
  printf("\nTopological sort:\n");
  for (int i = 0; i < g.nvertices; i++) {
    order[i] = pop_stack(&s);
    printf("%d %s\n", labels[order[i]], names[order[i]]);
  }

  path_data data;
  init_path_data(&data, order[0]);
  dijkstra_reversed(&g, &data);
  printf("\nLongest distance from %d to %d: %d\n",
	 order[0], order[g.nvertices-1], data.distance[g.nvertices-1]);

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

void read_labels_file(int labels[], char *names[], int n, FILE *fp) {
  if (!fp) return;

  int x, y;
  char tmp[MAXLEN];
  for (int i = 0; i < n; i++) {
    fscanf(fp, "%d %d %[^\n]", &x, &y, tmp);
    labels[x] = y;
    strcpy(names[x], tmp);
  }
}
