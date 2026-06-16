#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct Produto{
    char produto[50];
    int quantidade;
    float preco;
};

void main(){
    SetConsoleOutputCP(CP_UTF8);

    struct Produto produtos[6] = {
        {"Caderno", 10, 5.00},
        {"Caneta", 20, 2.50},
        {"Lápis", 15, 1.00},
        {"Borracha", 5, 0.50},
        {"Régua", 8, 3.00},
        {"Calculadora", 3, 25.00}
    };

    FILE *arquivo = fopen("desafio02.csv","w");

    if(arquivo == NULL){
        printf("Erro ao gravar arquivo\n");
        return;
    }

    // cabeçalho com total
    fprintf(arquivo,"Produto;Quantidade;Preco Unitario;Total de Vendas\n");

    for(int i = 0; i < 6; i++){
        float total = produtos[i].quantidade * produtos[i].preco;

        fprintf(arquivo,"%s;%d;%.2f;%.2f\n",
            produtos[i].produto,
            produtos[i].quantidade,
            produtos[i].preco,
            total);
    }

    fclose(arquivo);

    printf("Arquivo criado com sucesso.");
    getch();
}