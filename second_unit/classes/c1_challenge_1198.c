#include <stdio.h>
#include <stdlib.h>

int main () {
  long int n1, n2;

  while(scanf("%Ld %Ld", &n1, &n2) != EOF)
    printf("%Ld\n", abs(n1-n2));


  return 0;
}
