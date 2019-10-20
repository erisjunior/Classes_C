#include <stdio.h>
#include <stdlib.h>

//Fun��o do tamanho: como toda string termina com o s�mbolo \0, conta quantos s�mbolos tem at� chegar no \0
//Simula: strlen
int tamanhoString(char* palavra){
    int i;

    for(i=0; palavra[i] != '\0'; i++);

    return i;
}

//Fun��o auxiliar para converter todas as letras de um string para mai�sculas.
//Simula: strtoupper
void converteMaiuscula(char* s){
    int i, tam;

    tam = tamanhoString(s);

    for(i=0; i<tam; i++)
        if(s[i] >= 97 && i <= 122)
            s[i] -= 32;
}

//Fun��o que copia a string s1 na s2. A copia ocorre letra por letra
//Simula strcpy
void copiaString(char* s1, char* s2){
    int i, tamanho;

    //Pega o tamanho da string origem
    tamanho = tamanhoString(s1);

    //Copia letra por letra
    for(i=0; i<tamanho; i++)
        s2[i] = s1[i];

    //Adiciona o \0 no final. COmo s�o ponteiros, essas opera��es em s2 j� alteram o endere�o de mem�ria diretamente!
    s2[i] = '\0';
}


//Fun��o que compara duas strings
//Simula strcmp
int comparaStrings(char *s1, char* s2){
    //Strings auxiliares
    char aux1[100], aux2[100];
    int i, tam1, tam2;

    //Pega o tamanho das duas strings
    tam1 = tamanhoString(s1);
    tam2 = tamanhoString(s2);

    //Copia as strings para as strings auxiliares. Isso � feito para n�o alterar o valor das informa��es digitadas na entrada
    copiaString(s1, aux1);
    copiaString(s2, aux2);

    //Converte as strings para mai�sculas, para facilitar a compara��o
    converteMaiuscula(aux1);
    converteMaiuscula(aux2);

    //Se a segunda palavra � menor, vamos comparar em fun��o dela
    if(tam1 > tam2){
        for(i=0; i<tam2; i++){
            //Se a letra de 1 � maior, ela aparece depois no dicion�rio
            if(aux1[i] > aux2[i])
                return -1;
            //Se a letra de dois � maior, ela aparece depois no dicion�rio
            else if(aux1[i] < aux2[i])
                return 1;
            //Se forem iguais, n�o faz nada e continua o la�o
        }

        //Se o la�o terminar e todas as letras foram iguais, a menor palavra aparece primeiro!
        return -1;
    }
    //Sen�o, se a primeira palavra � menor, vamos comparar em fun��o dela
    else if(tam1 < tam2){
        for(i=0; i<tam1; i++){
            //Se a letra de 1 � maior, ela aparece depois no dicion�rio
            if(aux1[i] > aux2[i])
                return -1;
            //Se a letra de dois � maior, ela aparece depois no dicion�rio
            else if(aux1[i] < aux2[i])
                return 1;
        }

        //Se o la�o terminar e todas as letras foram iguais, a menor palavra aparece primeiro!
        return 1;
    }
    //Sen�o, elas s�o do mesmo tamanho
    else{
        for(i=0; i<tam2; i++){
            //Se a letra de 1 � maior, ela aparece depois no dicion�rio
            if(aux1[i] > aux2[i])
                return -1;
            //Se a letra de dois � maior, ela aparece depois no dicion�rio
            else if(aux1[i] < aux2[i])
                return 1;
        }

        //Se chegar at� o fim, � porque s�o iguais!
        return 0;
    }
}

//Junta duas strings
//Aqui temos uma fun��o que retorna um ponteiro para uma string!
//Simula strcat
char* concatenaString(char* s1, char* s2){
    int i, j;
    //Para poder retornar o endere�o de mem�ria, ele precisa existir quando a fun��o terminar de executar. Ou seja, n�o pode ser alocado na pilha de mem�ria da fun��o, mas sim na heap!
    //Logo n�o podemos criar uma string est�tica, ent�o vamos aloc�-la dinamicamente!
    char* juntas;

    //200 posi��es, para caber a jun��o das duas strings
    juntas = malloc(sizeof(char)*200);

    //Copia a primeira string para a grande
    for(i=0; i<tamanhoString(s1); i++)
        juntas[i] = s1[i];

    //Copia a segunda string para a grande
    //Perceba que o i controla onde nos vamos inserir na string grande, enquanto j controla a leitura da segunda string
    for(j=0; j<tamanhoString(s2); j++, i++)
        juntas[i] = s2[j];

    //Coloca aquele \0 maroto :)
    juntas[i] = '\0';

    //Como juntas foi alocada dinamicamente, podemos retornar o seu valor, que representar� um endere�o ainda v�lido e ativo na mem�ria.
    return juntas;
}

//Fun��o que verifica se a string s1 � substring (uma parte de) s2
//Simula strstr
int verificaSubstring(char* s1, char* s2){
    int i, j;

    /* A l�gica aqui � a seguinte: n�s vamos pegar a string maior, e sair percorrendo ela procurando a menor. Quando o caractere da string maior for igual ao primeiro caractere da menor, n�s vamos verificar se o resto da palavra menor est� vindo em sequ�ncia na maior.
        veja as palavras pato e sapato

        sapato ====> s != p
        pato

        sapato ====> a != p
         pato

        sapato ====> p == p, vamos conferir o resto! a == a, t == t e o == o. pato � uma substring de sapato!
          pato
    */

    //Se s1 � maior que s2, n�o tem como ela ser substring, retorna falso
    if(tamanhoString(s1) > tamanhoString(s2)) return 0;
    //s1 � menor, vamos verificar
    else{
        //de 0 at� a �ltima letra poss�vel onde ainda cabe a palavra de s1, vamos percorrer s2 e verificar
        for(i=0; i<tamanhoString(s2)-tamanhoString(s1); i++){
            //Se a letra de s2 � igual a primeira letra de s1, vamos verificar a palavra!
            if(s2[i] == s1[0]){
                //La�o para percorrer a menor
                for(j=1; j<tamanhoString(s1); j++)
                    //se alguma letra n�o bate, n�o � substring, sai do la�o
                    if(s1[j] != s2[i+j])
                        break;
                //Se ao chegar no final do la�o, o tamanho de j for igual ao tamanho da string, significa que o la�o rodou at� o fim sem tornar a condi��o das letras diferentes verdadeiras. Logo todas as letras da palavra menor bateram com as letras na palavra maior, e � uma substring! Retorna verdadeiro.
                if(j == tamanhoString(s1)) return 1;
            }
        }

        //Se verificou toda a palavra e n�o encontrou a substring em nenhuma posi��o, retorna falso.
        return 0;
    }
}

//Fun��o principal que controlar� todos os testes que queremos fazer com as fun��es de string
int main(){
    //Palavra 1 e palavra 2 v�o ler as strings da entrada pra gente
    char palavra[100], palavra2[100];
    //Grande vai ser um ponteiro para um string, retornado por uma fun��o
    char* grande;
    //tam vai armazenar o tamanho da string, e ok vai ser uma vari�vel de verifica��o do retorno das fun��es
    int tam, ok;

    //Leitura da primeira string
    //Normalmente, a leitura com %s l� um conjunto de s�mbolos at� o primeiro espa�o em branco encontrado.
    //Para podermos ler mais de uma palavra (no caso, uma linha inteira) com o scanf, precisamos informar uma express�o que modifica o %s
    //Abaixo temos um [^\n], ond o ^ indica qualquer conjunto de s�mbolos que ocorra antes de um \n. Dessa forma, o programa vai ler tudo at� chegar no \n do final da linha.
    scanf(" %[^\n]s", palavra);

    //Tamanho da palavra
    tam = tamanhoString(palavra);

    printf("Tamanho da palavra: %d\n", tam);

    //Fun��o que copia palavra em palavra2
    copiaString(palavra, palavra2);

    printf("Palavra copiada: %s\n", palavra2);

    printf("Digite a segunda palavra\n");

    scanf(" %[^\n]s", palavra2);

    //Fun��o que compara duas strings, pela ordem lexogr�fica (dicion�rio)
    ok = comparaStrings(palavra, palavra2);

    //Se for 0, s�o iguais. Se for < 0, a primeira palavra aparece depois (� maior). Se for > 0, a segunda palavra aparece depois.
    if(ok == 0) printf("S�o iguais!\n");
    else if(ok < 0) printf("%s � maior que %s\n", palavra, palavra2);
    else printf("%s � maior que %s\n", palavra2, palavra);

    printf("Juntando as duas palavras: ");

    //Concatena (junta) as duas strings. Aqui a string grande ser� retornada pela fun��o
    grande = concatenaString(palavra, palavra2);

    printf("%s\n", grande);

    printf("%s � substring de %s?\n", palavra, palavra2);

    //Verifica se a palavra est� contida (� um peda�o) de palavra2
    ok = verificaSubstring(palavra, palavra2);

    if(ok) printf("Sim, eh substring\n");
    else printf("Nao, nao eh substring\n");

    return 0;
}
