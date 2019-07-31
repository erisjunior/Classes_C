#include <stdio.h>

int main () {

  int code;
  int qnt;
  float price;

  scanf("%d", &code);
  scanf("%d", &qnt);

  switch (code) {
    case 1:
      price = qnt * 4.00;
    break;

    case 2:
      price = qnt * 4.50;
    break;

    case 3:
      price = qnt * 5.00;
    break;

    case 4:
      price = qnt * 2.00;
    break;

    case 5:
      price = qnt * 1.50;
    break;

    default:
      price = qnt;
  }

  printf("Total: R$ %.2f\n", price);

  return 0;
}
