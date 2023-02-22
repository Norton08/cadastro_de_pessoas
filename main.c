#include <stdio.h>
#include <unistd.h>
#include "cadastro_filmes.h"

int main() {
    char caminho[FILENAME_MAX];
    if (getcwd(caminho, sizeof(caminho)) != NULL) {
        FILE *arquivo = fopen(strcat(caminho, "/meu_arquivo.txt"), "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "Conteúdo do meu arquivo.\n");
            fclose(arquivo);
            printf("Arquivo criado com sucesso.\n");
        } else {
            printf("Não foi possível criar o arquivo.\n");
        }
    } else {
        printf("Não foi possível obter o caminho atual.\n");
    }

    return 0;
}
