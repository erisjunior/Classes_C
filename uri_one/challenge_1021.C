#include <stdio.h>

int main () {

  float money;

  int cedules100 = 0;
  int cedules50 = 0;
  int cedules20 = 0;
  int cedules10 = 0;
  int cedules5 = 0;
  int cedules2 = 0;
  
  int coin100 = 0;
  int coin50 = 0;
  int coin25 = 0;
  int coin10 = 0;
  int coin5 = 0;
  int coin1 = 0;

  scanf("%f", &money);

  while(money > 0){
    if(money >= 100){
      cedules100++;
      money -= 100;
    }else if(money >= 50){
      cedules50++;
      money -= 50;
    }else if(money >= 20){
      cedules20++;
      money -= 20;
    }else if(money >= 10){
      cedules10++;
      money -= 10;
    }else if(money >= 5){
      cedules5++;
      money -= 5;
    }else if(money >= 2){
      cedules2++;
      money -= 2;
    }else if(money >= 1){
      coin100++;
      money -= 1;
    }else if(money >= 0.50){
      coin50++;
      money -= 0.50;
    }else if(money >= 0.25){
      coin25++;
      money -= 0.25;
    }else if(money >= 0.10){
      coin10++;
      money -= 0.10;
    }else if(money >= 0.05){
      coin5++;
      money -= 0.05;
    }else{
      coin1++;
      money -= 0.01;
    }
  }

  printf("NOTAS:\n");
  printf("%d nota(s) de R$ 100,00\n", cedules100);
  printf("%d nota(s) de R$ 50,00\n", cedules50);
  printf("%d nota(s) de R$ 20,00\n", cedules20);
  printf("%d nota(s) de R$ 10,00\n", cedules10);
  printf("%d nota(s) de R$ 5,00\n", cedules5);
  printf("%d nota(s) de R$ 2,00\n", cedules2);
  printf("MOEDAS:\n");
  printf("%d moeda(s) de R$ 1,00\n", coin100);
  printf("%d moeda(s) de R$ 0,50\n", coin50);
  printf("%d moeda(s) de R$ 0,25\n", coin25);
  printf("%d moeda(s) de R$ 0,10\n", coin10);
  printf("%d moeda(s) de R$ 0,05\n", coin5);
  printf("%d moeda(s) de R$ 0,01\n", coin1);
  
  return 0;
}
