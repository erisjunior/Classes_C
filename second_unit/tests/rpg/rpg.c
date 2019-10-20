#include <stdio.h>

void get_players(FILE* arquivo){
	char name[100], class[100];
  int str, dex, con, inte, wis, cha, totalWis, cont = 0, sum=0;
  int maxstr=0, maxdex=0, maxcon=0, maxinte=0, maxwis=0, maxcha=0, max=0;
  char topPlayer[100], topstr[10][100], topdex[10][100], topcon[10][100];
  char topinte[10][100], topwis[10][100], topcha[10][100];

  //Ignorar legenda
  fscanf(arquivo, "%s %s %s %s %s %s %s %s", name, name, name, name, name, name, name, name);

	while(fscanf(arquivo, "%s %s %d %d %d %d %d %d", name, class, &str, &dex, &con, &inte, &wis, &cha) != EOF){
    printf("%s", name);

    sum = str+dex+con+inte+wis+cha;
    printf("%d\n", sum);

    if(sum > max){
      max = sum;
      sprintf(topPlayer, "%s", name);
      printf("%s", topPlayer);
    }

    if(str > maxstr){
      maxstr = str;
      sprintf(topstr, "%s", name);
    }

    if(dex > maxdex){
      maxdex = dex;
      sprintf(topdex, "%s", name);
    }

    if(con > maxcon){
      maxcon = con;
      sprintf(topcon, "%s", name);
    }

    if(inte > maxinte){
      maxinte = inte;
      sprintf(topinte, "%s", name);
    }

    if(wis > maxwis){
      maxwis = wis;
      sprintf(topwis, "%s", name);
    }

    if(cha > maxcha){
      maxcha = cha;
      sprintf(topcha, "%s", name);
    }

    totalWis += wis;
    cont++;
	}

  printf("São %d bravos guerreiros!\n", cont);
  printf("Bravos guerreiros com %d de Sabedoria!\n", totalWis);
  printf("%s é o mais poderoso, com %d de atributos!\n", topPlayer, max);
  printf("%s é o mais forte, com %d de atributos!\n", topstr, maxstr);
  printf("%s é o mais agil, com %d de atributos!\n", topdex, maxdex);
  printf("%s é o mais robusto, com %d de atributos!\n", topcon, maxcon);
  printf("%s é o mais inteligente, com %d de atributos!\n", topinte, maxinte);
  printf("%s é o mais sabio, com %d de atributos!\n", topwis, maxwis);
  printf("%s é o mais bonito, com %d de atributos!\n", topcha, maxcha);
}


int main(){
	FILE* arquivo;

	arquivo = fopen("./dados.txt", "r");

	if(arquivo == NULL)
		printf("Vixi... :~(\n");
	else{
    get_players(arquivo);
		fclose(arquivo);
	}

	return 0;
}
