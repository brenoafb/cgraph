#include "graph.h"

void initialize_graph(graph *g, bool directed) {
  if (!g) return;

  g->nedges = 0;
  g->nvertices = 0;
  g->directed = directed;

  for (int i = 0; i < MAXV; i++) {
    g->edges[i] = NULL;
    g->degrees[i] = 0;
  }
}

void deinit_list(edgenode *e) {
  if (e) {
    edgenode *p = e->next;
    free(e);
    deinit_list(p);
  }
}

void deinit_graph(graph *g) {
  if (!g) return;
  for (int i = 0; i < MAXV; i++) {
    if (g->edges[i]) {
      deinit_list(g->edges[i]);
    }
  }
}

void read_graph_file(graph *g, bool directed, bool weighted, FILE *fp) {
  if (!g) return;
  if (!fp) return;
  initialize_graph(g, directed);

  int nedges;
  fscanf(fp, "%d %d", &g->nvertices, &nedges);

  for (int i = 0; i < nedges; i++) {
    int x, y;
    int w = 0;
    if (weighted) {
      fscanf(fp, "%d %d %d", &x, &y, &w);
    } else {
      fscanf(fp, "%d %d", &x, &y);
    }
    insert_edge(g, x, y, w, directed);
  }
}

void insert_edge(graph *g, int x, int y, int w, bool directed) {
  if (!g) return;

  edgenode *p = malloc(sizeof(edgenode));
  p->v = y;
  p->weight = w;
  p->next = g->edges[x];
  g->edges[x] = p;
  g->degrees[x]++;

  if (!directed) {
    insert_edge(g, y, x, w, !directed);
  } else {
    g->nedges++;
  }
}

void print_list(edgenode *e) {
  if (!e) {
    printf("_\n");
  } else {
    printf("%d -> ", e->v);
    print_list(e->next);
  }
}

void print_graph(graph *g) {
  for (int i = 0; i < MAXV; i++) {
    if (g->edges[i]) {
      printf("%d -> ", i);
      print_list(g->edges[i]);
    }
  }
}
