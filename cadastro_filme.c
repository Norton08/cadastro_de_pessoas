#include "cadastro_filmes.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct filme
{
    char titulo[50];
    char diretor[50];
    int ano_lancamento;
    char genero[30];
};

Filme *criarFilme()
{
    printf("Digite separando por _ ao invés de ")
    Filme *novoFilme = (Filme *)malloc(sizeof(Filme));
    printf("Digite o titulo do filme: ");
    scanf("%s", novoFilme->titulo);
    printf("Digite o diretor do filme: ");
    scanf("%s", novoFilme->diretor);
    printf("Digite o ano de lancamento do filme: ");
    scanf("%d", &novoFilme->ano_lancamento);
    printf("Digite o genero do filme: ");
    scanf("%s", novoFilme->genero);
    return novoFilme;
}

void inserirFilme(Filme *novoFilme)
{
    FILE *arquivo = fopen("filmes.txt", "a");
    if (arquivo != NULL)
    {
        fprintf(arquivo, "%s;%s;%d;%s\n",
                novoFilme->titulo,
                novoFilme->diretor,
                novoFilme->ano_lancamento,
                novoFilme->genero);

        fclose(arquivo);
        printf("Filme cadastrado com sucesso!\n");
    }
    else
    {
        printf("Não foi possível abrir o arquivo de cadastro.\n");
    }
}

void removerFilme(char titulo[])
{
    FILE *arquivo = fopen("filmes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[100];
    int removido = 0;
    while (fgets(linha, 100, arquivo) != NULL)
    {
        if (strstr(linha, titulo) == NULL)
        {
            fputs(linha, temp);
        }
        else
        {
            removido = 1;
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove("filmes.txt");
    rename("temp.txt", "filmes.txt");
    if (removido)
    {
        printf("Filme removido com sucesso!\n");
    }
    else
    {
        printf("Filme não encontrado no cadastro.\n");
    }
}

void buscarFilme(char busca[])
{
    FILE *arquivo = fopen("filmes.txt", "r");
    char linha[100];
    int encontrado = 0;
    while (fgets(linha, 100, arquivo) != NULL)
    {
        if (strstr(linha, busca) != NULL)
        {
            printf("%s", linha);
            encontrado = 1;
        }
    }
    fclose(arquivo);
    if (!encontrado)
    {
        printf("Nenhum filme encontrado para a busca: %s\n", busca);
    }
}

void visualizarTodos()
{
    FILE *arquivo = fopen("cadastro.txt", "r");
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    fclose(arquivo);
}

void combinarCadastros()
{
    FILE *arquivo1 = fopen("cadastro1.txt", "r");
    FILE *arquivo2 = fopen("cadastro2.txt", "r");
    FILE *arquivoNovo = fopen("cadastroNovo.txt", "w");
    char linha[100];
    while (fgets(linha, 100, arquivo1) != NULL)
    {
        fputs(linha, arquivoNovo);
    }
    while (fgets(linha, 100, arquivo2) != NULL)
    {
        fputs(linha, arquivoNovo);
    }
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoNovo);
    printf("Cadastros combinados com sucesso!\n");
}