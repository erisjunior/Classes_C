#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY 0
#define CHECKED 1
#define MINE 2
#define FLAG 3

void config_field(int cols, int rows, int** field){
  int i, u;

  field = (int *) calloc(cols,sizeof(int*));

  for(i = 0; i < cols; i++){
    field[i] = (int*) calloc(rows,sizeof(int*));
    for(u = 0; u < rows; u++){
      field[i][u] = EMPTY;
    }
  }
}

void config_mines(int cols, int rows, int mines, int** field){
  int i;

  srand(time(NULL));

  printf("%d as %d ", cols, rows);

  for(i = 0; i < mines;i++){
    int c = rand() % cols;
    int r = rand() % rows;
    field[c][r] = MINE;
    printf("%d", field[c][r]);
  }
}

void show_space(int space){
  switch (space) {
    case EMPTY:
      printf("*");
      break;

    case MINE:
      printf("*");
      break;

    case FLAG:
      printf("B");
      break;

    case CHECKED:
      printf("X");
      break;

    default:
      break;
  }
}

void print_field(int cols, int rows, int** field){
  int i, u;
  for(i = 0; i < cols; i++){
    for(u = 0; u < rows; u++){
      show_space(field[i][u]);
    }
    printf("\n");
  }
}

int play(int cols, int rows, int** field) {
  int c, r, a;
  printf("Faça sua jogada");
  scanf("%d %d %c", &c, %d, a);

  int space = field[c][r];

  if (space == CHECKED) return 0;

  if(a == 'A') {

    if(space == MINE){
      printf("Você perdeu");
      return 1;
    }

    field[c][r] = CHECKED;
  }else if(a == 'B') {
    field[c][r] = FLAG;
  }
}

void print_rules() {
  printf("\n\nSuas jogadas são feitas da seguinte forma:\n");
  printf("X Y ACAO\n");
  printf("X - Coluna\n");
  printf("Y - Linha\n");
  printf("ACAO - A ou B (abrir ou marcar bandeira)\n");
}

int main(){
  int option, c, r, m;
  int** field;

  printf("Bem vindo ao Campo Manolado!! \n");
  printf("Selecione o tamanho do seu campo \n\n");
  printf("0 - Tamanho 9x9   | 10 minas \n");
  printf("1 - Tamanho 16x16 | 40 minas \n");
  printf("2 - Tamanho 16x30 | 99 minas \n");
  scanf("%d", &option);

  switch (option) {
    case 0:
      c = 9;
      r = 9;
      m = 10;
      break;

    case 1:
      c = 16;
      r = 16;
      m = 40;
      break;

    case 2:
      c = 16;
      r = 30;
      m = 99;
      break;

    default:
      return 0;
  }

  config_field(c, r, field);
  config_mines(c, r, m, field);
  print_field(c, r, field);
  print_rules();

  while(1){
    int res = play(c, r, field);
    if(res == 1) return 0;
  }

	return 0;
}
