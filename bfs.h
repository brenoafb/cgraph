#pragma once
#include <stdbool.h>
#include <assert.h>
#include "graph.h"
#include "queue.h"

#define NIL (-1)

typedef struct bfs_data {
  bool processed[MAXV];
  bool discovered[MAXV];
  int parent[MAXV];
  void (*process_vertex_early)(int v);
  void (*process_vertex_late)(int v);
  void (*process_edge)(int u, int v);
} bfs_data;

void init_bfs(graph *g, bfs_data *data);
void bfs(graph *g, bfs_data *data, int start);
