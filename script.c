#include <stdio.h>
#include <string.h>

#define MAX 33
#define MAXLEN 1024

int indexof(int x, int a[]) {
  for (int i = 0; i <= MAX; i++) {
    if (a[i] == x) return i;
  }

  return -1;
}

int main(void) {
  char *f1 = "labels_file.txt";
  char *f2 = "bcs.txt";

  int x, y;
  int labels[MAX+1];
  FILE *fp = fopen(f1, "r");
  for (int i = 0; i <= MAX; i++) {
    fscanf(fp, "%d %d", &x, &y);
    labels[x] = y;
  }

  fclose(fp);
  fp = fopen(f2, "r");
  int code;
  char names[MAX+1][MAXLEN];
  names[0][0] = '_'; names[0][1] = 0;
  char tmp[MAXLEN];
  for (int i = 0; i <= MAX; i++) {
    fscanf(fp, "%d %[^\n]", &code, tmp);
    int k = indexof(code, labels);
    if (k < 0) {
      printf("Warning: %d %s\n", code, tmp);
    } else {
      strcpy(names[k], tmp);
    }
  }

  for (int i = 1; i <= MAX; i++) {
    printf("%d %d %s\n", i, labels[i], names[i]);
  }

  fclose(fp);
}
