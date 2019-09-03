#include "stack.h"

void init_stack(stack *s) {
  assert(s);
  s->n = 0;
}

void init_stack_array(stack *s, int a[], int n) {
  init_stack(s);
  for (int i = 0; i < n; i++) {
    push_stack(s, a[i]);
  }
}

void push_stack(stack *s, int x) {
  assert(s);
  s->a[s->n++] = x;
}

bool is_empty_stack(stack *s) {
  assert(s);
  assert(s->n > 0);
  return s->n == 0;
}

int pop_stack(stack *s) {
  assert(s);
  assert(s->n > 0);
  return s->a[--s->n];
}
