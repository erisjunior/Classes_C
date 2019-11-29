typedef struct {
    char nome[100];
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
} Time;

Time* carrega_dados  (int *tamanho);
void  imprime_tabela (Time* campeonato, int tamanho);
