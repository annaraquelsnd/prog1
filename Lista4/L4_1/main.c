/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: arsandrini
 *
 * Created on July 3, 2025, 9:32 AM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    float preco;
    int qtd_estoque;
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1,tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p);

tProduto LeProduto(){
    tProduto produto;
    /*
    char caractere = 0;
    int codigo = 0, qtd_estoque = 0;
    float preco = 0;
    float casas_dec = 0;
    
    scanf("%c", &caractere);
    while(caractere != ';'){
        if(caractere >= 48 && caractere <= 57){
            codigo = (codigo*10)+(int)(caractere-48);
        }
        scanf("%c", &caractere);
    }
    
    scanf("%c", &caractere);
    while(caractere != ';'){
        if(caractere >= 48 && caractere <= 57){
            preco = (preco*10)+(float)(caractere-48);
            if (casas_dec != 0){
                casas_dec = casas_dec*10;
            }
        } else {
            casas_dec = 1;
        }
        scanf("%c", &caractere);
    }
    preco = preco/casas_dec;
    
    scanf("%d", &qtd_estoque);
    
    produto.codigo = codigo;
    produto.preco = preco; 
    produto.qtd_estoque = qtd_estoque;

    return produto;*/

    scanf("%d;%f;%d", &produto.codigo, &produto.preco, &produto.qtd_estoque);

    return produto;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
    if (p1.preco > p2.preco) {
        return 1;
    } else {
        return 0;
    }
}
int EhProduto1MenorQ2(tProduto p1,tProduto p2){
    if (p1.preco < p2.preco) {
        return 1;
    } else {
        return 0;
    }
}
int TemProdutoEmEstoque(tProduto p){
    int qtd_estoque = p.qtd_estoque;
    
    if (qtd_estoque == 0){
        return 0;
    } else {
        return 1;
    }
}

void ImprimeProduto(tProduto p){
    printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.qtd_estoque);
}

int main(int argc, char** argv) {
    int n = 0, contador = 0;
    tProduto produto1, produto2, maior, menor;
    
    scanf("%d", &n);
    
    produto1 = LeProduto();
    if (!TemProdutoEmEstoque(produto1)){
        printf("FALTA:");
        ImprimeProduto(produto1);
    }
    
    maior = produto1;
    menor = produto1;
    
    for(contador = 1; contador < n; contador++){
        produto2 = produto1;
        produto1 = LeProduto();
        
        if (!TemProdutoEmEstoque(produto1)){
            printf("FALTA:");
            ImprimeProduto(produto1);
        }
        
        if(EhProduto1MaiorQ2(produto1, maior)){
            maior = produto1;
        }
        
        if(EhProduto1MenorQ2(produto1, menor)){
            menor = produto1;
        }
        
    }
    printf("MAIOR:");
    ImprimeProduto(maior);
    printf("MENOR:");
    ImprimeProduto(menor);

    return (EXIT_SUCCESS);
}

