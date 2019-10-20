#include <stdio.h>

//Opera��es da m�quina, de acordo com o arquivo de descri��o do problema

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

//Fun��o para checar as condi��es e imprimir poss�veis problemas
int verifica_status(int p, int t, int e){
    if(p >= 100){
        printf("CABUUUUUM!\n");
        return 1;
    }
    else if(p > 70) printf("Press�o elevada!\n");

    if(t >= 70){
        printf("Mossor� Time!\n");
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

//Fun��o principal que controla a m�quina do NPITI
int main(){
    //Vari�veis que controlam o status da m�quina. Erro ser� utilizado para detectar se ocorre algum erro no funcionamento da m�quina
    int pressao, temperatura, energia;
    int erro = 0;
    //Vari�vel que ler� as opera��es, uma de cada vez
    int operacao;

    //Leitura dos valores iniciais da entrada
    scanf("%d %d %d", &pressao, &temperatura, &energia);

    //Enquanto n�o ocorrer um erro, realiza a leitura de uma das opera��es na m�quina
    while(!erro){
        scanf("%d", &operacao);

        //Verifica qual foi a opera��o, e executa a fun��o correspondente
        switch(operacao){
            case 1: insercao(&pressao, &temperatura, &energia); break;
            case 2: processamento(&pressao, &temperatura, &energia); break;
            case 3: refrigeracao(&pressao, &temperatura, &energia); break;
            case 4: liberacao(&pressao, &temperatura, &energia); break;
            case 5: overclock(&pressao, &temperatura, &energia); break;
            default: printf("Opera��o Inv�lida!\n");
        }
        //Imprime os atributos da m�quina
        printf("Pressao = %d\nTemperatura = %d\nEnergia = %d\n", pressao, temperatura, energia);

        //Verifica se ocorre algum problema com a m�quina ap�s a opera��o
        erro = verifica_status(pressao, temperatura, energia);

        printf("\n");
    }

    return 0;
}
