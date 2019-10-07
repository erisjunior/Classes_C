#include <stdio.h>

void init() {
  printf("*********  Insira um labirinto 5x5 pro mano Jonas *********\n");
  printf("*********  ----------- Instruções -----------     *********\n");
  printf("********* I - Ponto inicial de partida de Jonas   *********\n");
  printf("********* F - Destino final de Jonas              *********\n");
  printf("********* > - Caminho para o leste                *********\n");
  printf("********* < - Caminho para o oeste                *********\n");
  printf("********* ^ - Caminho para o norte                *********\n");
  printf("********* v - Caminho para o sul                  *********\n\n\n");
}

void winning() {
  printf("   __                             _         _       _   _                 \n");
  printf(" / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___ \n");
  printf("| |   / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __|\n");
  printf("| |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\ \n");
  printf(" \\____\\___/|_| |_|\\__,|_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/\n");
  printf("                    |___/                                                   \n");
}

void printDarkness() {
  int v;
  for(v = 0; v < 10; v++)
    printf("\n");
}

void lost() {
  printDarkness();
  printf("          Lost in the Darkness\n");
  printDarkness();
  printf("          ...     Forever   ...\n");
}

int main() {
  int i, u, nextI, nextU;
  int steps = 0;
  int forBreak = 0;
  char maze[5][5];
  char aux;

  init();

  for(i = 0; i < 5; i++){
    for(u = 0; u < 5; u++){
     scanf(" %c", &maze[i][u]);
    }
  }

  for(i = 0; i < 5; i++){
    for(u = 0; u < 5; u++){
      aux = maze[i][u];
      if(aux == 73 || aux == 108){
        nextI = i;
        nextU = u;
        if(maze[i-1][u] != 42) nextI--;
        if(maze[i+1][u] != 42) nextI++;
        if(maze[i][u-1] != 42) nextU--;
        if(maze[i][u+1] != 42) nextU++;
        break;
        forBreak = 1;
      }
    }
    if(forBreak) break;
  }

  while(1){
    aux = maze[nextI][nextU];
    steps++;
    if(aux == 94) nextI++;
    else if(aux == 118) nextI++;
    else if(aux == 60) nextU--;
    else if(aux == 62) nextU++;
    else if(aux == 70 || aux == 102)break;
    else{
      steps = 0;
      break;
    }
  }

  if(steps == 0 ){
    lost();
  }else{
    winning();
    printf("Escapou em %d passos\n", steps);
    for(i = 0; i < 5; i++){
      for(u = 0; u < 5; u++){
        printf(" %c", maze[i][u]);
      }
      printf("\n");
    }
  }

  return 0;
}
