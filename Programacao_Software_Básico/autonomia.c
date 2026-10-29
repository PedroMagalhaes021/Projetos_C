#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char marca[50];
    char modelo[50];
    int ano;
    float cdt; // Capacidade do tanque
    float csm; // Consumo
} Carro;


float calcular(float cdt, float csm) {
    return cdt * csm;
}

int main() {
    Carro carro[MAX];
    int quantidade = 0;
    int i;
    char opcao = 'S';

    printf("=======================\n");
    printf("    SISTEMA DE CADASTRO\n");
    printf("=======================\n");

    while (opcao == 'S' || opcao == 's') {

        printf("\n--------------------------\n");
        printf("Cadastro %d\n", quantidade + 1);
        printf("--------------------------\n");
        
        printf("ID: ");
        scanf("%d", &carro[quantidade].id);
        getchar();

        // CORREÇÃO: Lendo como string (%s) e sem o '&'
        printf("Digite a marca do carro: ");
        scanf("%49s", carro[quantidade].marca);
        getchar();

        // CORREÇÃO: Simplificado o scanf do modelo
        printf("Modelo: ");
        scanf("%49s", carro[quantidade].modelo);
        getchar();

        printf("Digite o ano do carro: ");
        scanf("%d", &carro[quantidade].ano);
        getchar();

        printf("Digite capacidade do tanque (Ltrs): ");
        scanf("%f", &carro[quantidade].cdt);
        getchar();

        printf("Digite o consumo (Km/L): ");
        scanf("%f", &carro[quantidade].csm);
        getchar();

        // Incrementa a quantidade de carros
        quantidade++;

        // Verifica se chegou ao limite
        if (quantidade == MAX) {
            printf("\nLimite maximo de cadastros atingido!\n");
            break;
        }

        // Pergunta se quer continuar
        printf("\nDeseja cadastrar outro carro? (S/N): ");
        scanf(" %c", &opcao);
        getchar();
    }
    
    // RELATORIO
    printf("\n\n===============================\n");
    printf("       RELATORIO GERAL\n");
    printf("===============================\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nCadastro %d\n", i + 1);
        printf("--------------------\n");
        printf("ID: %d\n", carro[i].id);
        printf("Marca: %s\n", carro[i].marca);
        printf("Modelo: %s\n", carro[i].modelo);
        printf("Ano: %d\n", carro[i].ano); // CORREÇÃO: Ano modificado para %d (inteiro)
        
        // CORREÇÃO: Exibindo a autonomia como float (.2f para duas casas decimais)
        printf("Autonomia: %.2f Km\n", calcular(carro[i].cdt, carro[i].csm));
    }

    printf("\n==========================\n");
    printf("TOTAL DE CARROS CADASTRADOS: %d\n", quantidade);
    printf("==========================\n");

    return 0;
}
