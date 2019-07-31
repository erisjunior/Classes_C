#include <stdio.h>

int main () {

  float grade1;
  float grade2;
  float grade3;
  float grade4;
  float grade5;

  float average;

  scanf("%f", &grade1);
  scanf("%f", &grade2);
  scanf("%f", &grade3);
  scanf("%f", &grade4);

  average = (grade1 * 2 + grade2 * 3 + grade3 * 4 + grade4)/10;
  printf("Media: %.1f\n", average);

  if(average >= 7.0){
    printf("Aluno aprovado.\n");
  }else if(average < 5.0){
    printf("Aluno reprovado.\n");
  }else if(average >= 5.0 && average < 7.0 ){
    printf("Aluno em exame.\n");

    scanf("%f", &grade5);
    printf("Nota do exame: %.1f\n", grade5);
    average = (average + grade5)/2;

    if(average >= 5.0){
      printf("Aluno aprovado.\n");
    }else{
      printf("Aluno reprovado.\n");
    }
    printf("Media final: %.1f\n", average);
  }

  return 0;
}
