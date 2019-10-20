#include <stdio.h>
#include <stdlib.h>

//Função do tamanho: como toda string termina com o símbolo \0, conta quantos símbolos tem até chegar no \0
//Simula: strlen
int tamanhoString(char* palavra){
    int i;

    for(i=0; palavra[i] != '\0'; i++);

    return i;
}

//Função auxiliar para converter todas as letras de um string para maiúsculas.
//Simula: strtoupper
void converteMaiuscula(char* s){
    int i, tam;

    tam = tamanhoString(s);

    for(i=0; i<tam; i++)
        if(s[i] >= 97 && i <= 122)
            s[i] -= 32;
}

//Função que copia a string s1 na s2. A copia ocorre letra por letra
//Simula strcpy
void copiaString(char* s1, char* s2){
    int i, tamanho;

    //Pega o tamanho da string origem
    tamanho = tamanhoString(s1);

    //Copia letra por letra
    for(i=0; i<tamanho; i++)
        s2[i] = s1[i];

    //Adiciona o \0 no final. COmo são ponteiros, essas operações em s2 já alteram o endereço de memória diretamente!
    s2[i] = '\0';
}


//Função que compara duas strings
//Simula strcmp
int comparaStrings(char *s1, char* s2){
    //Strings auxiliares
    char aux1[100], aux2[100];
    int i, tam1, tam2;

    //Pega o tamanho das duas strings
    tam1 = tamanhoString(s1);
    tam2 = tamanhoString(s2);

    //Copia as strings para as strings auxiliares. Isso é feito para não alterar o valor das informações digitadas na entrada
    copiaString(s1, aux1);
    copiaString(s2, aux2);

    //Converte as strings para maiúsculas, para facilitar a comparação
    converteMaiuscula(aux1);
    converteMaiuscula(aux2);

    //Se a segunda palavra é menor, vamos comparar em função dela
    if(tam1 > tam2){
        for(i=0; i<tam2; i++){
            //Se a letra de 1 é maior, ela aparece depois no dicionário
            if(aux1[i] > aux2[i])
                return -1;
            //Se a letra de dois é maior, ela aparece depois no dicionário
            else if(aux1[i] < aux2[i])
                return 1;
            //Se forem iguais, não faz nada e continua o laço
        }

        //Se o laço terminar e todas as letras foram iguais, a menor palavra aparece primeiro!
        return -1;
    }
    //Senão, se a primeira palavra é menor, vamos comparar em função dela
    else if(tam1 < tam2){
        for(i=0; i<tam1; i++){
            //Se a letra de 1 é maior, ela aparece depois no dicionário
            if(aux1[i] > aux2[i])
                return -1;
            //Se a letra de dois é maior, ela aparece depois no dicionário
            else if(aux1[i] < aux2[i])
                return 1;
        }

        //Se o laço terminar e todas as letras foram iguais, a menor palavra aparece primeiro!
        return 1;
    }
    //Senão, elas são do mesmo tamanho
    else{
        for(i=0; i<tam2; i++){
            //Se a letra de 1 é maior, ela aparece depois no dicionário
            if(aux1[i] > aux2[i])
                return -1;
            //Se a letra de dois é maior, ela aparece depois no dicionário
            else if(aux1[i] < aux2[i])
                return 1;
        }

        //Se chegar até o fim, é porque são iguais!
        return 0;
    }
}

//Junta duas strings
//Aqui temos uma função que retorna um ponteiro para uma string!
//Simula strcat
char* concatenaString(char* s1, char* s2){
    int i, j;
    //Para poder retornar o endereço de memória, ele precisa existir quando a função terminar de executar. Ou seja, não pode ser alocado na pilha de memória da função, mas sim na heap!
    //Logo não podemos criar uma string estática, então vamos alocá-la dinamicamente!
    char* juntas;

    //200 posições, para caber a junção das duas strings
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

    //Como juntas foi alocada dinamicamente, podemos retornar o seu valor, que representará um endereço ainda válido e ativo na memória.
    return juntas;
}

//Função que verifica se a string s1 é substring (uma parte de) s2
//Simula strstr
int verificaSubstring(char* s1, char* s2){
    int i, j;

    /* A lógica aqui é a seguinte: nós vamos pegar a string maior, e sair percorrendo ela procurando a menor. Quando o caractere da string maior for igual ao primeiro caractere da menor, nós vamos verificar se o resto da palavra menor está vindo em sequência na maior.
        veja as palavras pato e sapato

        sapato ====> s != p
        pato

        sapato ====> a != p
         pato

        sapato ====> p == p, vamos conferir o resto! a == a, t == t e o == o. pato é uma substring de sapato!
          pato
    */

    //Se s1 é maior que s2, não tem como ela ser substring, retorna falso
    if(tamanhoString(s1) > tamanhoString(s2)) return 0;
    //s1 é menor, vamos verificar
    else{
        //de 0 até a última letra possível onde ainda cabe a palavra de s1, vamos percorrer s2 e verificar
        for(i=0; i<tamanhoString(s2)-tamanhoString(s1); i++){
            //Se a letra de s2 é igual a primeira letra de s1, vamos verificar a palavra!
            if(s2[i] == s1[0]){
                //Laço para percorrer a menor
                for(j=1; j<tamanhoString(s1); j++)
                    //se alguma letra não bate, não é substring, sai do laço
                    if(s1[j] != s2[i+j])
                        break;
                //Se ao chegar no final do laço, o tamanho de j for igual ao tamanho da string, significa que o laço rodou até o fim sem tornar a condição das letras diferentes verdadeiras. Logo todas as letras da palavra menor bateram com as letras na palavra maior, e é uma substring! Retorna verdadeiro.
                if(j == tamanhoString(s1)) return 1;
            }
        }

        //Se verificou toda a palavra e não encontrou a substring em nenhuma posição, retorna falso.
        return 0;
    }
}

//Função principal que controlará todos os testes que queremos fazer com as funções de string
int main(){
    //Palavra 1 e palavra 2 vão ler as strings da entrada pra gente
    char palavra[100], palavra2[100];
    //Grande vai ser um ponteiro para um string, retornado por uma função
    char* grande;
    //tam vai armazenar o tamanho da string, e ok vai ser uma variável de verificação do retorno das funções
    int tam, ok;

    //Leitura da primeira string
    //Normalmente, a leitura com %s lê um conjunto de símbolos até o primeiro espaço em branco encontrado.
    //Para podermos ler mais de uma palavra (no caso, uma linha inteira) com o scanf, precisamos informar uma expressão que modifica o %s
    //Abaixo temos um [^\n], ond o ^ indica qualquer conjunto de símbolos que ocorra antes de um \n. Dessa forma, o programa vai ler tudo até chegar no \n do final da linha.
    scanf(" %[^\n]s", palavra);

    //Tamanho da palavra
    tam = tamanhoString(palavra);

    printf("Tamanho da palavra: %d\n", tam);

    //Função que copia palavra em palavra2
    copiaString(palavra, palavra2);

    printf("Palavra copiada: %s\n", palavra2);

    printf("Digite a segunda palavra\n");

    scanf(" %[^\n]s", palavra2);

    //Função que compara duas strings, pela ordem lexográfica (dicionário)
    ok = comparaStrings(palavra, palavra2);

    //Se for 0, são iguais. Se for < 0, a primeira palavra aparece depois (é maior). Se for > 0, a segunda palavra aparece depois.
    if(ok == 0) printf("São iguais!\n");
    else if(ok < 0) printf("%s é maior que %s\n", palavra, palavra2);
    else printf("%s é maior que %s\n", palavra2, palavra);

    printf("Juntando as duas palavras: ");

    //Concatena (junta) as duas strings. Aqui a string grande será retornada pela função
    grande = concatenaString(palavra, palavra2);

    printf("%s\n", grande);

    printf("%s é substring de %s?\n", palavra, palavra2);

    //Verifica se a palavra está contida (é um pedaço) de palavra2
    ok = verificaSubstring(palavra, palavra2);

    if(ok) printf("Sim, eh substring\n");
    else printf("Nao, nao eh substring\n");

    return 0;
}
