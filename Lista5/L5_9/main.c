#include <stdio.h>

void InverteVetor(int * vet, int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

void InverteVetor(int * vet, int qtd){
    int i = 0, aux = 0;
    for (i = 0; i < qtd/2; i++){
        aux = vet[i];
        vet[i] = vet[qtd-1-i];
        vet[qtd-1-i] = aux;
    }
    
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i = 0;
    if(qtd == 0){
        printf("{}");
    } else {
        printf("{");
        for (i = 0; i < qtd-1; i++){
            printf("%d, ", vet[i]);
        }
        printf("%d}", vet[qtd-1]);
    }
}

int main(){
    int n = 0, i = 0;

    scanf("%d", &n);
    int sequencia[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &sequencia[i]);
    }
    
    InverteVetor(sequencia, n);
    ImprimeDadosDoVetor(sequencia, n);

    return 0;
}