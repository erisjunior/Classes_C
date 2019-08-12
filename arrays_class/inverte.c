#include <stdio.h>

int main(){
	int numeros[100];
	int i;

	for(i=0; i<5; i++){
		scanf("%d", &numeros[i]);
	}

	for(i=4; i>=0; i--){
		printf("%d\n", numeros[i]);
	}

	return 0;
}