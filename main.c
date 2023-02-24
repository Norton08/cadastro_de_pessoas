#include "cadastro_filmes.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    Filme *novoFilme;
    char titulo[50];
    char busca[50];
    int opcao = 0;
    while (opcao != 6)
    {
        printf("\n-------- Cadastro de Filmes --------\n");
        printf("Escolha uma opcao:\n");
        printf("1. Cadastrar um novo filme\n");
        printf("2. Remover um filme do cadastro\n");
        printf("3. Buscar um filme por titulo, diretor ou genero\n");
        printf("4. Visualizar todos os filmes cadastrados\n");
        printf("5. Combinar dois cadastros em um so\n");
        printf("6. Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            novoFilme = criarFilme();
            inserirFilme(novoFilme);
            break;
        case 2:
            printf("Digite o título do filme que deseja remover: ");
            fgets(titulo, 50, stdin);
            removerFilme(titulo);
            break;
        case 3:
            printf("Digite o termo de busca: ");
            fgets(busca, 50, stdin);
            buscarFilme(busca);
            break;
        case 4:
            visualizarTodos();
            break;
        case 5:
            combinarCadastros();
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}
