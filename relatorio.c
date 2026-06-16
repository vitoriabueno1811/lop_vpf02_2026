#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct Produto{
    char produto[50];
    int quantidade;
    float preco;
};

void main(){
    SetConsoleOutputCP(CP_UTF8);

    int qtdLinhas = 0;
    struct Produto produtos[MAX_LINHAS];

    FILE *arquivo = fopen("desafio01.csv","r");

    if(arquivo == NULL){
        printf("Arquivo não encontrado.\n");
        getch();
        return;
    }

    char linha[MAX_LETRAS];

    while(fgets(linha,sizeof(linha),arquivo) != NULL && qtdLinhas < MAX_LINHAS){

        linha[strcspn(linha,"\n")] = '\0';
        qtdLinhas++;

        // pula cabeçalho
        if(qtdLinhas > 1){

            sscanf(linha,"%49[^;];%d;%f",
                produtos[qtdLinhas - 2].produto,
                &produtos[qtdLinhas - 2].quantidade,
                &produtos[qtdLinhas - 2].preco
            );
        }
    }

    fclose(arquivo);

    printf("=========== RELATÓRIO DE VENDAS ===========\n\n");
    printf("Produto\tQtd\tPreco\tTotal\n");

    for(int i = 0; i < qtdLinhas - 1; i++){
        float total = produtos[i].quantidade * produtos[i].preco;

        printf("%s\t%d\t%.2f\t%.2f\n",
            produtos[i].produto,
            produtos[i].quantidade,
            produtos[i].preco,
            total);
    }

    getch();
}