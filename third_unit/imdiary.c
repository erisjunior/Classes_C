#include <stdio.h>
#include <stdlib.h>

//Definindo o registro para guardar uma tarefa do compromisso
typedef struct compromisso{
    char descricao[105];
    int hi, mi, hf, mf;
} Entry;

//Fun��o para comparar as tarefas. Essa assinatura � a exigida pela fun��o qsort, uma fun��o padr�o de ordena��o da biblioteca stdlib.h
//Essa fun��o retornaum valor inteiro: negativo se a < b, positivo se b < a e 0 se for igual
//Vamos implementar a fun��o para ordenar os registros de acordo com a hora inicial do compromisso
int compara_Entry(const void* a, const void* b){
    //Converte os par�metros void* para o tipo do registro
    Entry n1 = *((Entry*)a);
    Entry n2 = *((Entry*)b);

    //Se as horas forem diferentes, faz a subtra��o direto do valor das horas.
    if(n1.hi != n2.hi) return n1.hi - n2.hi;
    //Se forem iguais, faz conta similar dos minutos
    else return n1.mi - n2.mi;
}

//Fun��o principal
int main(){
    int entradas, i, j;
    int hi, mi, hf, mf;
    Entry agenda[105] = {0};

    //Leitura da entrada
    scanf("%d", &entradas);

    for(i=0; i<entradas; i++){
        scanf("%d:%d %d:%d", &agenda[i].hi, &agenda[i].mi, &agenda[i].hf, &agenda[i].mf);
        scanf(" %[^\n]s", agenda[i].descricao);
    }

    //Ordena��o do vetor agenda, usando a fun��o qsort da stdlib
    qsort(agenda, entradas, sizeof(Entry), compara_Entry);

    printf("Consultas\n");

    //Leitura das consultas
    while(scanf("%d:%d %d:%d", &hi, &mi, &hf, &mf) != EOF){
        //Para cada tarefa na agenda
        for(j=0; j<entradas; j++){
            //Se a hora de in�cio do compromisso est� dentro do intervalo d ahora inicial e final da consulta
            if(agenda[j].hi > hi && agenda[j].hi < hf){
                //%02d imprime o inteiro com duas casas de d�gitos, colocando 0 a esquerda quando necess�rio
                printf("%02d:%02d - %s\n", agenda[j].hi, agenda[j].mi, agenda[j].descricao);
            }
            //Se a hora do compromisso for igual a hora inicial da consulta, verifica se ela come�a depois (pelos minutos)
            else if(agenda[j].hi == hi){
                if(agenda[j].mi >= mi)
                    printf("%02d:%02d - %s\n", agenda[j].hi, agenda[j].mi, agenda[j].descricao);
            }
            //Se a hora do compromisso for igual a hora final da consulta, verifica se ela come�a antes (pelos minutos)
            else if(agenda[j].hi == hf){
                if(agenda[j].mi <= mf)
                    printf("%02d:%02d - %s\n", agenda[j].hi, agenda[j].mi, agenda[j].descricao);
            }
        }
        printf("\n");
    }

    return 0;
}
