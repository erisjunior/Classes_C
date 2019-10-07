#include <stdio.h>

int main () {

  int valueA;
  int valueB;
  int valueC;
  int valueD;

  scanf("%d", &valueA);
  scanf("%d", &valueB);
  scanf("%d", &valueC);
  scanf("%d", &valueD);

  if(valueB > valueC && 
    valueD > valueA && 
    valueC+valueD > valueA+valueB &&
    valueC >= 0 && valueD >= 0 &&
    valueA % 2 == 0
  ){
    printf("Valores aceitos\n");
  }else{
    printf("Valores nao aceitos\n");
  }

  return 0;
}
