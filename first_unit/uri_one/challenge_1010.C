#include <stdio.h>

int main () {

  int productCodeOne;
  int productCodeTwo;
  int productQntOne;
  int productQntTwo;
  float productPriceOne;
  float productPriceTwo;

  float totalOne;
  float totalTwo;

  float total;

  scanf("%d%d%f", &productCodeOne, &productQntOne, &productPriceOne);
  scanf("%d%d%f", &productCodeTwo, &productQntTwo, &productPriceTwo);

  totalOne = productQntOne * productPriceOne;
  totalTwo = productQntTwo * productPriceTwo;

  total = totalOne + totalTwo;

  printf("VALOR A PAGAR: R$ %.2f\n", total);

  return 0;
}
