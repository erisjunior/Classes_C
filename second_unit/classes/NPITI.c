#include <stdio.h>

//Operações da máquina, de acordo com o arquivo de descrição do problema

void insercao(int* p, int* t, int* e){
    *p += 20;
    *t += 10;
    *e -= 15;
}

void processamento(int* p, int* t, int* e){
    *p -= 5;
    *t += 15;
    *e -= 25;
}

void refrigeracao(int* p, int* t, int* e){
    *p -= 7;
    *t -= 10;
    *e += 5;
}

void liberacao(int* p, int* t, int* e){
    *p -= 15;
    *t -= 5;
    *e += 5;
}

void overclock(int* p, int* t, int* e){
    *p += 15;
    *t += 10;
    *e -= 20;
}

//Função para checar as condições e imprimir possíveis problemas
int verifica_status(int p, int t, int e){
    if(p >= 100){
        printf("CABUUUUUM!\n");
        return 1;
    }
    else if(p > 70) printf("Pressão elevada!\n");

    if(t >= 70){
        printf("Mossoró Time!\n");
        return 1;
    }
    else if(t > 50) printf("Temperatura elevada!\n");

    if(e <= 0){
        printf("Queda de energia!\n");
        return 1;
    }
    else if(e < 30) printf("Energia baixa!\n");

    return 0;
}

//Função principal que controla a máquina do NPITI
int main(){
    //Variáveis que controlam o status da máquina. Erro será utilizado para detectar se ocorre algum erro no funcionamento da máquina
    int pressao, temperatura, energia;
    int erro = 0;
    //Variável que lerá as operações, uma de cada vez
    int operacao;

    //Leitura dos valores iniciais da entrada
    scanf("%d %d %d", &pressao, &temperatura, &energia);

    //Enquanto não ocorrer um erro, realiza a leitura de uma das operações na máquina
    while(!erro){
        scanf("%d", &operacao);

        //Verifica qual foi a operação, e executa a função correspondente
        switch(operacao){
            case 1: insercao(&pressao, &temperatura, &energia); break;
            case 2: processamento(&pressao, &temperatura, &energia); break;
            case 3: refrigeracao(&pressao, &temperatura, &energia); break;
            case 4: liberacao(&pressao, &temperatura, &energia); break;
            case 5: overclock(&pressao, &temperatura, &energia); break;
            default: printf("Operação Inválida!\n");
        }
        //Imprime os atributos da máquina
        printf("Pressao = %d\nTemperatura = %d\nEnergia = %d\n", pressao, temperatura, energia);

        //Verifica se ocorre algum problema com a máquina após a operação
        erro = verifica_status(pressao, temperatura, energia);

        printf("\n");
    }

    return 0;
}
