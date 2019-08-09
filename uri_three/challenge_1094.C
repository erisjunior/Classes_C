#include <stdio.h>

int main () {

  int total = 0;
  int totalC = 0;
  int totalR = 0;
  int totalS = 0;
  int totalTestCases, auxValue, i;
  float percentC, percentR, percentS = 0.0;
  char auxChar;

  scanf("%d", &totalTestCases);

  for(i = 0; i < totalTestCases; i++){
    scanf("%d", &auxValue);
    scanf(" %c", &auxChar);

    total += auxValue;

    if(auxChar == 'C') totalC += auxValue;
    if(auxChar == 'R') totalR += auxValue;
    if(auxChar == 'S') totalS += auxValue;
  }

  percentC = (100.00*totalC)/total;
  percentR = (100.00*totalR)/total;
  percentS = (100.00*totalS)/total;

  printf("Total: %d cobaias\n", total);
  printf("Total de coelhos: %d\n", totalC);
  printf("Total de ratos: %d\n", totalR);
  printf("Total de sapos: %d\n", totalS);
  printf("Percentual de coelhos: %.2f %%\n", percentC);
  printf("Percentual de ratos: %.2f %%\n", percentR);
  printf("Percentual de sapos: %.2f %%\n", percentS);

  return 0;
}
