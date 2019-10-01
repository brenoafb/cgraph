#include "search.h"

void init_search_data(graph *g, search_data *data) {
  assert(g);
  assert(data);

  data->time = 0;
  for (int i = 0; i < g->nvertices; i++) {
    data->processed[i] = false;
    data->discovered[i] = false;
    data->parent[i] = NIL;
    data->entry_time[i] = INT_MAX;
    data->exit_time[i] = INT_MAX;
  }
}

void bfs(graph *g, search_data *data, int start) {
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

void dfs(graph *g, search_data *data, int v) {
  assert(g);
  assert(data);

  data->process_vertex_early(v);
  data->time += 1;
  data->discovered[v] = true;
  data->entry_time[v] = data->time;

  edgenode *ptr = g->edges[v];
  while (ptr) {
    if (!data->discovered[ptr->v]) {
      data->parent[ptr->v] = v;
      data->process_edge(v, ptr->v);
      dfs(g, data, ptr->v);
    } else if (!data->processed[ptr->v] || g->directed) {
      data->process_edge(v, ptr->v);
    }
    ptr = ptr->next;
  }

  data->processed[v] = true;
  data->process_vertex_late(v);
  data->time += 1;
  data->exit_time[v] = data->time;
}

int edge_classification(search_data *data, int x, int y) {
  if (data->parent[y] == x) return TREE;
  if (data->discovered[y] && !data->processed[y]) return BACK;
  if (data->processed[y] && (data->entry_time[y] > data->entry_time[x]))
    return FORWARD;
  if (data->processed[y] && (data->entry_time[y] < data->entry_time[x]))
    return CROSS;

  return NIL;
}













