#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Time* carrega_dados  (int *tamanho) {
  FILE* arq = fopen("base.txt", "r");
  Time* vetor;
  int i;

  i = *tamanho = 0;

  if(arq == NULL){
    return NULL;
  }

  fscanf(arq, "%d", &*tamanho);

  vetor = malloc(sizeof(Time) * *tamanho);

  for(i = 0; i < *tamanho; i++){
    fscanf(arq," %[^;]", vetor[i].nome);
    fscanf(arq,";%d %d %d", &vetor[i].vitorias, &vetor[i].empates, &vetor[i].derrotas);
    fscanf(arq," %d %d", &vetor[i].gols_feitos, &vetor[i].gols_sofridos);
  }

  return vetor;
}

void print_header() {
  printf("\n*********************************** Tabela do Campeonato! ***********************************\n");
  printf("\nNome | Pontos | Jogos | Vitorias | Empates | Derrotas | Gols Pro | Gols Contra | Saldo de Gols\n");
}

void  imprime_tabela (Time* campeonato, int tamanho) {
  int saldo_gols, jogos, pontos;
  int pontos_atuais, pontos_proximos;
  int saldo_atual, saldo_proximo;
  int i, u, j;
  Time tmp;

  print_header();

  for (u = 0; u < tamanho; u++) {
    for (j = 0; j < tamanho; j++) {
      pontos_atuais   = (campeonato[j].vitorias * 3) + campeonato[j].empates;
      pontos_proximos = (campeonato[u].vitorias * 3) + campeonato[u].empates;

      saldo_atual   = campeonato[j].gols_feitos - campeonato[j].gols_sofridos;
      saldo_proximo = campeonato[u].gols_feitos - campeonato[u].gols_sofridos;

      if (pontos_proximos > pontos_atuais) {
        tmp = campeonato[u];
        campeonato[u] = campeonato[j];
        campeonato[j] = tmp;
      }else if(pontos_proximos == pontos_atuais) {
        if (campeonato[u].vitorias > campeonato[j].vitorias) {
          tmp = campeonato[u];
          campeonato[u] = campeonato[j];
          campeonato[j] = tmp;
        } else if(campeonato[u].vitorias == campeonato[j].vitorias) {
          if (saldo_proximo > saldo_atual) {
            tmp = campeonato[u];
            campeonato[u] = campeonato[j];
            campeonato[j] = tmp;
          }
        }
      }
    }
  }

  for(i = 0; i < tamanho; i++){
    pontos = (campeonato[i].vitorias * 3) + campeonato[i].empates;
    jogos = campeonato[i].vitorias + campeonato[i].empates + campeonato[i].derrotas;
    saldo_gols = campeonato[i].gols_feitos - campeonato[i].gols_sofridos;

    printf("%s |", campeonato[i].nome);
    printf(" %d |", pontos);
    printf(" %d |", jogos);
    printf(" %d |", campeonato[i].vitorias);
    printf(" %d |", campeonato[i].empates);
    printf(" %d |", campeonato[i].derrotas);
    printf(" %d |", campeonato[i].gols_feitos);
    printf(" %d |", campeonato[i].gols_sofridos);
    printf(" %d\n", saldo_gols);
  }

  printf("\n\nTimes na zona da libertadores:\n");

  for(i = 0; i < 6; i++){
    printf("%s\n", campeonato[i].nome);
  }

  printf("\n\nTimes rebaixados:\n");

  for(i = tamanho - 1; i > tamanho - 1 - 4; i--){
    printf("%s\n", campeonato[i].nome);
  }
}
