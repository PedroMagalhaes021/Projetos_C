// Online C compiler to run C program online
#include <stdio.h>
typedef struct{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
}Produto;

int main(){
    Produto p;

    FILE *arquivoesp;
    printf("===CADASTRPO DE PRODUTO===");
    printf("Digite o produto: ");
    scanf("%d",&p.codigo);
    printf("Digite o Nome: ");
    scanf("%49[^\n]",p.nome);
    printf("Digite o preco");
    scanf("%f",&p.preco);
    printf("Digite a Quantidade: ");
    scanf("%d",&p.quantidade);
    arquivoesp =fopen("produtos.txt","a");
    if(arquivoesp == NULL){
        printf("Erro  ao abrir arquivo!\n");
        return 1;
    }
    fprintf(arquivoesp,"%d;%s;%2.f;%d\n", p.codigo,p.nome,p.preco,p.quantidade);
    fclose(arquivoesp);
    printf("\nProduto cadastro com sucesso!");
    arquivoesp=fopen("produto.txt","r");
    if(arquivoesp==NULL){
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    printf("\n==========PRODUTOS CADASTRADOS==========");
    while(fscanf(arquivoesp,"%d;%49[^;],%f;%f\n",&p.codigo,p.nome,&p.preco,&p.quantidade)==4){
        printf("\nCodigo:%d\n",&p.codigo);
        printf("Nome: %s\n",&p.nome);
        printf("Preco: R$%.2f\n",&p.preco);
        printf("Quantidade: %d\n",&p.quantidade);
    }
    fclose(arquivoesp);
    return 0;
}
