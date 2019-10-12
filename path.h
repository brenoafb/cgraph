#pragma once
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "graph.h"

#define NIL (-1)

typedef struct path_data {
  int start;
  bool intree[MAXV];
  int distance[MAXV];
  int parent[MAXV];
} path_data;

void init_path_data(path_data *data, int start);
void dijkstra(graph *g, path_data *data);
