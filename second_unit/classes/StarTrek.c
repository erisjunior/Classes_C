#include <stdio.h>

//Fun��o que trata o ataque da rodada
void executa_ataque(int* atacante, int* defensor, char arma){
    //Se o ataque for canh�o
    if(arma == 'C'){
            //Verifica se tem municao para atacar, sen�o imprime mensagem
        if(atacante[0] <= 0) printf("Sem municao!\n");
        else{
            //Fun��o verifica se ainda tem escudo, se sim diminui o ataque do escudo
            //Caso contr�rio, reduz da armadura
            if(defensor[2] > 0){
                defensor[2] -= 10;

                //Se o escudo zerar no meio do ataque, abate o restante da armadura
                if(defensor[2] < 0)
                    defensor[3] -= defensor[2];
            }
            else{
                defensor[3] -= 10;
            }
            //reduz municao do ataque utilizado
            atacante[0]--;
        }
    }
    //Se o ataque for m�ssel � mais f�cil, s� precisa testar se tem municao e reduzir os tributos
    else if(arma == 'M'){
        if(atacante[1] <= 0) printf("Sem municao!\n");
        else{
            defensor[3] -= 20;
            atacante[1]--;
        }
    }
    else printf("Eita piula, arma n�o reconhecida!\n");
}

//Fun��o que verifica se o combate j� terminou
int testa_fim(int* atacado, char atacante){
    //Se armadura do atacado for zero ou menor
    if(atacado[3] <= 0){
        //Imprime o vencedor de acordo com quem realizou o ataque
        switch(atacante){
            case 'E': printf("Enterprise Vence!\n"); break;
            case 'K': printf("Klingons Vencem!\n"); break;
        }
        return 1;
    }
    else return 0;
}

//Fun��o principal que controla a repeti��o base da leitura de informa��es e execu��o dos ataques
int main(){
    /*
        Vari�veis:
        - rodadas: quantos ataques ser�o executados (lida da entrada)
        - enterprise[4], klingon[4] - vetor que armazenar� em cada posi��o uma das informa��es da nave (lidos da entrada). Aqui usarei da seguinte forma:
        ----> [0] - canh�o, [1] - missil, [2] - escudo, [3] - armadura
        - nave, ataque: caracteres para lerem os ataques de cada rodada (lidos da entrada)
    */
    int rodadas;
    int enterprise[4], klingon[4];
    char nave, ataque;
    int i, ok;

    //L� o n�mero de rodadas
    scanf("%d", &rodadas);

    //L� os dados da enterprise e da nave klingon, respectivamente
    scanf("%d %d %d %d", &enterprise[3], &enterprise[2], &enterprise[0], &enterprise[1]);
    scanf("%d %d %d %d", &klingon[3], &klingon[2], &klingon[0], &klingon[1]);

    //Inicia repeti��o com as rodadas de ataque
    for(i=0; i<rodadas; i++){
        scanf(" %c %c", &nave, &ataque);

        //Chama uma das fun��es de ataque passando os par�metros de acordo com a nave atacante/defensora
        //Ap�s o ataque, verifica se ocorreu a derrota do advers�rio
        if(nave == 'E'){
                executa_ataque(enterprise, klingon, ataque);
                ok = testa_fim(klingon, nave);

        }
        else if(nave == 'K'){
                executa_ataque(klingon, enterprise, ataque);
                ok = testa_fim(enterprise, nave);
        }

        //Se houve um vencedor ap�s o �ltimo ataque, quebra o la�o e finaliza o programa
        if(ok) break;
    }

    return 0;
}
