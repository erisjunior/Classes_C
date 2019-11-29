#include <stdio.h>


int main(){
  int times, i, peaks = 0, subindo = 0, descendo = 0;
  int aux[2] = {0,0};

  scanf("%d", &times);

  do {
    for (i = 0; i < times; i++) {
      scanf("%d", &aux[1]);

      if(i != 0 ){
        if(aux[0] > aux[1] ){
          descendo++;
          if(subindo == 1){
            subindo--;
            peaks++;
          }
        }else if(aux[0] < aux[1] ){
          subindo++;
          if(descendo == 1){
            descendo--;
            peaks++;
          }
        }

        if(i == times - 1) {
          if(descendo == 1 || subindo == 1){
            peaks++;
          }
        }
      }else{
        peaks++;
      }

      aux[0] = aux[1];
    }

    printf("%d picos!\n", peaks);

    scanf("%d", &times);

  } while(times > 0);

	return 0;
}
