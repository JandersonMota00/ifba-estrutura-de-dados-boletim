#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Aluno
{
  int identificador;
  char nome[255];
  float nota;
  struct Aluno *proximo;
};

/* COMANDO:
** 'malloc' para alocar memória para um novo aluno, garantindo que ele seja
*adicionado à lista encadeada.
*/
void cadastrarAluno(struct Aluno **aluno)
{
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

// Busca aluno pelo identificador.
void buscarAlunoPorIdentificador(struct Aluno *aluno, int identificador)
{

  // Variável de controle para encontrar aluno
  int encontrado = 0;

  // Indice atual é um ponteiro do tipo aluno e que vai armazenar o aluno do
  // primeiro nó, para iniciar a busca.
  struct Aluno *indiceAtual = aluno;

  // Enquanto o IndiceAtual for diferente de Nulo, ele não chegou no final da
  // lista encadeada, portanto continuar na busca.
  while (indiceAtual != NULL)
  {
    // Condição que verifica se o identificador do nó atual é igual ao que estou
    // buscando.
    if (indiceAtual->identificador == identificador)
    {
      printf("Nome: %s\n", indiceAtual->nome);
      printf("Nota: %f\n", indiceAtual->nota);
      printf("Identificador %d\n", indiceAtual->identificador);
      // Aluno encontrado
      encontrado = 1;
      // Encerrar a busca
      break;
    }

    // indiceAtual avança para o proximo nó da lista encadeada, caso a condição
    // do if não seja atendida
    indiceAtual = indiceAtual->proximo;
  }

  // Exibe a mensagem caso o aluno não seja encontrado
  if (!encontrado)
  {
    printf("\nAluno do identificador %d não foi encontrado na lista encadeada\n",
           identificador);
  }
}

void removerAlunoPorIdentificador(struct Aluno **aluno, int identificador)
{

  struct Aluno *indiceAtual = *aluno;  // Inicio da lista
  struct Aluno *indiceAnterior = NULL; // Ponteiro para o nó anterior

  while (indiceAtual != NULL)
  {
    if (indiceAtual->identificador == identificador)
    {
      // Se o aluno estiver no inicio da lista, ele vai ser apagado e a lista
      // vai ser atualizada
      if (indiceAnterior == NULL)
      {
        *aluno = indiceAtual->proximo;
        // Remoção dos alunos caso não seja o primeiro aluno da lista a ser removido, ou seja, segundo em diante
      }
      else
      {
        indiceAnterior->proximo = indiceAtual->proximo;
      }

      // Liberar a memória do aluno removido
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

void editarAluno(struct Aluno *aluno, int identificador)
{
  struct Aluno *indiceAtual = aluno;

  while (indiceAtual != NULL)
  {
    if (indiceAtual->identificador == identificador)
    {
      printf("Aluno encontrado! Você pode editar os dados:\n");

      printf("Digite o novo nome: ");
      scanf("%s", indiceAtual->nome);

      printf("Digite a nova nota: ");
      scanf("%f", &indiceAtual->nota);

      printf("Dados do aluno atualizados com sucesso!\n");
      return;
    }
    indiceAtual = indiceAtual->proximo;
  }

  printf("Aluno com o identificador %d não foi encontrado.\n", identificador);
}

void exibirAluno(struct Aluno *aluno)
{
  if (aluno == NULL)
  {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  printf("\nLista de Alunos:\n");
  struct Aluno *indiceAtual = aluno;
  while (indiceAtual != NULL)
  {
    printf("Identificador: %d\n", indiceAtual->identificador);
    printf("Nome: %s\n", indiceAtual->nome);
    printf("Nota: %.2f\n", indiceAtual->nota);
    printf("-----------------------------\n");
    indiceAtual = indiceAtual->proximo;
  }
}

void exibirEstatistica(struct Aluno *aluno)
{
  if (aluno == NULL)
  {
    printf("Nenhum aluno cadastrado!\n");
    return;
  }

  float maiorNota = aluno->nota;
  float menorNota = aluno->nota;
  float somaNotas = 0.0;
  int contagem = 0;
  struct Aluno *indiceAtual = aluno;

  while (indiceAtual != NULL)
  {
    if (indiceAtual->nota > maiorNota)
    {
      maiorNota = indiceAtual->nota;
    }
    if (indiceAtual->nota < menorNota)
    {
      menorNota = indiceAtual->nota;
    }
    somaNotas += indiceAtual->nota;
    contagem++;
    indiceAtual = indiceAtual->proximo;
  }

  float mediaNotas = somaNotas / contagem;

  printf("\nEstatísticas dos Alunos:\n");
  printf("Maior nota: %.2f\n", maiorNota);
  printf("Menor nota: %.2f\n", menorNota);
  printf("Média das notas: %.2f\n", mediaNotas);
}

int main()
{
  struct Aluno *aluno = NULL;
  struct Aluno alunos[10];

  int identificadorMenu;
  int opcao;

  do
  {
    printf("SELECIONE UMA OPÇÃO");
    printf("( 0 ) Sair || ( 1 ) Cadastrar aluno || ( 2 ) Remover aluno || ( 3 ) Buscar aluno por identificador || ( 4 ) Editar aluno por identificador || (5) Mostrar todos os alunos da lista || (6) Ver as estatísticas do aluno)");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 01:
      // Cadastro novo aluno
      cadastrarAluno(&aluno);
      break;

    case 02:
      // Remoção aluno pelo identificador.
      printf("Digite o identificador do aluno desejado para a remoção: ");
      scanf("%d",&identificadorMenu);
      removerAlunoPorIdentificador(&aluno, identificadorMenu);
      break;

    case 03:
      printf("Digite o identificador do aluno desejado: ");
      scanf("%d", &identificadorMenu);
      buscarAlunoPorIdentificador(aluno, identificadorMenu);
      break;

    case 04:
      // Editar um aluno buscando ele pelo identificador
      printf("Digite o identificador do aluno que deseja editar: ");
      scanf("%d", &identificadorMenu);
      editarAluno(aluno, identificadorMenu);
      break;

    case 05:
      // Exibir todos os alunos da lista
      exibirAluno(aluno);
      break;

    case 06:
      /*Exibir as estatísticas:
      ** maior nota.
      ** menor nota.
      ** média das notas dos alunos.
      */
      exibirEstatistica(aluno);
      break;

    case 0:
      printf("Programa encerrado.\n");
      break;

    default:
      printf("\nOpção inválida!\n");
      for (int i = 0; i < 10000; i++)
        system("clear");
      break;
    }
  } while (opcao != 0);

  return 0;
}
