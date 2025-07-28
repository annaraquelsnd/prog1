#include <stdio.h>

int AcharMenorEntreAeB(int vet[], int a, int b);
void OrdenaCrescente(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int AcharMenorEntreAeB(int vet[], int a, int b){
    int menor = vet[a], i, indexMenor = a;
    for (i = a + 1; i < b; i++) {
        if (vet[i] < menor){
            menor = vet[i];
            indexMenor = i;
        }
    }
    return indexMenor;
}

void OrdenaCrescente(int vet[], int qtd){
    int i = 0, aux = 0, indexMenor = 0;
    for (i = 0; i < qtd; i++) {
        indexMenor = AcharMenorEntreAeB(vet, i, qtd);
        if (vet[indexMenor] < vet[i]) {
            aux = vet[i];
            vet[i] = vet[indexMenor];
            vet[indexMenor] = aux;
        }
        
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
    
    OrdenaCrescente(sequencia, n);
    ImprimeDadosDoVetor(sequencia, n);

    return 0;
}