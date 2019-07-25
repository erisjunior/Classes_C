#include <stdio.h>

int main () {

  const double pi = 3.14159;

  double valueA;
  double valueB;
  double valueC;

  double triangleArea;
  double circleRadius;
  double trapeziumArea;
  double squareArea;
  double rectangleArea;

  scanf("%lf%lf%lf", &valueA, &valueB, &valueC);

  triangleArea = ( valueA * valueC )/2;
  circleRadius = ( valueC * valueC )*pi;
  trapeziumArea = ( ( valueA + valueB ) * valueC) / 2;
  squareArea = valueB * valueB;
  rectangleArea = valueA * valueB;

  printf("TRIANGULO: %.3lf\n", triangleArea);
  printf("CIRCULO: %.3lf\n", circleRadius);
  printf("TRAPEZIO: %.3lf\n", trapeziumArea);
  printf("QUADRADO: %.3lf\n", squareArea);
  printf("RETANGULO: %.3lf\n", rectangleArea);

  return 0;
}
