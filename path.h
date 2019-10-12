#pragma once
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "graph.h"

#define NIL (-1)

typedef struct path_data {
  bool intree[MAXV];
  int distance[MAXV];
  int parent[MAXV];
} path_data;

void init_path_data(graph *g, path_data *data);
void dijkstra(graph *g, int start, path_data *data);
