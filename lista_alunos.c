#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int identificador;
    char nome[255];
    float nota;
    struct Aluno *proximo;
};

/* COMANDO:
** 'malloc' para alocar memória para um novo aluno, garantindo que ele seja adicionado à lista encadeada.
*/
void cadastrarAluno(struct Aluno **aluno) {
    // Criação de um novo aluno
    struct Aluno *novoAluno = (struct Aluno *)malloc(sizeof(struct Aluno))

    printf("Digite o identificador (nº): ");
    scanf("%d", &novoAluno->identificador);

    printf("Digite o nome: ");
    scanf("%s", novoAluno->nome);

    printf("Digite o nota: ");
    scanf("%f", &novoAluno->nota);

    //Adicionando o novo aluno no início da lista encadeada
    novoAluno->proximo = *aluno;
    *aluno = novoAluno;

    printf("\nAluno cadastrado com sucesso!\n\n");
}

void removerAluno() {}

void exibirAluno() {}

void exibirEstatistica() {}

int main()
{
    struct Aluno *aluno = NULL;
    struct Aluno alunos[10];
    
    int opcao;

    do {
        printf("SELECIONE UMA OPÇÃO");
        printf("( 0 ) Sair || ( 1 ) Cadastra aluno || ( 2 ) Remover aluno || ( 3 ) Exibir alunos || ( 4 ) Estatística");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 01:
            //Cadastro novo aluno
            cadastrarAluno(&aluno);
            break;
        
        case 02:
            //Remoção aluno pelo identificador.
            break;
        
        case 03:
            //Exibir todos os alunos da lista.
            break;
        
        case 04:
            /*Exibir as estatísticas:
            ** maior nota.
            ** menor nota.
            ** média das notas dos alunos.
            */
            break;
        
        case 0:
            printf("Programa encerrado.\n");
            break;
        
        default:
            printf("\nOpção inválida!\n");
            for (int i = 0; i < 10000; i++)
            clear();
            break;
        }
    } while (opcao != 0);

    return 0;
}
