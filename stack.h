#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *top;
  int n;
} stack;

void init_stack(stack *s);
void push_stack(stack *s, int x);
int is_empty_stack(stack *s);
int pop_stack(stack *s);
