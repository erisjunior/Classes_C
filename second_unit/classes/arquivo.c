#include <stdio.h>

int conta_vogais(FILE* arquivo){
	int cont = 0;
	char palavra[100];

	while(fscanf(arquivo, " %s", palavra) != EOF){
		switch(palavra[0]){
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				cont++;
				break;
		}
	}

	return cont;
}

int main(){
	FILE* arquivo;
	int cont;

	arquivo = fopen("../poesia.txt", "r");

	if(arquivo == NULL)
		printf("Vixi... :~(\n");
	else{
		
		cont = conta_vogais(arquivo);

		printf("Existem %d palavras comecando com vogal!\n", cont);

		fclose(arquivo);
	}

	return 0;
}