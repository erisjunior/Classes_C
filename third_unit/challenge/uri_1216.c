# include <stdio.h>
# include <stdlib.h>

int main() {
  int qnt = 0, distance;
  char nome[100];
  double total = 0;

  while((scanf("%s", nome)) != EOF) {
    scanf("%d", &distance);

    qnt++;
    total += (float)distance;
  }

  printf("%.1f\n", (total/(float)qnt));

  return 0;
}
