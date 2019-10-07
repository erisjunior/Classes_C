#include <stdio.h>
#include <stdlib.h>

//Em homenagem a Ana Victoria

int carrega_cidade(int *cidade) {
  int i, lotes;
  scanf("%d", &lotes);

  for(i = 0; i < lotes; i++){
    scanf("%d", &cidade[i]);
  }

  return lotes;
}

float funcao_media(int lotes, int *cidade) {
  int i;
  float soma = 0;

  for(i = 0; i < lotes; i++){
    soma += cidade[i];
  }

  return soma/lotes;
}

void procura_maior(int lotes, int *cidade, int *mais_alto) {
  int i;

  for(i = 0; i < lotes; i++){
    if (cidade[i] > *mais_alto) *mais_alto = cidade[i];
  }
}

void derruba_predio(int j, int *cidade, int lotes, int *mais_alto, float *media_altura) {
  int maior;
  maior = cidade[j];
  cidade[j] = 0;


  if(maior == *mais_alto) {
    *mais_alto = 0;
    procura_maior(lotes, cidade, &*mais_alto);
  }

  *media_altura = funcao_media(lotes, cidade);
}

void imprime_alturas_ordenadas(int lotes, int *cidade) {
  int u, j, tmp;

  for (u = 0; u < lotes; u++) {
    for (j = 0; j < lotes; j++) {
      if (cidade[j] > cidade[u]) {
        tmp = cidade[u];
        cidade[u] = cidade[j];
        cidade[j] = tmp;
      }
    }
  }

  for (u = 0; u < lotes; u++) {
    if(cidade[u] > 0) printf("%d\n", cidade[u]);
  }
}

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
