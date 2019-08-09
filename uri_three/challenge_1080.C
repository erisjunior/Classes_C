#include <stdio.h>

int main () {

  int value, index, i;
  int finishValue = 0;

  for(i = 1; i <= 100; i++){
    scanf("%d", &value);
    if(finishValue < value){
      finishValue = value;
      index = i;
    }
  }

  printf("%d\n", finishValue);
  printf("%d\n", index);

  return 0;
}
