#include <stdio.h>
#include <stdlib.h>

//Em homenagem a Ana Victoria

int main(){
  int cidade[100] = {0};
  int mais_alto = 0, predios;
  float media_altura;
  int i, j, lotes;

  lotes = carrega_cidade(cidade);

  media_altura = funcao_media(lotes, cidade);
  procura_maior(lotes, cidade, &mais_alto);

  printf("Maior altura: %d\n", mais_alto);
  printf("Altura Média: %.2f\n", media_altura);

  i=lotes/3;

  while(i>0){
    j = rand()%lotes + 1;
    if(cidade[j] > 0){
      printf("Derruba prédio no lote %d\n", j);
      derruba_predio(j, cidade, lotes, &mais_alto, &media_altura);
    }
    else
      i++;
    i--;
  }

  printf("Maior altura: %d\n", mais_alto);
  printf("Altura Média: %.2f\n", media_altura);

  imprime_alturas_ordenadas(lotes, cidade);

  return 0;
}
