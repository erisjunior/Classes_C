#include <stdio.h>

//Função que trata o ataque da rodada
void executa_ataque(int* atacante, int* defensor, char arma){
    //Se o ataque for canhão
    if(arma == 'C'){
            //Verifica se tem municao para atacar, senão imprime mensagem
        if(atacante[0] <= 0) printf("Sem municao!\n");
        else{
            //Função verifica se ainda tem escudo, se sim diminui o ataque do escudo
            //Caso contrário, reduz da armadura
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
    //Se o ataque for míssel é mais fácil, só precisa testar se tem municao e reduzir os tributos
    else if(arma == 'M'){
        if(atacante[1] <= 0) printf("Sem municao!\n");
        else{
            defensor[3] -= 20;
            atacante[1]--;
        }
    }
    else printf("Eita piula, arma não reconhecida!\n");
}

//Função que verifica se o combate já terminou
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

//Função principal que controla a repetição base da leitura de informações e execução dos ataques
int main(){
    /*
        Variáveis:
        - rodadas: quantos ataques serão executados (lida da entrada)
        - enterprise[4], klingon[4] - vetor que armazenará em cada posição uma das informações da nave (lidos da entrada). Aqui usarei da seguinte forma:
        ----> [0] - canhão, [1] - missil, [2] - escudo, [3] - armadura
        - nave, ataque: caracteres para lerem os ataques de cada rodada (lidos da entrada)
    */
    int rodadas;
    int enterprise[4], klingon[4];
    char nave, ataque;
    int i, ok;

    //Lê o número de rodadas
    scanf("%d", &rodadas);

    //Lê os dados da enterprise e da nave klingon, respectivamente
    scanf("%d %d %d %d", &enterprise[3], &enterprise[2], &enterprise[0], &enterprise[1]);
    scanf("%d %d %d %d", &klingon[3], &klingon[2], &klingon[0], &klingon[1]);

    //Inicia repetição com as rodadas de ataque
    for(i=0; i<rodadas; i++){
        scanf(" %c %c", &nave, &ataque);

        //Chama uma das funções de ataque passando os parâmetros de acordo com a nave atacante/defensora
        //Após o ataque, verifica se ocorreu a derrota do adversário
        if(nave == 'E'){
                executa_ataque(enterprise, klingon, ataque);
                ok = testa_fim(klingon, nave);

        }
        else if(nave == 'K'){
                executa_ataque(klingon, enterprise, ataque);
                ok = testa_fim(enterprise, nave);
        }

        //Se houve um vencedor após o último ataque, quebra o laço e finaliza o programa
        if(ok) break;
    }

    return 0;
}
