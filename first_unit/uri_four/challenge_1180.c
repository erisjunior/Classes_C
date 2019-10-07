#include <stdio.h>

int main() {
  int quantidade, i, num, menor, posicao;

  scanf("%d\n", &quantidade);

  for (i = 0; i < quantidade; i++) {
    scanf("%d", &num);

    if( num < menor || i == 0 ) {
      menor = num;
      posicao = i;
    }
  }

  printf("Menor valor: %d\n", menor);
  printf("Posicao: %d\n", posicao);

  return 0;
}
