#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAXQ 1000

typedef struct queue {
  int a[MAXQ];
  int start;
  int end;
} queue;

void init_queue(queue *q);
bool is_empty_queue(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
