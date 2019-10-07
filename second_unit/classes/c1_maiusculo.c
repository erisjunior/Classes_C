#include <stdio.h>

int main() {
  char letra;

  scanf(" %c", &letra);

  while(letra != '\n'){
    if(letra > 64 && letra < 91){
      printf("%c", letra+32);
    }else if(letra > 96 && letra < 123){
      printf("%c", letra-32);
    }
    scanf("%c", &letra);
  }

  printf("\n");

  return 0;
}
