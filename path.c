#include "path.h"

void init_path_data(graph *g, path_data *data) {
  for (int i = 0; i < MAXV; i++) {
    data->intree[i] = false;
    data->distance[i] = INT_MAX;
    data->parent[i] = NIL;
  }
}

void dijkstra(graph *g, int start, path_data *data) {
  data->parent[start] = 0;
  int u = start;

  while (!data->intree[u]) {
    data->intree[u] = true;
    edgenode *p = g->edges[u];
    while (p) {
      int v = p->v;
      int weight = p->weight;
      if (data->distance[v] > data->distance[u] + weight) {
	data->distance[v] = data->distance[u] + weight;
	data->parent[v] = u;
      }
      p = p->next;
    }

    u = 0;
    int dist = INT_MAX;
    for (int i = 0; i < g->nvertices; i++) {
      if (!data->intree[i] && (dist > data->distance[i])) {
	dist = data->distance[i];
	u = i;
      }
    }
  }
}
