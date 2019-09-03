#include "bfs.h"

void init_bfs(graph *g, bfs_data *data) {
  assert(g);
  assert(data);

  for (int i = 0; i < g->nvertices; i++) {
    data->processed[i] = false;
    data->discovered[i] = false;
    data->parent[i] = NIL;
  }
}

void bfs(graph *g, bfs_data *data, int start) {
  assert(g);
  assert(data);
  queue q;
  init_queue(&q);
  enqueue(&q, start);

  data->discovered[start] = true;

  while (!is_empty_queue(&q)) {
    int y = dequeue(&q);

    if (data->process_vertex_early) {
      data->process_vertex_early(y);
    }
    data->processed[y] = true;

    edgenode *p = g->edges[y];
    while (p) {
      int v = p->v;
      if (g->directed || !data->processed[v]) {
        if (data->process_edge) {
          data->process_edge(y, v);
        }
      }
      if (!data->discovered[v]) {
        enqueue(&q, v);
        data->discovered[v] = true;
        data->parent[v] = y;
      }
      p = p->next;
    }

    if (data->process_vertex_late) {
      data->process_vertex_late(y);
    }
  }
}
