#include <stdio.h>
#include <string.h>

int sum(int num1, int num2){
  int len1 = strlen(num1);
  int len2 = strlen(num2);

  return 10;
}

int sub(int num1, int num2){
  return 10;
}

int mult(int num1, int num2){
  return 10;
}

int div(int num1, int num2){
  printf("Não funciona!!\n\n");
  return 1300135;
}

int calc(int num1, int num2, char identifier) {
  switch(identifier) {
    case '+': sum(num1, num2);
    case '-': sub(num1, num2);
    case '*': mult(num1, num2);
    case '/': div(num1, num2);
  }
}

int main() {
  char num1[1000], num2[1000];
  char identifier;

  printf("Bem vindos à CALCULADORONA!!\n\n");
  printf("Escreva dois numeros GIGANTES separados pelo sinal da conta\n");
  printf("Exemplo: 1.1e+23 * 2.3e+18\n\n");
  printf("Calculos disponiveis: \n");
  printf("+ | Adição \n");
  printf("- | Subtração \n");
  printf("* | Multiplicação \n");
  printf("/ | Divisão \n");

  while(1) {
    scanf("%s %c%s", num1, &identifier, num2);

    if(num1[0] == 'S') return 0;

    printf("%d\n", calc(num1,num2,identifier));

  }

  return 0;
}
