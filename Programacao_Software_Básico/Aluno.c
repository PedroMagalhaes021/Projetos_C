#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

int main() {
    Aluno a;
    
    printf("Matricula: ");
    scanf("%d", &a.matricula); 
    
    printf("Nome: ");
    scanf("%s", a.nome);      
    
    printf("Nota: ");
    scanf("%f", &a.nota);      
    
    return 0;
}

