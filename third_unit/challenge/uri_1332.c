# include <stdio.h>
# include <stdlib.h>

int isThree(char* word) {
  int count = 0;
  if(word[0] == 't') count++;
  if(word[1] == 'h') count++;
  if(word[2] == 'r') count++;
  if(word[3] == 'e') count++;
  if(word[4] == 'e') count++;

  return count > 3 ? 1 : 0;
}

int isTwo(char* word) {
  int count = 0;
  if(word[0] == 't') count++;
  if(word[1] == 'w') count++;
  if(word[2] == 'o') count++;

  return count > 1 ? 1 : 0;
}

int isOne(char* word) {
  int count = 0;
  if(word[0] == 'o') count++;
  if(word[1] == 'n') count++;
  if(word[2] == 'e') count++;

  return count > 1 ? 1 : 0;
}

int main() {
  int qnt, i;
  scanf("%d", &qnt);
  char word[10];

  for(i = 0; i < qnt; i++) {
    scanf(" %s", &word);

    if(isOne(word)){
      printf("1\n");
    }else if(isTwo(word)){
      printf("2\n");
    }else if(isThree(word)){
      printf("3\n");
    }else{
      printf("Sei lá\n");
    }
  }

  return 0;
}
