#include <stdio.h>
#include <math.h>

int main(){
    int n = 0, i = 0;
    int menor = 0, maior = 0, acima_media = 0, reprovados = 0;
    float media = 0, std = 0;
    scanf("%d", &n);
    int notas[n];

    for (i = 0; i < n; i++){
        scanf("%d", &notas[i]);
    }

    menor = notas[0];
    maior = notas[0];
    for (i = 0; i < n; i++){
        if(notas[i] < menor){
            menor = notas[i];
        }

        if(notas[i] > maior){
            maior = notas[i];
        }
        
        media += notas[i];

        if(notas[i] < 70){
            reprovados += 1;
        }

    }

    media = media/(float) n;

    for (i = 0; i < n; i++){
        if(notas[i] > media){
            acima_media += 1;
        }

        std += pow((notas[i]-media) ,2);

    }

    std = sqrt(std/n);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", menor, maior, media, std, acima_media, reprovados);

    return 0;
}