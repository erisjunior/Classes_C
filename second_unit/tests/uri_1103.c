#include <stdio.h>
#include <stdbool.h>

int main(){
  int h1, m1, h2, m2, init, end, time;

  while(true) {
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    if(h1 == 0 && h1 == h2 && h2 == m1 && m1 == m2) break;

    if(h1 == 0) init = 24*60 + m1;
    else init = h1*60 + m1;

    if(h2 == 0) end = 24*60 + m2;
    else end = h2*60 + m2;

    if(end > init) time = end-init;
    else time = 24*60 - (init-end);

    printf("%d\n", time);
  }

  return 0;
}
