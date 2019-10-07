#include <stdio.h>

int main() {
  int num, numeros[10];
  int i;

  for (i = 0; i < 10; i++) {
    scanf("%d", &num);
    if (num < 1) num = 1;
    numeros[i] = num;
  }

  for (i = 0; i < 10; i++) {
    printf("X[%d] = %d\n", i, numeros[i]);
  }

  return 0;
}
