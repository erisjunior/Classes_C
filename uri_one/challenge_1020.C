#include <stdio.h>

int main () {

  const int monthsInDays = 30;
  const int yearsInDays =  365;

  int days;

  int years = 0;
  int months = 0;

  scanf("%d", &days);

  while(days > 0){
    if(days >= yearsInDays){
      years++;
      days -= yearsInDays;
    }else if(days >= monthsInDays){
      months++;
      days -= monthsInDays;
    }else{
      break;
    }
  }

  printf("%d ano(s)\n", years);
  printf("%d mes(es)\n", months);
  printf("%d dia(s)\n", days);
  
  return 0;
}
