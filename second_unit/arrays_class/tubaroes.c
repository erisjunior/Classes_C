#include <stdio.h>

int main(){
	int quantidade, foto, i, especies = 0;
	int apareceu[15] = {0};

	scanf("%d", &quantidade);

	for(i=0; i<quantidade; i++){
		scanf("%d", &foto);

		if(apareceu[foto] == 0){
			especies++;
			apareceu[foto] = 1;
		}
	}

	printf("%d especies diferentes.\n", especies);

	for(i=1; i<=14; i++){
		if(apareceu[i] == 1){
			switch(i){
				case 1: printf("Tubarão Branco");break;
				case 2: printf("Tubarão Martelo");break;
				case 3: printf("Tubarão Touro");break;
				case 4: printf("Tubarão Baleia");break;
				case 5: printf("Tubarão Lixa");break;
				case 6: printf("Tubarão Frade");break;
				case 7: printf("Tubarão Tigre");break;
				case 8: printf("Tubarão Cabeça-chata");break;
				case 9: printf("Tubarão Serra");break;
				case 10: printf("Tubarão de Pontas Negras");break;
				case 11: printf("Tubarão Raposa");break;
				case 12: printf("Tubarão Mako");break;
				case 13: printf("Tubarão Bruxa");break;
				case 14: printf("Tubarão Azul");break;
			}

			printf("\n");
		}
	}

	return 0;
}