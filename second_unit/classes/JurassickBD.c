#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*BANCO DE DADOS DO JURASSIC PARK
  Informações do banco: nome do dinossauro, população (quantidade de espécimes) e alimentação (dieta dos bichinhos)
  Formato: NOME - QUANTIDADE ALIMENTACAO

  Vocês vão fazer um programa que vai realizar operações
  de atualização na base de dados do Jurassic Park
  - Adiciona novas especies
  - Remove especies (extincao)
  - Altera quantidade de especies
  - Imprime um relatorio com as especies
*/

//Função que realiza a adição de uma nova espécie à base de dados.
//A função vai inserir ordenando pelo nome do dinossauro.
//Caso o dinossauro já exista, ele adiciona a quantidade digitada pelo usuário à quantidade prévia existente da espécime
void adicionar_nova_especie(){
    //Começa limpando a tela para ficar biito
    system("cls || clear");

    //Serão utilizados dois arquivos: arq será utilizado para ler os dados e contém os dados originais, novo será um arquivo temporário para realizar as alterações.
    //Quando a função finalizar, vamos mover o arquivo novo para o lugar do arq para termos a versão mais atualizado dos dados
    FILE* arq = fopen("dino-data.txt", "r");
    FILE* novo = fopen("dino-temp.txt", "w");

   //VARIÁVEIS
   /*
    - qtd, nome, alimentacao - dados do dinossauro informados pelo usuário na entrada padrão
    - linha - auxiliar que vai armazenar uma linha lida do arquivo
    - aux, tail - strings auziliares para a lógica do programa
    - temp_qtd,tmp_a - variáveis auxiliares para a lógica do programa
    - ins, res - variáveis de guarda, vão testar retorno de funções ou condições lógicas no programa
    - i, j - controle de laço de repetição
   */
    int qtd, res, ins, tmp_qtd, i, j;
    char nome[100], aux[100], tail[100], linha[1000];
    char alimentacao, tmp_a;

    //Se ocorreu algum erro na abertura de qualquer um dos dois arquivos, para por aqui!
    if(arq == NULL || novo == NULL) printf("Erro ao abrir o arquivo!\n");
    //Se deu certo abrir os dois...
    else{
        //Lê os dados do usuário
        printf("\n\nDigite as informações necessarias.\nNome da especie: ");
        //leitura da string para permitir nomes compostos (com espaços em branco)
        scanf(" %[^\n]s", nome);
        printf("\nQuantidade no parque: ");
        scanf("%d", &qtd);
        printf("\nDieta preferida (use C para Carnivoros e H para herbivoros: ");

        //Laço para garantir que a entrada estará entre os dois valores solicitados
        do{
            scanf(" %c", &alimentacao);
            if(alimentacao != 'C' && alimentacao != 'H') printf("Valor invalido!\n");
        } while(alimentacao != 'C' && alimentacao != 'H');

        //Variável de guarda que indica se o valor digitado pelo usuário já foi inserido ou não. Inicializará com 0, indicando que não foi feita a inserção do novo dinossauro.
        ins = 0;

        //Enquanto não chegar no fim do arquivo, lê linha por linha
        while(fgets(linha, 1000, arq) != NULL){
            //Leitura formatada da linha lida, pegando o nome do dinossauro até encontrar o hífen (ver formato no início dos comentários do programa)
            sscanf(linha, "%[^-]s", aux);

            //Na formatação acima, a string aux encerra com um espaço em branco, então vamos substituí-lo por um '\0'
            aux[strlen(aux)-1] = '\0';

           //Pegando o restante das informações da linha na mão: vamos criar uma segunda string com o pedaço final da linha (do hífen para frente).
           for(i=strlen(aux), j = 0; linha[i] != '\0'; i++, j++)
                tail[j] = linha[i];

            tail[j] = '\0';

            //Lendo a segunda parte da linha e guardando os valores de quantidade e alimentação previamente armazenados
            sscanf(tail, " - %d %c", &tmp_qtd, &tmp_a);

            //Compara o nome do dinossauro digitado pelo usuário com o nome do dinossauro da linha atual do arquivo
            res = strcmp(nome, aux);

            //Se for o mesmo dinossauro, vamos apenas atualizar a quantidade da população, somando o valor digitado
            if(res == 0){
                printf("Especie ja existe no banco! Somando quantitativo...\n");
                //Imprime na string linha, não no arquivo. Após os condicionais essa linha será impressa na última instrução do laço
                sprintf(linha, "%s - %d %c\n", nome, qtd+tmp_qtd, tmp_a);
                //Marca que os dados digitados pelo usuário já foram tratados, e daqui pra frente é só copiar o que tem no arquivo original para o novo
                ins = 1;
            }
            //Se o nome digitado é menor e eu ainda não fiz a inserção do dado, a hora é agora!
            else if(res < 0 && ins == 0){
                //Insere a nova linha no arquivo novo
                fprintf(novo, "%s - %d %c\n", nome, qtd, alimentacao);
                //Marca que o dado foi inserido
                ins = 1;
            }

            //Imprime a linha lida do arquivo original para o novo
            fprintf(novo, "%s", linha);
        }

        //Se o laço terminar e nenhuma inserção foi feita, estamos diante de um de dois casos:
        //--> O arquivo estava vazio, e é a primeira inserção
        //--> O dinossauro adicionado será o último na ordem alfabética
        //Por isso, se ins for zero, temos que inserir os dados do usuário agora, ao término da cópia do arquivo
        if(ins == 0) fprintf(novo, "%s - %d %c\n", nome, qtd, alimentacao);

        printf("Insercao feita com sucesso!\n");

        //Fecha os arquivos!!!!
        fclose(arq);
        fclose(novo);

        //Como o system("pause") só funciona no windows, vou trocar por getchar() :)
        getchar();
        getchar();

        //Comando para mover o arquivo temporário novo para sobrescrever o arquivo original, mantendo o nome do original
        //Basicamente, copiando dino-temp para dino-data
        system("move dino-temp.txt dino-data.txt || mv dino-temp.txt dino-data.txt");
        system("cls || clear");
    }
}

//Função que remove um dinossauro da lista
//Será feita a remoção em função do nome
void remover_especie(){
    system("cls || clear");

    FILE* arq = fopen("dino-data.txt", "r");
    FILE* novo = fopen("dino-temp.txt", "w");

    char del[100], aux[100], linha[1000];
    int ok;

    if(arq == NULL || novo == NULL) printf("Oh Oh, arquivo bugou!\n");
    else{
        //Pede ao usuário o nome do dinossauro a ser removido
        printf("Digite o nome do dinossauro a ser removido: ");
        scanf(" %[^\n]s", del);

        printf("Deletar %s\n", del);

        //ok será uma guarda para verificar se deletou ou não. Vamos usar para saber se a operação executou.
        ok = 0;

        //lendo o arquivo, linha por linha
        while(fgets(linha, 1000, arq) != NULL){
            sscanf(linha, "%[^-]s", aux);

            aux[strlen(aux)-1] = '\0';

            //Se estou em uma linha onde o dinossauro é diferente ao que o usuário digitou, eu copio ela para o arquivo novo
            if(strcmp(aux, del) != 0)
                fprintf(novo, "%s", linha);
            //Se a linha é igual ao que o usuário digitou, eu não vou copiá-la para o arquivo novo (dessa forma, ela estará "apagada" lá)
            //E informo que a remoção ocorreu, setando ok como 1 (um)
            else
                ok = 1;
        }

        //fecha os arquivos!!!
        fclose(arq);
        fclose(novo);

        //Se removeu, imprime a mensagem de sucesso
        if(ok == 1)
            printf("Remocao realizada com sucesso!\n");
        //Senão, informa que o dinossauro não faz parte da base
        else
            printf("Dinossauro nao encontrado!\n");

        getchar();
        getchar();

        system("move dino-temp.txt dino-data.txt || mv dino-temp.txt dino-data.txt");
        system("cls || clear");
    }
}

//Função para imprimir o relatório com todos os dinossauros da base
void imprimir(){
    system("cls || clear");

    //Aqui só vamos precisar ler do arquivo e imprimir na tela
    FILE* arq = fopen("dino-data.txt", "r");
    char linha[1000];

    if(arq == NULL) printf("Big Trouble, Little China!\n");
    else{
        //Lê a linha, imprime a linha
        while(fgets(linha, 1000, arq) != NULL)
            printf("%s", linha);

        fclose(arq);

        getchar();
        getchar();
        system("cls || clear");
    }
}

//Função para atualizar a quantidade de especimes da população de um dinossauro
//Será feita em função do nome do dinossauro
void atualiza_especie(){
    system("cls || clear");

    FILE* arq = fopen("dino-data.txt", "r");
    FILE* novo = fopen("dino-temp.txt", "w");

    char up[100], aux[100], linha[1000];
    int ok, qtd, dieta;

    if(arq == NULL || novo == NULL) printf("Duuuuuuuuuuuuuuuuuuuuuuuude!\n");
    else{
        //Lendo dados da entrada
        printf("Digite o nome do dinossauro a ser atualizado: ");
        scanf(" %[^\n]s", up);
        printf("Digite a nova quantidade: ");
        scanf("%d", &qtd);

        //Variável para verificar se a atualização ocorreu
        ok = 0;

        //Lendo linha por linha, procurando o dinossauro informado pelo usuário
        while(fgets(linha, 1000, arq) != NULL){
            sscanf(linha, "%[^-]s", aux);

            aux[strlen(aux)-1] = '\0';

            //Se não for o dinossauro, só copia a linha para o novo arquivo
            if(strcmp(aux, up) != 0)
                fprintf(novo, "%s", linha);
            //Se achar o dinossauro, imprime no novo arquivo a quantidade digitada pelo usuário
            else{
                dieta = linha[strlen(linha)-2];
                fprintf(novo, "%s - %d %c\n", up, qtd, dieta);
                //marca que a atualização ocorreu
                ok = 1;
            }
        }

        //Fecha o arquivo!
        fclose(arq);
        fclose(novo);

        //Imprime de acordo com o valor de ok (se houve atualização ou não)
        if(ok)
            printf("Atualizacao realizada com sucesso!\n");
        else
            printf("Dinossauro nao encontrado\n");

        getchar();
        getchar();

        system("move dino-temp.txt dino-data.txt || mv dino-temp.txt dino-data.txt");
        system("cls || clear");
    }
}

//Função principal: controla o loop do programa, a impressão do menu e a entrada do usuário
int main(){
    //Variável para armazenar a opção do usuário (inicializado com qualquer valor para garantir a primeira execução do laço)
    char option = 'a';

    printf("Welcome to the Jurassic Park!\n\n");

    //Enquanto o usuário não digitar uma saída
    while(option != 'Q'){
		printf("MENU DE OPERACOES\n");
		printf("I - Inserir nova especie\n");
		printf("R - Remover especie\n");
		printf("A - Atualiza especie\n");
		printf("P - Imprime conteudo do banco\n");
		printf("Q - Sair\n");

		scanf(" %c", &option);

		//Chama a função de acordo com o que foi digitado pelo usuário, ou acusa que foi digitado uma opção inválida
		switch(option){
			case 'A': atualiza_especie(); break;
			case 'I': adicionar_nova_especie(); break;
			case 'P': imprimir(); break;
			case 'R': remover_especie(); break;
			case 'Q': break;
			default: printf("Opcao invalida!\n");
		}

		//Função que executa o comando de limpar terminal do SO. cls no Windows, clear no linux
        system("cls || clear");
	}
}
