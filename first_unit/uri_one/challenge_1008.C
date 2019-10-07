#include <stdio.h>

int main () {

  int employeeNumber;
  int workedHours;
  float receivedPerHour;
  float salary;

  scanf("%d", &employeeNumber);
  scanf("%d", &workedHours);
  scanf("%f", &receivedPerHour);

  salary = workedHours * receivedPerHour;

  printf("NUMBER = %d\n", employeeNumber);
  printf("SALARY = U$ %.2f\n", salary);

  return 0;
}
