#include <stdio.h>

int main () {

  int total = 0;
  int totalI = 0;
  int totalG = 0;
  int totalD = 0;
  int auxChoose = 1;
  int gG, gI;

  while(auxChoose == 1){
    if(auxChoose == 1){
      scanf("%d", &gI);
      scanf("%d", &gG);

      total++;

      if(gI > gG) totalI++;
      if(gI < gG) totalG++;
      if(gI == gG) totalD++;
    }
    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d", &auxChoose);
  }

  printf("%d grenais\n", total);
  printf("Inter:%d\n", totalI);
  printf("Gremio:%d\n", totalG);
  printf("Empates:%d\n", totalD);

  if(totalI > totalG){
    printf("Inter venceu mais\n");
  }else if(totalI > totalG){
    printf("Gremio venceu mais\n");
  }else{
    printf("Não houve vencedor\n");
  }

  return 0;
}
