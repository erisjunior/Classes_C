#include <stdio.h>
#include <string.h>

typedef struct comic{
  char name[200];
  int volume;
  int month;
  int year;
  int read;
} Comic;

void load_comics(Comic *comics){
  char ptr[100];
  FILE* file;
  Comic comic;

	file = fopen("./comics.txt", "r");

	if(file == NULL) {
		printf("Base de dados vazia\n");
  }	else {
    int count = 0;
    while(!(feof(file))){
      fscanf(file,"%[^,]", comic.name);
      fscanf(file,"%[^ ]", ptr);
      fscanf(file,"%d", &comic.volume);
      fscanf(file,"%d", &comic.month);
      fscanf(file,"%d", &comic.year);
      fscanf(file,"%d", &comic.read);
      fscanf(file,"%[^\n]", ptr);

      comics[count] = comic;
      count++;
    }
    printf("Prontinho! \n");
  }
  fclose(file);
}

void fetch_comic() {
  char name[200];
  int volume;

  char ptr[100];
  FILE* file;
  Comic comic;

	file = fopen("./comics.txt", "r");

	if(file == NULL) {
		printf("Base de dados vazia\n");
  }	else {
		printf("Nome do quadrinho\n");
    scanf("%s", name);
		printf("Volume do quadrinho\n");
    scanf("%d", &volume);

    while(!(feof(file))){
      fscanf(file,"%[^,]", comic.name);
      fscanf(file,"%[^ ]", ptr);
      fscanf(file,"%d", &comic.volume);
      fscanf(file,"%d", &comic.month);
      fscanf(file,"%d", &comic.year);
      fscanf(file,"%d", &comic.read);
      fscanf(file,"%[^\n]", ptr);


      if(strcmp(name, comic.name) && volume == comic.volume){
        printf("%s - %d, lançado em %d %d", name, comic.volume, comic.month, comic.year);
        if(comic.read){
          printf(" - Lido");
        }else{
          printf(" - Não lido");
        }
        fclose(file);
        return;
      }
    }

    fclose(file);
    printf("HQ não encontrada: \n");
  }
}

int main(){
  Comic comics[1000];

  int option = 0;

  do {
    printf("\n \nEscolha uma das opções: \n");
    printf("1 - Carregar Base de dados das HQs \n");
    printf("2 - Adicionar nova HQ \n");
    printf("3 - Remover HQ \n");
    printf("4 - Consultar HQ \n");
    printf("5 - Consultas gerais \n");
    printf("6 - Marcar HQ como lida \n");
    printf("7 - Sair do programa \n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        load_comics(comics);
        break;

      // case 2:
      //   add_comic(comics);
      //   break;

      // case 3:
      //   remove_comic(comics);
      //   break;

      case 4:
        fetch_comic();
        break;

      // case 5:
      //   general_configs(comics);
      //   break;

      // case 6:
      //   mark_as_read(comics);
      //   break;

      default:
        break;
    }

  } while(option < 7);

	return 0;
}
