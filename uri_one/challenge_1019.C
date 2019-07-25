#include <stdio.h>

int main () {

  const int minutesInSeconds = 60;
  const int hoursInSeconds =  60 * 60;

  int hours = 0;
  int minutes = 0;
  int seconds;

  scanf("%d", &seconds);

  while(seconds > 0){
    if(seconds >= hoursInSeconds){
      hours++;
      seconds -= hoursInSeconds;
    }else if(seconds >= minutesInSeconds){
      minutes++;
      seconds -= minutesInSeconds;
    }else{
      break;
    }
  }

  printf("%d:%d:%d\n", hours, minutes, seconds);
  
  return 0;
}
