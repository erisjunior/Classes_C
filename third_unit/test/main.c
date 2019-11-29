#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    Time* campeonato;
    int tamanho;

    campeonato = carrega_dados(&tamanho);

    if(campeonato == NULL){
        printf("Erro ao carregar as informacoes!\n");
        return 1;
    }

    imprime_tabela(campeonato, tamanho);

    return 0;
}
