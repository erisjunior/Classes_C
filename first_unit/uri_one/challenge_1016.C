#include <stdio.h>

int main () {

  int money;

  int cedules100 = 0;
  int cedules50 = 0;
  int cedules20 = 0;
  int cedules10 = 0;
  int cedules5 = 0;
  int cedules2 = 0;
  int cedules1 = 0;

  int auxMoney;

  scanf("%d", &money);

  auxMoney = money;

  while(auxMoney > 0){
    if(auxMoney >= 100){
      cedules100++;
      auxMoney -= 100;
    }else if(auxMoney >= 50){
      cedules50++;
      auxMoney -= 50;
    }else if(auxMoney >= 20){
      cedules20++;
      auxMoney -= 20;
    }else if(auxMoney >= 10){
      cedules10++;
      auxMoney -= 10;
    }else if(auxMoney >= 5){
      cedules5++;
      auxMoney -= 5;
    }else if(auxMoney >= 2){
      cedules2++;
      auxMoney -= 2;
    }else if(auxMoney >= 1){
      cedules1++;
      auxMoney -= 1;
    }
  }

  printf("%d\n", money);
  printf("%d nota(s) de R$ 100,00\n", cedules100);
  printf("%d nota(s) de R$ 50,00\n", cedules50);
  printf("%d nota(s) de R$ 20,00\n", cedules20);
  printf("%d nota(s) de R$ 10,00\n", cedules10);
  printf("%d nota(s) de R$ 5,00\n", cedules5);
  printf("%d nota(s) de R$ 2,00\n", cedules2);
  printf("%d nota(s) de R$ 1,00\n", cedules1);
  
  return 0;
}
