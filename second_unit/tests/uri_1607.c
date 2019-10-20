#include <stdio.h>
#include <string.h>

int main(){
  int cases, i, u, aux, steps = 0;
  char words[2][10000];

  scanf("%d", &cases);

  for(i = 0; i < cases; i++){
    scanf("%s %s", &words[0], &words[1]);

    for(u = 0; u < strlen(words[0]); u++){
      if(words[0][u] > words[1][u]){
        printf("%d\n", 'z'- words[0][u]);
        printf("%d\n", words[1][u]);
        aux = ('z' - words[0][u]) + (words[1][u] + 1 - 'a');
      }else {
        aux = words[1][u] - words[0][u];
      }

      steps += aux;
    }

    printf("%d\n", steps);
  }


  return 0;
}
