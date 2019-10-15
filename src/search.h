#pragma once
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "graph.h"
#include "queue.h"

#define NIL (-1)
#define TREE (0)
#define BACK (1)
#define FORWARD (2)
#define CROSS (3)

typedef struct search_data {
  bool processed[MAXV];
  bool discovered[MAXV];
  int parent[MAXV];
  int time;
  int entry_time[MAXV];
  int exit_time[MAXV];
  void (*process_vertex_early)(int v);
  void (*process_vertex_late)(int v);
  void (*process_edge)(int u, int v);
} search_data;

void init_search_data(graph *g, search_data *data);
void bfs(graph *g, search_data *data, int start);
void dfs(graph *g, search_data *data, int start);
int edge_classification(search_data *data, int x, int y);
