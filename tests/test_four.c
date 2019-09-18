#include <stdio.h>
#include <stdbool.h>
int matchTime = 0;
int hand[5];

void sort(){
  int u, j, tmp;

  for (u = 0; u < 5; u++) {
    for (j = 0; j < 5; j++) {
      if (hand[j] > hand[u]) {
        tmp = hand[u];
        hand[u] = hand[j];
        hand[j] = tmp;
      }
    }
  }
}

void finish(int value){
  printf("Teste %d\n", matchTime);
  printf("%d Pontos\n", value);
  printf("\n");
}

bool isFlush(){
  int i;
  for (i = 0; i < 4; i++) {
    if (hand[i]+1 != hand[i+1]) return false;
  }
  finish(200 + hand[0]);
  return true;
}

bool isFourOfAKing(){
  int i = 0;

  if(hand[0] != hand[1]) i = 1;

  for (; i < 3; i++)
    if(hand[i] != hand[i+1]) return false;

  finish(180 + hand[1]);
  return true;
}

int thereIsThreeInARow() {
  if(hand[0] == hand[1] && hand[1] == hand[2]) return 0;
  if(hand[1] == hand[2] && hand[2] == hand[3]) return 1;
  if(hand[2] == hand[3] && hand[3] == hand[4]) return 2;
  return -1;
}

bool isFullHouseOrThreeOfAKing(){
  int threeInARow, auxToTwoInARow, value;

  threeInARow = thereIsThreeInARow();
  if(threeInARow == -1) return false;
  else if(threeInARow == 0) auxToTwoInARow = 3;
  else if(threeInARow == 1) auxToTwoInARow = -1;
  else if(threeInARow == 2) auxToTwoInARow = 0;

  if(hand[auxToTwoInARow] != hand[auxToTwoInARow + 1] || auxToTwoInARow == -1) {
    value = 140;
  } else{
    value = 160;
  }

  finish(value + hand[threeInARow]);
  return true;
}

int thereIsTwoInARow(int initPosition) {
  if(hand[0] == hand[1]) return 0;
  else if(hand[1] == hand[2]) return 1;
  else if(hand[2] == hand[3]) return 2;
  else if(hand[3] == hand[4]) return 3;
  return -1;
}

bool isTwoPairOrPair(){
  int twoInARow, auxToTwoInARow, firstTwo, secondTwo = 0;

  twoInARow = thereIsTwoInARow(0);
  if(twoInARow == -1) return false;

  firstTwo = hand[twoInARow];

  if(twoInARow == 0) {
    if(hand[2] == hand[3]) secondTwo = hand[2];
    if(hand[3] == hand[4]) secondTwo = hand[3];
  }else if(twoInARow == 1) {
    if(hand[3] == hand[4]) secondTwo = hand[3];
  }else if(twoInARow == 2) {
    if(hand[0] == hand[1]) secondTwo = hand[0];
  }

  if (secondTwo == 0) {
    finish(firstTwo);
    return true;
  }

  if(firstTwo > secondTwo){
    finish(20 + firstTwo*3 + secondTwo*2);
    return true;
  }else{
    finish(20 + firstTwo*2 + secondTwo*3);
    return true;
  }
}

int main() {
  int i, u, numberOfPlays;

  scanf("%d\n", &numberOfPlays);

  for(i = 0; i < numberOfPlays; i++){
    matchTime++;

    for(u = 0; u < 5; u++) scanf("%d",&hand[u]);
    sort();

    if(isFlush())continue;
    if(isFourOfAKing())continue;
    if(isFullHouseOrThreeOfAKing())continue;
    if(isTwoPairOrPair())continue;

    finish(0);
  }

  return 0;
}
