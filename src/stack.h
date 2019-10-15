#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAXS 1000

typedef struct stack {
  int a[MAXS];
  int n;
} stack;

void init_stack(stack *s);
void init_stack_array(stack *s, int a[], int n);
void push_stack(stack *s, int x);
bool is_empty_stack(stack *s);
int pop_stack(stack *s);
void print_stack(stack *s);
