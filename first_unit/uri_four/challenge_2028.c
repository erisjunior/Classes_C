#include <stdio.h>

int main() {
  int i, u, indice = 0, num, nums;

  while(scanf("%d", &num) != EOF) {
    indice++;
    nums = ((num *(num+1))/2) + 1;

    if(nums == 1) printf("Caso %d: %d numero\n", indice, nums);
    else printf("Caso %d: %d numeros\n", indice, nums);

    for( i = 0; i <= num; i++){
      if( i == 0 ) printf("0");
      else {
        for( u = 0; u < i; u++) printf(" %d", i);
      }
    }
    printf("\n\n");

  }

  return 0;
}
