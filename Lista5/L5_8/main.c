#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

void TrocaParEImpar(int vet[], int qtd){
    int i = 0, aux = 0;
    for (i = 0; i+1 < qtd; i += 2){
        aux = vet[i+1];
        vet[i+1] = vet[i];
        vet[i] = aux;
    }
    
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i = 0;
    if (qtd == 0){
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

    TrocaParEImpar(sequencia, n);
    ImprimeDadosDoVetor(sequencia, n);
    
    return 0;
}