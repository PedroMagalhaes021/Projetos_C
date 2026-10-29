#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

// Cadastrar Aluno
void cadastrarAluno() {
    FILE *arquivo;
    Aluno aluno;
    
    arquivo = fopen("alunos.txt", "a");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }
    
    printf("\nDigite a Matrícula: ");
    scanf("%d", &aluno.matricula);
    getchar(); // Limpa o buffer do teclado
    
    printf("Digite o nome: ");
    scanf("%49[^\n]", aluno.nome);
    
    printf("Digite a Nota: ");
    scanf("%f", &aluno.nota);
    
    fprintf(arquivo, "%d;%s;%.2f\n", aluno.matricula, aluno.nome, aluno.nota);
    fclose(arquivo);
    printf("\nAluno cadastrado com sucesso!\n");
}

// Lista de Alunos
void listarAlunos() {
    FILE *arquivo;
    Aluno aluno;
    
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("\nArquivo ainda não existe!\n");
        return;
    }
    
    printf("\n============ LISTA DE ALUNOS ============");
    while (fscanf(arquivo, "%d;%49[^;];%f\n", &aluno.matricula, aluno.nome, &aluno.nota) == 3) {
        printf("\nMatricula: %d\n", aluno.matricula);
        printf("Nome: %s\n", aluno.nome);
        printf("Nota: %.2f\n", aluno.nota);
        printf("-------------------------\n");
    }
    fclose(arquivo);
}

// Pesquisar Aluno
void pesquisarAluno() {
    FILE *arquivo;
    Aluno aluno;
    int matriculaPesquisa;
    int encontrado = 0;
    
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("\nArquivo não criado!\n");
        return;
    }
    
    printf("\nDigite a matricula que deseja pesquisar: ");
    scanf("%d", &matriculaPesquisa);
    
    while (fscanf(arquivo, "%d;%49[^;];%f\n", &aluno.matricula, aluno.nome, &aluno.nota) == 3) {
        if (aluno.matricula == matriculaPesquisa) {
            printf("\nAluno Encontrado!\n");
            printf("Matricula: %d\n", aluno.matricula);
            printf("Nome: %s\n", aluno.nome);
            printf("Nota: %.2f\n", aluno.nota);
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0) {
        printf("\nAluno não encontrado!\n");
    }
    fclose(arquivo);
}

int main() {
    int opcao;
    do {
        printf("\n========================");
        printf("\n   SISTEMA DE ALUNOS");
        printf("\n========================");
        printf("\n1 - Cadastrar");
        printf("\n2 - Listar alunos");
        printf("\n3 - Pesquisar alunos");
        printf("\n0 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                pesquisarAluno();
                break;
            case 0:
                printf("\nPrograma Encerrado!\n");
                break;
            default:
                printf("\nOpção Inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
