#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void juntando_pecas(char *mensagem) {
	FILE* arquivo;
  char decoder[50];
  char word[50];
  mensagem[0] = '\0';

	arquivo = fopen("./pistas2.txt", "r");

	if(arquivo == NULL)
		printf("Vixi... :~(\n");
	else{
    fgets(decoder, 50, arquivo);

    while(fscanf(arquivo, "%s", word) != EOF) {
      if(word[0] - 65 == atoi(decoder) || word[0] - 97 == atoi(decoder)){
        strcat(mensagem, word);
        strcat(mensagem, " ");
      }
	  }

		fclose(arquivo);
	}
}

int* decodifica(char* mensagem, int* tam) {
  int i, cont = 0;
  int* codes = (int *) calloc (strlen(mensagem)/2, sizeof (int));
  for(i = 0; i <= strlen(mensagem); i++){
    if(i % 2 == 0) {
      if(mensagem[i] - 97 < 0){
        codes[cont] = mensagem[i] - 65;
      }else{
        codes[cont] = mensagem[i] - 97;
      }
      cont++;
    }
  }

  *tam = strlen(mensagem)/2;
  return codes;
}

void resposta_enigma(int* codes, int tam, char* mensagem) {
  FILE* arquivo;
  int i;
  arquivo = fopen("./riddle.txt", "w");

  fprintf(arquivo, "%s", "Resposta do Enigma\n");
  fprintf(arquivo, "%s", "Mensagem: ");
  fprintf(arquivo, "%s", mensagem);
  fprintf(arquivo, "%s", "\n");
  fprintf(arquivo, "%s", "Código do Cofre: ");
  for(i = 0; i < tam; i++){
    fprintf(arquivo, "%d", codes[i]);
    fprintf(arquivo, "%s", " ");
  }
  fprintf(arquivo, "%s", "\n");

  fclose(arquivo);
}

int main(){
    char mensagem[1000];
    int* codes;
    int tam;

    juntando_pecas(mensagem);

    codes = decodifica(mensagem, &tam);

    resposta_enigma(codes, tam, mensagem);

    return 0;
}
