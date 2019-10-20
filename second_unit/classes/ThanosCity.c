#include <stdio.h>
#include <stdlib.h>

//Em homenagem a Ana Victoria

//Função que faz a leitura das informações
int carrega_cidade(int* vet){
    int i, predios;

    //Lê a quantidade de lotes
    scanf("%d", &predios);

    //Lê a altura em cada lote
    for(i=0; i<predios; i++)
        scanf("%d", &vet[i]);

    return predios;
}

//Função que calcula a media das alturas dos lotes da cidade
float funcao_media(int pred, int* city){
    int i;
    //Somador
    float media = 0.0;

    for(i=0; i<pred; i++)
        //Soma todas as alturas...
        media += city[i];

    //...e divide pela quantidade de lotes
    return media/pred;
}

//Função para atribuir o valor da altura do predio mais alto
void procura_maior(int pred, int* city, int* taller){
    int i, tall = 0;

    //Compara a variável tall (inicialmente 0) com todas as posições do vetor cidade. Sempre que encontrar alguém maior, tall recebe o valor
    for(i=0; i<pred; i++)
        if(city[i] > tall)
            tall = city[i];

    *taller = tall;
}

//Função que derruba o prédio. Ela irá remover o prédio (colocar sua altura com 0), e recalcular o valor do prédio mais alto e da media
void derruba_predio(int alvo, int* city, int pred, int* taller, float* averg){
    city[alvo] = 0;
    procura_maior(pred, city, taller);
    *averg = funcao_media(pred, city);
}

//Função que imprime as alturas ordenadas
//Vamos utilizar um algoritmo de ordenação bubblesort, explicado mais abaixo
void imprime_alturas_ordenadas(int lotes, int* cidades){
    int i, j, aux;

    /*Ordenando o vetor. O Bubblesort irá utilizar dois laços para ordenar todo o vetor.
      O laço mais externo, controlado pelo i, marcará a posição onde iremos colocar o menor elemento encontrado no vetor até o momento. Dessa forma, quando i for 0, estaremos procurando o menor de todos, quand for 1 o segundo menor, e assim sucessivamente.
      A cada laço de i completo, temos o menor daquela posição garantido.
      O segundo laço compara o menor valor encontrado e guardado em i com os outros valores no restante do vetor. É importante notar que ele só executará de i para frente no vetor, porque os elementos anteriores são menores com certeza, a medida que o i avança.

      Visualmente:

      3 4 1 2 5

      i=0 significa a posição que atualmente contem o 3. O laço j vai comparar de 4 para frente procurando um valor menor que 3

      j=1 é 4, que é maior
      j=2 é 1 que é menor! Então vamos trocar o 3 e o 1 de lugar

      1 4 3 2 5

      O laço do j continua, mas agora o elemento que está em i para comparar é o 1, não o 3

      j=3 é 2, que é maior que 1
      j=4 é 5 que é maior

      O laço do j acaba e o i atualiza para 1, que contém o valor 4. Nesse ponto, não precisamos mais verificar a posição 0 porque temos garantia que 1 é o menor valor do vetor.

      j = 2 é 3, que é menor que 4! troca 4 e 3 de lugar

      1 3 4 2 5

      j=3 é 2, que é menor que 3! troca 2 e 3 de lugar

      1 2 4 3 5

      j = 4 é 5, que é maior, não faz nada

      Executando até o fim, temos o vetor ordenado :)
    */

    for(i=0; i<lotes-1; i++)
        for(j=i+1; j<lotes; j++)
            if(cidades[i] > cidades[j]){
                aux = cidades[j];
                cidades[j] = cidades[i];
                cidades[i] = aux;
            }

    //Agora vamos percorrer o vetor e imprimir onde for diferente de zero!
    for(i=0; i<lotes; i++)
        if(cidades[i] != 0)
            printf("%d ", cidades[i]);
    printf("\n");
}

//Função principal: coordena a interação do programa. Não deve ser alterado, porque é daqui que você vai derivar as assinaturas
//das funções que precisa fazer :)
int main(){
    /*Variáveis
    - cidade: vetor de alturas que representará a cidade e seus prédios
    - mais_alto: guarda a aaltura do prédio mais alto
    - media_altura: guarda a media de altura dos predios da cidade
    - lotes: guarda a quantidade de lotes que existem na cidade
    */
    int cidade[100] = {0};
    int mais_alto = 0;
    float media_altura;
    int i, j, lotes;

    //Primeira função: faz a leitura das informações a partir da entrada. Recebe como parâmetro o vetor cidade e retorna um inteiro, armazenado em lotes
    lotes = carrega_cidade(cidade);

    //Calcula a media de altura a partir da funcao_media. Passa a quantidade de lotes e o vetor de cidades e retorna um float com a media
    media_altura = funcao_media(lotes, cidade);
    //Procura o valor do prédio mais alto. Armazena na variável mais_alto, que é alterada por referência pela função
    procura_maior(lotes, cidade, &mais_alto);

    printf("Maior altura: %d\n", mais_alto);
    printf("Altura Média: %.2f\n", media_altura);

    //i contém agora o valor de um terço dos lotes
    i=lotes/3;

    //Laço que derruba um terço dos prédios (roda i vezes)
    while(i>0){
            //Sorteia um aposição aleatória, se não derrubou bota o prédio abaixo com a função derruba_predio
            j = rand()%lotes + 1;
            if(cidade[j] > 0){
                printf("Derruba prédio no lote %d\n", j);
                //Quando um prédio cai, sua media de altura muda, e o mais alto pode vir a mudar também!
                derruba_predio(j, cidade, lotes, &mais_alto, &media_altura);
            }
            //Caso o lote já tenha sido derrubado, reset o laço para não contar essa iteração
            else
                i++;
            i--;
    }

    //Imprime o resultado final
    printf("Maior altura: %d\n", mais_alto);
    printf("Altura Média: %.2f\n", media_altura);

    imprime_alturas_ordenadas(lotes, cidade);

    return 0;
}
