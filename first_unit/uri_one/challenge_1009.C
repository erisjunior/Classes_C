#include <stdio.h>

int main () {

  char employeeName[100];
  double fixedSalary;
  double totalSold;
  double salary;

  scanf("%s", &employeeName);
  scanf("%lf", &fixedSalary);
  scanf("%lf", &totalSold);

  salary = fixedSalary + (totalSold * 0.15);

  printf("TOTAL = R$ %.2f\n", salary);

  return 0;
}
