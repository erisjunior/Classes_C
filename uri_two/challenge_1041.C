#include <stdio.h>

int main () {

  double positionX,positionY;

  scanf("%lf%lf", &positionX,&positionY);

  if(positionX == 0.0 && positionY == 0.0){
    printf("Origem\n");
  }else if(positionX == 0.0){
    printf("Eixo X\n");
  }else if(positionY == 0.0){
    printf("Eixo Y\n");
  }else if(positionX > 0.0 && positionY > 0.0){
    printf("Q1\n");
  }else if(positionX < 0.0 && positionY > 0.0){
    printf("Q2\n");
  }else if(positionX < 0.0 && positionY < 0.0){
    printf("Q3\n");
  }else if(positionX > 0.0 && positionY < 0.0){
    printf("Q4\n");
  }

  return 0;
}
