#include <stdio.h>

int main(){
    int n = 0, i = 0, anterior = 0, ordem = 0;
    scanf("%d", &n);
    int notas[n];

    for (i = 0; i < n; i++){
        scanf("%d", &notas[i]);
    }

    /*Verificar se é crescente&decrescente (0)*/
    if (n > 1){
        i = 0;
        while (i+1 < n){
            if (notas[i] != notas[i+1]) {
                ordem = 1;
                break;
            } else {
                i++;
            }   
        }
    }

    /*Verificar se é crescente (1)*/
    i = 0;
    while (i+1 < n && ordem){
        if (notas[i] > notas[i+1]) {
            ordem = -1;
            break;
        } else {
            i++;
        }
    }

     /*Verificar se é decrescente (-1)*/
    i = 0;
    while (i+1 < n && ordem == -1){
        if (notas[i] < notas[i+1]) {
            ordem = -2;
            break;
        } else {
            i++;
        }
    }

    if (ordem == 1){
        printf("CRESCENTE");
    } else if(ordem == 0){
        printf("CRESCENTE&DECRESCENTE");
    } else if (ordem == -1){
        printf("DECRESCENTE");
    } else {
        printf("DESORDENADO");
    }

    return 0;
}