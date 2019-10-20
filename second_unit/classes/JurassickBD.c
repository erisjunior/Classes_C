#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*BANCO DE DADOS DO JURASSIC PARK
  Informa��es do banco: nome do dinossauro, popula��o (quantidade de esp�cimes) e alimenta��o (dieta dos bichinhos)
  Formato: NOME - QUANTIDADE ALIMENTACAO

  Voc�s v�o fazer um programa que vai realizar opera��es
  de atualiza��o na base de dados do Jurassic Park
  - Adiciona novas especies
  - Remove especies (extincao)
  - Altera quantidade de especies
  - Imprime um relatorio com as especies
*/

//Fun��o que realiza a adi��o de uma nova esp�cie � base de dados.
//A fun��o vai inserir ordenando pelo nome do dinossauro.
//Caso o dinossauro j� exista, ele adiciona a quantidade digitada pelo usu�rio � quantidade pr�via existente da esp�cime
void adicionar_nova_especie(){
    //Come�a limpando a tela para ficar biito
    system("cls || clear");

    //Ser�o utilizados dois arquivos: arq ser� utilizado para ler os dados e cont�m os dados originais, novo ser� um arquivo tempor�rio para realizar as altera��es.
    //Quando a fun��o finalizar, vamos mover o arquivo novo para o lugar do arq para termos a vers�o mais atualizado dos dados
    FILE* arq = fopen("dino-data.txt", "r");
    FILE* novo = fopen("dino-temp.txt", "w");

   //VARI�VEIS
   /*
    - qtd, nome, alimentacao - dados do dinossauro informados pelo usu�rio na entrada padr�o
    - linha - auxiliar que vai armazenar uma linha lida do arquivo
    - aux, tail - strings auziliares para a l�gica do programa
    - temp_qtd,tmp_a - vari�veis auxiliares para a l�gica do programa
    - ins, res - vari�veis de guarda, v�o testar retorno de fun��es ou condi��es l�gicas no programa
    - i, j - controle de la�o de repeti��o
   */
    int qtd, res, ins, tmp_qtd, i, j;
    char nome[100], aux[100], tail[100], linha[1000];
    char alimentacao, tmp_a;

    //Se ocorreu algum erro na abertura de qualquer um dos dois arquivos, para por aqui!
    if(arq == NULL || novo == NULL) printf("Erro ao abrir o arquivo!\n");
    //Se deu certo abrir os dois...
    else{
        //L� os dados do usu�rio
        printf("\n\nDigite as informa��es necessarias.\nNome da especie: ");
        //leitura da string para permitir nomes compostos (com espa�os em branco)
        scanf(" %[^\n]s", nome);
        printf("\nQuantidade no parque: ");
        scanf("%d", &qtd);
        printf("\nDieta preferida (use C para Carnivoros e H para herbivoros: ");

        //La�o para garantir que a entrada estar� entre os dois valores solicitados
        do{
            scanf(" %c", &alimentacao);
            if(alimentacao != 'C' && alimentacao != 'H') printf("Valor invalido!\n");
        } while(alimentacao != 'C' && alimentacao != 'H');

        //Vari�vel de guarda que indica se o valor digitado pelo usu�rio j� foi inserido ou n�o. Inicializar� com 0, indicando que n�o foi feita a inser��o do novo dinossauro.
        ins = 0;

        //Enquanto n�o chegar no fim do arquivo, l� linha por linha
        while(fgets(linha, 1000, arq) != NULL){
            //Leitura formatada da linha lida, pegando o nome do dinossauro at� encontrar o h�fen (ver formato no in�cio dos coment�rios do programa)
            sscanf(linha, "%[^-]s", aux);

            //Na formata��o acima, a string aux encerra com um espa�o em branco, ent�o vamos substitu�-lo por um '\0'
            aux[strlen(aux)-1] = '\0';

           //Pegando o restante das informa��es da linha na m�o: vamos criar uma segunda string com o peda�o final da linha (do h�fen para frente).
           for(i=strlen(aux), j = 0; linha[i] != '\0'; i++, j++)
                tail[j] = linha[i];

            tail[j] = '\0';

            //Lendo a segunda parte da linha e guardando os valores de quantidade e alimenta��o previamente armazenados
            sscanf(tail, " - %d %c", &tmp_qtd, &tmp_a);

            //Compara o nome do dinossauro digitado pelo usu�rio com o nome do dinossauro da linha atual do arquivo
            res = strcmp(nome, aux);

            //Se for o mesmo dinossauro, vamos apenas atualizar a quantidade da popula��o, somando o valor digitado
            if(res == 0){
                printf("Especie ja existe no banco! Somando quantitativo...\n");
                //Imprime na string linha, n�o no arquivo. Ap�s os condicionais essa linha ser� impressa na �ltima instru��o do la�o
                sprintf(linha, "%s - %d %c\n", nome, qtd+tmp_qtd, tmp_a);
                //Marca que os dados digitados pelo usu�rio j� foram tratados, e daqui pra frente � s� copiar o que tem no arquivo original para o novo
                ins = 1;
            }
            //Se o nome digitado � menor e eu ainda n�o fiz a inser��o do dado, a hora � agora!
            else if(res < 0 && ins == 0){
                //Insere a nova linha no arquivo novo
                fprintf(novo, "%s - %d %c\n", nome, qtd, alimentacao);
                //Marca que o dado foi inserido
                ins = 1;
            }

            //Imprime a linha lida do arquivo original para o novo
            fprintf(novo, "%s", linha);
        }

        //Se o la�o terminar e nenhuma inser��o foi feita, estamos diante de um de dois casos:
        //--> O arquivo estava vazio, e � a primeira inser��o
        //--> O dinossauro adicionado ser� o �ltimo na ordem alfab�tica
        //Por isso, se ins for zero, temos que inserir os dados do usu�rio agora, ao t�rmino da c�pia do arquivo
        if(ins == 0) fprintf(novo, "%s - %d %c\n", nome, qtd, alimentacao);

        printf("Insercao feita com sucesso!\n");

        //Fecha os arquivos!!!!
        fclose(arq);
        fclose(novo);

        //Como o system("pause") s� funciona no windows, vou trocar por getchar() :)
        getchar();
        getchar();

        //Comando para mover o arquivo tempor�rio novo para sobrescrever o arquivo original, mantendo o nome do original
        //Basicamente, copiando dino-temp para dino-data
        system("move dino-temp.txt dino-data.txt || mv dino-temp.txt dino-data.txt");
        system("cls || clear");
    }
}

//Fun��o que remove um dinossauro da lista
//Ser� feita a remo��o em fun��o do nome
void remover_especie(){
    system("cls || clear");

    FILE* arq = fopen("dino-data.txt", "r");
    FILE* novo = fopen("dino-temp.txt", "w");

    char del[100], aux[100], linha[1000];
    int ok;

    if(arq == NULL || novo == NULL) printf("Oh Oh, arquivo bugou!\n");
    else{
        //Pede ao usu�rio o nome do dinossauro a ser removido
        printf("Digite o nome do dinossauro a ser removido: ");
        scanf(" %[^\n]s", del);

        printf("Deletar %s\n", del);

        //ok ser� uma guarda para verificar se deletou ou n�o. Vamos usar para saber se a opera��o executou.
        ok = 0;

        //lendo o arquivo, linha por linha
        while(fgets(linha, 1000, arq) != NULL){
            sscanf(linha, "%[^-]s", aux);

            aux[strlen(aux)-1] = '\0';

            //Se estou em uma linha onde o dinossauro � diferente ao que o usu�rio digitou, eu copio ela para o arquivo novo
            if(strcmp(aux, del) != 0)
                fprintf(novo, "%s", linha);
            //Se a linha � igual ao que o usu�rio digitou, eu n�o vou copi�-la para o arquivo novo (dessa forma, ela estar� "apagada" l�)
            //E informo que a remo��o ocorreu, setando ok como 1 (um)
            else
                ok = 1;
        }

        //fecha os arquivos!!!
        fclose(arq);
        fclose(novo);

        //Se removeu, imprime a mensagem de sucesso
        if(ok == 1)
            printf("Remocao realizada com sucesso!\n");
        //Sen�o, informa que o dinossauro n�o faz parte da base
        else
            printf("Dinossauro nao encontrado!\n");

        getchar();
        getchar();

        system("move dino-temp.txt dino-data.txt || mv dino-temp.txt dino-data.txt");
        system("cls || clear");
    }
}

//Fun��o para imprimir o relat�rio com todos os dinossauros da base
void imprimir(){
    system("cls || clear");

    //Aqui s� vamos precisar ler do arquivo e imprimir na tela
    FILE* arq = fopen("dino-data.txt", "r");
    char linha[1000];

    if(arq == NULL) printf("Big Trouble, Little China!\n");
    else{
        //L� a linha, imprime a linha
        while(fgets(linha, 1000, arq) != NULL)
            printf("%s", linha);

        fclose(arq);

        getchar();
        getchar();
        system("cls || clear");
    }
}

//Fun��o para atualizar a quantidade de especimes da popula��o de um dinossauro
//Ser� feita em fun��o do nome do dinossauro
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

        //Vari�vel para verificar se a atualiza��o ocorreu
        ok = 0;

        //Lendo linha por linha, procurando o dinossauro informado pelo usu�rio
        while(fgets(linha, 1000, arq) != NULL){
            sscanf(linha, "%[^-]s", aux);

            aux[strlen(aux)-1] = '\0';

            //Se n�o for o dinossauro, s� copia a linha para o novo arquivo
            if(strcmp(aux, up) != 0)
                fprintf(novo, "%s", linha);
            //Se achar o dinossauro, imprime no novo arquivo a quantidade digitada pelo usu�rio
            else{
                dieta = linha[strlen(linha)-2];
                fprintf(novo, "%s - %d %c\n", up, qtd, dieta);
                //marca que a atualiza��o ocorreu
                ok = 1;
            }
        }

        //Fecha o arquivo!
        fclose(arq);
        fclose(novo);

        //Imprime de acordo com o valor de ok (se houve atualiza��o ou n�o)
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

//Fun��o principal: controla o loop do programa, a impress�o do menu e a entrada do usu�rio
int main(){
    //Vari�vel para armazenar a op��o do usu�rio (inicializado com qualquer valor para garantir a primeira execu��o do la�o)
    char option = 'a';

    printf("Welcome to the Jurassic Park!\n\n");

    //Enquanto o usu�rio n�o digitar uma sa�da
    while(option != 'Q'){
		printf("MENU DE OPERACOES\n");
		printf("I - Inserir nova especie\n");
		printf("R - Remover especie\n");
		printf("A - Atualiza especie\n");
		printf("P - Imprime conteudo do banco\n");
		printf("Q - Sair\n");

		scanf(" %c", &option);

		//Chama a fun��o de acordo com o que foi digitado pelo usu�rio, ou acusa que foi digitado uma op��o inv�lida
		switch(option){
			case 'A': atualiza_especie(); break;
			case 'I': adicionar_nova_especie(); break;
			case 'P': imprimir(); break;
			case 'R': remover_especie(); break;
			case 'Q': break;
			default: printf("Opcao invalida!\n");
		}

		//Fun��o que executa o comando de limpar terminal do SO. cls no Windows, clear no linux
        system("cls || clear");
	}
}
