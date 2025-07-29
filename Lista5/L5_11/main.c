#include <stdio.h>

void OrdenaCrescente(int vet[], int qtd);
int AcharMenorEntreAeB(int vet[], int a, int b);

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

int main(){
    int n1 = 0, n2 = 0, i = 0;

    scanf("%d", &n1);
    int sequenciaA[n1];

    for (i = 0; i < n1; i++) {
        scanf("%d", &sequenciaA[i]);
    }
    
    scanf("%d", &n2);
    int sequenciaB[n2];

    for (i = 0; i < n2; i++) {
        scanf("%d", &sequenciaB[i]);
    }

    OrdenaCrescente(sequenciaA, n1);
    OrdenaCrescente(sequenciaB, n2);

    int a = 0, b = 0;
    while (b < n2 && a < n1) {
        
        if (sequenciaA[a] < sequenciaB[b]) {
            printf("A");
            a++;
        } else if (sequenciaA[a] > sequenciaB[b]){
            printf("B");
            b++;
        } else {
            printf("A");
            a++;
        }
        
    }

    if (a < n1) {
        while (a < n1) {
            printf("A");
            a++;
        }
    } else if (b < n2) {
        while (b < n2) {
            printf("B");
            b++;
        }
    }

    return 0;
}