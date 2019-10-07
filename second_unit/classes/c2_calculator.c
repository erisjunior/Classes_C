#include <stdio.h>

int calc(int num1, int num2, char identifier) {
  switch(identifier) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/':
      if(num2 == 0) {
        printf("Não divido por zero\n");
        exit(1);
      }
      return num1 / num2;
  }
}

int main() {
  int num1, num2;
  char identifier;

  scanf("%d %c%d", &num1,&identifier,&num2);

  printf("%d\n", calc(num1,num2,identifier));

  return 0;
}
