#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Aluno {
  int identificador;
  char nome[255];
  float nota;
  struct Aluno *proximo;
};

/* COMANDO:
** 'malloc' para alocar memória para um novo aluno, garantindo que ele seja
*adicionado à lista encadeada.
*/
void cadastrarAluno(struct Aluno **aluno) {
  // Criação de um novo aluno
  struct Aluno *novoAluno = (struct Aluno *)malloc(sizeof(struct Aluno));

  printf("Digite o identificador (nº): ");
  scanf("%d", &novoAluno->identificador);

  printf("Digite o nome: ");
  scanf("%s", novoAluno->nome);

  printf("Digite o nota: ");
  scanf("%f", &novoAluno->nota);

  // Adicionando o novo aluno no início da lista encadeada
  novoAluno->proximo = *aluno;
  *aluno = novoAluno;

  printf("\nAluno cadastrado com sucesso!\n\n");
}

void removerAluno() {}

void exibirAluno() {}

// Busca aluno pelo identificador.
void buscarAlunoPorIdentificador(struct Aluno *aluno, int identificador) {

  // Indice atual é um ponteiro do tipo aluno e que vai armazenar o aluno do
  // primeiro nó, para iniciar a busca.
  struct Aluno *indiceAtual = aluno;

  // Enquanto o IndiceAtual for diferente de Nulo, ele não chegou no final da
  // lista encadeada, portanto continuar na busca.
  while (indiceAtual != NULL) {
    // Condição que verifica se o identificador do nó atual é igual ao que estou
    // buscando.
    if (indiceAtual->identificador == identificador) {
      printf("Nome: %d\n", indiceAtual->nome);
      printf("Nota: %d\n", indiceAtual->nota);
      printf("Identificador %d\n", indiceAtual->identificador);
    }

    // indiceAtual avança para o proximo nó da lista encadeada, caso a condição
    // do if não seja atendida
    indiceAtual = indiceAtual->proximo;
  }

  printf("\nAluno do identificador %d não foi encontrado na lista encadeada\n",
         identificador);
}

void removerAlunoPorIdentificador(struct Aluno **aluno, int identificador) {

  struct Aluno **indiceAtual = *aluno;  // Inicio da lista
  struct Aluno **indiceAnterior = NULL; // Ponteiro para o nó anterior

  while (indiceAtual != NULL) {
    if (indiceAtual->identificador == identificador) {
      // Se o aluno estiver no inicio da lista, ele vai ser apagado e a lista
      // vai ser atualizada
      if (indiceAnterior == NULL) {
        *aluno = indiceAtual->proximo;
      } else {
        indiceAnterior->proximo = indiceAtual->proximo;
      }
      free(indiceAtual);
      printf("Aluno com o identificador %d, foi removido da lista!",
             identificador);

      return;
    }

    // Movimento dos ponteiros para a frente na lista
    indiceAnterior = indiceAtual;
    indiceAtual = indiceAtual->proximo;
  }

  printf("Aluno com o identificador %d não foi encontrado", identificador);
}

void exibirEstatistica() {}

int main() {
  struct Aluno *aluno = NULL;
  struct Aluno alunos[10];

  int opcao;

  do {
    printf("SELECIONE UMA OPÇÃO");
    printf("( 0 ) Sair || ( 1 ) Cadastra aluno || ( 2 ) Remover aluno || ( 3 ) "
           "Exibir alunos || ( 4 ) Estatística");
    scanf("%d", &opcao);

    switch (opcao) {
    case 01:
      // Cadastro novo aluno
      cadastrarAluno(&aluno);
      break;

    case 02:
      // Remoção aluno pelo identificador.
      break;

    case 03:
      // Exibir todos os alunos da lista.
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
