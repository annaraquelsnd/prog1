#include <stdio.h>

int main(){
    int n = 0, i = 0;

    scanf("%d", &n);
    int sequencia[n];

    for (i = 0; i < n; i++){
        scanf("%d", &sequencia[i]);
    }

    if (n == 1){
        printf("NAO");
    } else if (n == 2){
        printf("RESP:%d", sequencia[1] - sequencia[0]);
    } else{
        i = n-1;
        while(i >= 2){
            if(sequencia[i]-sequencia[i-1] == sequencia[i-1]-sequencia[i-2]){
                i--;
            } else {
                printf("NAO");
                break;
            }
        }

        if (i == 1){
            printf("RESP:%d", sequencia[1]-sequencia[0]);
        }
        
    }

    return 0;
}