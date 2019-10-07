#include <stdio.h>

int main () {

  int nTestCases, value, i;
  int div5 = 0, div3 = 0, div2 = 0, div4 = 0;

  scanf("%d\n", &nTestCases);

  for(i = 0; i < nTestCases; i++){
    scanf("%d", &value);
    
    if(value%2 == 0) div2++;
    if(value%3 == 0) div3++;
    if(value%4 == 0) div4++;
    if(value%5 == 0) div5++;
  }

  printf("%d Multiplo(s) de 2\n", div2);
  printf("%d Multiplo(s) de 3\n", div3);
  printf("%d Multiplo(s) de 4\n", div4);
  printf("%d Multiplo(s) de 5\n", div5);

  return 0;
}
