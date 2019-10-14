#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int times, len, i, j;
  char aux;
	char word[10000];

	scanf("%d\n", &times);

	for(i = 0; i < times; i++){
		scanf(" %[^\n]s\n", word);

		len = strlen(word);

  	for(j = 0; j < len; j++){
      if(word[j] >= 97 && word[j] <= 122 || word[j] >= 65 && word[j] <= 90){
				word[j] += 3;
			}
		}

		for(j = 0; j < j/2; j++){
			aux = word[j];
			word[j] = word[len-1-j];
			word[len-1-j] = aux;
		}

		for (j = len/2; j < len; j++) {
			word[j] = word[j] - 1;
		}

		printf("%s\n", word);
	}

  return 0;
}
