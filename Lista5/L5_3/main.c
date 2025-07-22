#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0, i = 0, maior = 0;
    scanf("%d", &n);

    int alturas[n];
    int diferencas[n-1];

    if(n == 1){
        printf("IMPOSSIVEL");
    } else {
        scanf("%d", &alturas[i]);
        for (i = 1; i < n; i++){
            scanf("%d", &alturas[i]);
            diferencas[i-1] = abs(alturas[i]-alturas[i-1]);
            if (diferencas[i-1] > maior){
                maior = diferencas[i-1];
            }
        }

        for (i = 0; i < n-1; i++) {
            if(diferencas[i] == maior){
                printf(" (%d %d)", i, i+1);
            }
        }
    }

    return 0;
}