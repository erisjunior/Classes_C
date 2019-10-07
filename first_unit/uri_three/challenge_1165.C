#include <stdio.h>

int main () {

  int nTestCases, value, i, u, boolean;

  scanf("%d", &nTestCases);

  for(i = 0; i < nTestCases; i++){
    scanf("%d", &value);
    boolean = 0;

    for(u = 2; u <= value/2; u++){
      if((value % u) == 0) boolean++;
    }
    if(boolean == 0) printf("%d eh primo\n", value);
    if(boolean > 0) printf("%d nao eh primo\n", value);
  }

  return 0;
}
