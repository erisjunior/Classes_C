#include <stdio.h>

int main() {
  int i, textLength;
  int numberOfA = 0;
  int numberOfE = 0;
  int numberOfI = 0;
  int numberOfO = 0;
  int numberOfU= 0;
  char letter;

  scanf("%d", &textLength);

  for(i = 0; i < textLength; i++){
    scanf(" %c", &letter);

    if(letter == 65 || letter == 97) numberOfA++;
    if(letter == 69 || letter == 101) numberOfE++;
    if(letter == 73 || letter == 105) numberOfI++;
    if(letter == 79 || letter == 111) numberOfO++;
    if(letter == 85 || letter == 117) numberOfU++;
  }

  if(numberOfA == numberOfE && numberOfE == numberOfI && numberOfI == numberOfO && numberOfO == numberOfU){
    printf("Mensagem secreta!\n");
  }else{
    printf("Mensagem normal!\n");
  }

  return 0;
}
