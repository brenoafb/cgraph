#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 1000

typedef struct edgenode {
  int v;
  int weight;
  struct edgenode *next;
} edgenode;

void deinit_list(edgenode *e);
void print_list(edgenode *e);

typedef struct graph {
  edgenode *edges[MAXV];
  int degrees[MAXV];
  int nedges;
  int nvertices;
  bool directed;
} graph;

void initialize_graph(graph *g, bool directed);
void deinit_graph(graph *g);
void read_graph(graph *g, bool directed, bool weighted);
void insert_edge(graph *g, int x, int y, int w, bool directed);
void print_graph(graph *g);
