# IFBA - Estrutura de Dados

- **Projeto:** Lista de Alunos do IFBA
- **Professor:** Felipe Gustavo de Souza Gomes
- **Semestre:** 3
- **Ano:** 2024.1

## Integrantes do Projeto

<table>
  <tr>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/165097289?v=4" width="100px;" alt="Foto do Integrante Igor"/><br />
      <sub><b>Igor Cauan</b></sub>
    </td>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/80362674?v=4" width="100px;" alt="Foto do Integrante Janderson"/><br />
      <sub><b>Janderson Mota</b></sub>
    </td>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/157417082?v=4" width="100px;" alt="Foto do Integrante Saulo"/><br />
      <sub><b>Saulo Melo</b></sub>
    </td>
  </tr>
</table>

## Descrição

Este projeto implementa um conjunto de operações de **CRUD** (Create, Read, Update, Delete) utilizando **listas encadeadas** em C, ao invés de banco de dados. As operações envolvem o cadastro, remoção, atualização e exibição de alunos, além de estatísticas sobre as notas.

O objetivo é consolidar o aprendizado sobre listas encadeadas e manipulação de memória. O projeto será avaliado com base no funcionamento correto das operações propostas.

## Funcionalidades

O sistema deve permitir as seguintes operações:

1. **Cadastro de um novo aluno**
   - Inserir informações do aluno: identificador, nome e nota.
   
2. **Remoção de um aluno**
   - Remover aluno da lista pelo identificador.

3. **Mostrar aluno por identificador**
   - Exibir os dados de um aluno específico buscando pelo identificador.

4. **Editar um aluno**
   - Permitir a edição dos dados de um aluno através do seu identificador.

5. **Mostrar todos os alunos**
   - Listar todos os alunos cadastrados na lista encadeada.

6. **Estatísticas sobre as notas dos alunos**
   - Exibir a maior nota, a menor nota e a média das notas dos alunos.

7. **Fechar o programa**
   - Encerrar o sistema.

## Estrutura de Dados

A lista encadeada utiliza uma `struct` para armazenar as seguintes informações:

```c
struct Aluno {
    int identificador;
    char nome[255];
    float nota;
    struct Aluno *proximo;
};
