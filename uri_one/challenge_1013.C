#include <stdio.h>
#include <stdlib.h>

int main () {

  int valueA;
  int valueB;
  int valueC;

  int biggerOfAB;
  int biggerOfAll;

  scanf("%d%d%d", &valueA, &valueB, &valueC);

  biggerOfAB = (valueA + valueB + abs(valueA - valueB)) / 2;
  biggerOfAll = (biggerOfAB + valueC + abs(biggerOfAB - valueC)) / 2;

  printf("%d eh o maior\n", biggerOfAll);
  
  return 0;
}
