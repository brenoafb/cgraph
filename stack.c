#include "stack.h"

void init_stack(stack *s) {
  s->n = 0;
}

void init_stack_array(stack *s, int a[], int n) {
  init_stack(s);
  for (int i = 0; i < n; i++) {
    push_stack(s, a[i]);
  }
}

void push_stack(stack *s, int x) {
  s->a[s->n++] = x;
}

bool is_empty_stack(stack *s) {
  assert(s->n > 0);
  return s->n == 0;
}

int pop_stack(stack *s) {
  assert(s->n > 0);
  return s->a[--s->n];
}

void print_stack(stack *s) {
  for (int i = s->n-1; i >= 0; i--) {
    printf("%d ", s->a[i]);
  }
  printf("\n");
}
