#include "path.h"

void init_path_data(path_data *data, int start) {
  data->start = start;
  for (int i = 0; i < MAXV; i++) {
    data->intree[i] = false;
    data->distance[i] = INT_MIN;
    data->parent[i] = NIL;
  }
  data->distance[start] = 0;
}

void dijkstra_reversed(graph *g, path_data *data) {
  int u = data->start;

  while (!data->intree[u]) {
    data->intree[u] = true;
    edgenode *p = g->edges[u];
    while (p) {
      int v = p->v;
      int weight = p->weight;
      if (data->distance[v] < (data->distance[u] + weight)) {
	        data->distance[v] = data->distance[u] + weight;
	        data->parent[v] = u;
      }
      p = p->next;
    }

    u = 0;
    int dist = INT_MIN;
    
    for (int i = 0; i < g->nvertices; i++) {
      if (!data->intree[i] && (dist < data->distance[i])) {
	      dist = data->distance[i];
	      u = i;
      }
    }
  }
}
