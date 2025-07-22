#include <stdio.h>

int main(){
    int n = 0, x = 0, i = 0;
    scanf("%d %d", &x, &n);
    
    int sequencia[n];

    for (i = 0; i < n; i++){
        scanf("%d", &sequencia[i]);
    }

    i = 0;
    while (i < n){
        if (sequencia[i] == x){
            printf("RESP:%d", i);
            break;
        } else {
            i++;
        }
    }

    if (i == n){
        printf("RESP:%d", n);
    }
    
}