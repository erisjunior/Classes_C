#include <stdio.h>
#include <stdlib.h>

int main() {
  int quantidade, i, u, num1, num2, num3, aux = 0;
  int ordem[10000] = {};

  scanf("%d\n", &quantidade);

  for(i = 0; i < 10000; i++){
		ordem[i] = 0;
	}

  for (i = 0; i < quantidade; i++) {
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    for(u = num1; u < num2; u++){
			if(num3 > ordem[u]){
				ordem[u] = num3;
			}
		}
  }

  for(i = 0; i < 10000; i++){
		if(ordem[i] != aux){
			printf("%d %d ", i, ordem[i]);
			aux = ordem[i];
		}
	}

  printf("\n");

  return 0;
}
