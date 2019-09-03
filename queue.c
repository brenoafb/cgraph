#include "queue.h"

void init_queue(queue *q) {
  assert(q);
  q->start = 0;
  q->end = 0;
}

bool is_empty_queue(queue *q) {
  assert(q);
  return q->end == q->start;
}

void enqueue(queue *q, int x) {
  assert(q);
  q->a[(q->end++)%MAXQ] = x;
}

int dequeue(queue *q) {
  assert(q);
  assert(!is_empty_queue(q));
  return q->a[(q->end--)%MAXQ];
}
