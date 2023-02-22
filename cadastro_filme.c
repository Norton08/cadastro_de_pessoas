#include "cadastro_filmes.h"

struct filme
{
    char titulo[50];
    char diretor[50];
    int ano_lancamento;
    char genero[30];
};

Filme criarFilme() {
    Filme novoFilme;
    printf("Digite o título do filme: ");
    fgets(novoFilme.titulo, 50, stdin);
    printf("Digite o diretor do filme: ");
    fgets(novoFilme.diretor, 50, stdin);
    printf("Digite o ano de lançamento do filme: ");
    scanf("%d", &novoFilme.ano_lancamento);
    printf("Digite o gênero do filme: ");
    fgets(novoFilme.genero, 20, stdin);
    printf("Digite a avaliação do filme (0 a 10): ");
    scanf("%f", &novoFilme.avaliacao);
    return novoFilme;
}

void inserirFilme(Filme novoFilme) {
    FILE *arquivo = fopen("cadastro.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%d;%s;%f\n", novoFilme.titulo, novoFilme.diretor, novoFilme.ano_lancamento, novoFilme.genero, novoFilme.avaliacao);
        fclose(arquivo);
        printf("Filme cadastrado com sucesso!\n");
    } else {
        printf("Não foi possível abrir o arquivo de cadastro.\n");
    }
}

void removerFilme(char titulo[]) {
    FILE *arquivo = fopen("cadastro.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[100];
    int removido = 0;
    while (fgets(linha, 100, arquivo) != NULL) {
        if (strstr(linha, titulo) == NULL) {
            fputs(linha, temp);
        } else {
            removido = 1;
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove("cadastro.txt");
    rename("temp.txt", "cadastro.txt");
    if (removido) {
        printf("Filme removido com sucesso!\n");
    } else {
        printf("Filme não encontrado no cadastro.\n");
    }
}

void buscarFilme(char busca[]) {
    FILE *arquivo = fopen("cadastro.txt", "r");
    char linha[100];
    int encontrado = 0;
    while (fgets(linha, 100, arquivo) != NULL) {
        if (strstr(linha, busca) != NULL) {
            printf("%s", linha);
            encontrado = 1;
        }
    }
    fclose(arquivo);
    if (!encontrado) {
        printf("Nenhum filme encontrado para a busca: %s\n", busca);
    }
}