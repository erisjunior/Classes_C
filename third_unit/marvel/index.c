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
    fclose(file);
    printf("Prontinho! \n");
  }
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
          printf(" - Lido\n");
        }else{
          printf(" - Não lido\n");
        }
        fclose(file);
        return;
      }
    }

    fclose(file);
    printf("HQ não encontrada\n");
  }
}

void add_comic() {
  char name[200];
  int volume;
  int month;
  int year;

  char ptr[100];
  FILE* file;
  Comic comic;

	file = fopen("./comics.txt", "a+");

  printf("Nome do quadrinho\n");
  scanf("%s", name);
  printf("Volume do quadrinho\n");
  scanf("%d", &volume);
  printf("Mês de lançamento\n");
  scanf("%d", &month);
  printf("Ano de lançamento\n");
  scanf("%d", &year);

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
  fprintf(file, "%s, %d %d %d 0\n", name, volume, month, year);
  fclose(file);
}

void remove_comic() {
  char name[200];
  int volume;

  char ptr[100];
  FILE* file;
  FILE* buffer;
  Comic comic;

	file = fopen("./comics.txt", "r");
	buffer = fopen("./buffer.txt", "w");

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

    if(strcmp(name, comic.name)){
      if(volume != comic.volume){
        fprintf(buffer, "%s, %d %d %d %d\n", comic.name, comic.volume, comic.month, comic.year, comic.read);
      }
    }else{
      fprintf(buffer, "%s, %d %d %d %d\n", comic.name, comic.volume, comic.month, comic.year, comic.read);
    }
  }
  fclose(file);
  fclose(buffer);

  remove("./comics.txt");

	buffer = fopen("./buffer.txt", "r");
  file = fopen("./comics.txt", "w");
  size_t n = 0;
  size_t m = 0;
  unsigned char buf[ 1024 * 8 ];
  do {
    m = 0;

    n = fread( buf, 1, sizeof(buf), buffer );

    if( n > 0 )
        m = fwrite( buf, 1, n, file );

  } while( (n > 0) && (n == m) );
  fclose(file);
  fclose(buffer);
  remove("./buffer.txt");
}

void mark_as_read() {
  char name[200];
  int volume;

  char ptr[100];
  FILE* file;
  FILE* buffer;
  Comic comic;

	file = fopen("./comics.txt", "r");
	buffer = fopen("./buffer.txt", "w");

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

    if(strcmp(name, comic.name)){
      if(volume != comic.volume){
        fprintf(buffer, "%s, %d %d %d %d\n", comic.name, comic.volume, comic.month, comic.year, comic.read);
      }else {
        fprintf(buffer, "%s, %d %d %d 1\n", comic.name, comic.volume, comic.month, comic.year);
      }
    }else{
      fprintf(buffer, "%s, %d %d %d %d\n", comic.name, comic.volume, comic.month, comic.year, comic.read);
    }
  }
  fclose(file);
  fclose(buffer);

  remove("./comics.txt");

	buffer = fopen("./buffer.txt", "r");
  file = fopen("./comics.txt", "w");
  size_t n = 0;
  size_t m = 0;
  unsigned char buf[ 1024 * 8 ];
  do {
    m = 0;

    n = fread( buf, 1, sizeof(buf), buffer );

    if( n > 0 )
        m = fwrite( buf, 1, n, file );

  } while( (n > 0) && (n == m) );
  fclose(file);
  fclose(buffer);
  remove("./buffer.txt");
}

void general_queries() {
  int select = 0;

  printf("\n Escolha uma das opções: \n");
  printf("1 - Listar HQs por ano \n");
  printf("2 - Listar HQs por período \n");
  printf("3 - Listar HQs por personagem \n");
  printf("4 - Listar HQs lidas \n");
  scanf("%d", &select);

  FILE* file;

	file = fopen("./comics.txt", "r");

	if(file == NULL) {
		printf("Base de dados vazia\n");
    return;
  }	else {
    switch (select) {
      case 1:
        fetch_comic_by_year(file);
        break;

      case 2:
        fetch_comic_by_period(file);
        break;

      case 3:
        fetch_comic_by_name(file);
        break;

      case 4:
        fetch_comic_by_read(file);
        break;

      default:
        break;
    }
  }
}

fetch_comic_by_year(FILE* file){
  int year;

  char ptr[100];
  Comic comic;

  printf("Ano do quadrinho\n");
  scanf("%d", &year);

  while(!(feof(file))){
    fscanf(file,"%[^,]", comic.name);
    fscanf(file,"%[^ ]", ptr);
    fscanf(file,"%d", &comic.volume);
    fscanf(file,"%d", &comic.month);
    fscanf(file,"%d", &comic.year);
    fscanf(file,"%d", &comic.read);
    fscanf(file,"%[^\n]", ptr);

    if(year == comic.year){
      printf("%s - %d, lançado em %d %d", comic.name, comic.volume, comic.month, comic.year);
      if(comic.read){
        printf(" - Lido\n");
      }else{
        printf(" - Não lido\n");
      }
    }
  }

  fclose(file);
}

fetch_comic_by_period(FILE* file){
  int year;
  int yeartwo;

  char ptr[100];
  Comic comic;

  printf("Ano inicial\n");
  scanf("%d", &year);
  printf("Ano final\n");
  scanf("%d", &yeartwo);

  while(!(feof(file))){
    fscanf(file,"%[^,]", comic.name);
    fscanf(file,"%[^ ]", ptr);
    fscanf(file,"%d", &comic.volume);
    fscanf(file,"%d", &comic.month);
    fscanf(file,"%d", &comic.year);
    fscanf(file,"%d", &comic.read);
    fscanf(file,"%[^\n]", ptr);

    if(year > comic.year && yeartwo < comic.year){
      printf("%s - %d, lançado em %d %d", comic.name, comic.volume, comic.month, comic.year);
      if(comic.read){
        printf(" - Lido\n");
      }else{
        printf(" - Não lido\n");
      }
    }
  }

  fclose(file);
}

fetch_comic_by_name(FILE* file){
  char name[200];

  char ptr[100];
  Comic comic;

  printf("Nome do quadrinho\n");
  scanf("%s", name);

  while(!(feof(file))){
    fscanf(file,"%[^,]", comic.name);
    fscanf(file,"%[^ ]", ptr);
    fscanf(file,"%d", &comic.volume);
    fscanf(file,"%d", &comic.month);
    fscanf(file,"%d", &comic.year);
    fscanf(file,"%d", &comic.read);
    fscanf(file,"%[^\n]", ptr);

    if(strcmp(name, comic.name)){
      printf("%s - %d, lançado em %d %d", name, comic.volume, comic.month, comic.year);
      if(comic.read){
        printf(" - Lido\n");
      }else{
        printf(" - Não lido\n");
      }
    }
  }

  fclose(file);
}

fetch_comic_by_read(FILE* file){
  char ptr[100];
  Comic comic;

  while(!(feof(file))){
    fscanf(file,"%[^,]", comic.name);
    fscanf(file,"%[^ ]", ptr);
    fscanf(file,"%d", &comic.volume);
    fscanf(file,"%d", &comic.month);
    fscanf(file,"%d", &comic.year);
    fscanf(file,"%d", &comic.read);
    fscanf(file,"%[^\n]", ptr);

    if(comic.read){
      printf("%s - %d, lançado em %d %d - Lido\n", comic.name, comic.volume, comic.month, comic.year);
    }
  }

  fclose(file);
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

      case 2:
        add_comic();
        break;

      case 3:
        remove_comic();
        break;

      case 4:
        fetch_comic();
        break;

      case 5:
        general_queries();
        break;

      case 6:
        mark_as_read();
        break;

      default:
        break;
    }

  } while(option < 7);

	return 0;
}
