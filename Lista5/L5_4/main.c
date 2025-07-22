#include <stdio.h>

int main(){
    int n = 0, i = 0, a = 0, b = 0, dentro = 0, fora = 0;
    scanf("%d", &n);
    int sequencia[n];

    for (i = 0; i < n; i++){
        scanf("%d", &sequencia[i]);
    }

    scanf("%d %d", &a, &b);
    
    for (i = 0; i < n; i++){
        if(sequencia[i] >= a && sequencia[i] <= b){
            dentro += 1;
        } else {
            fora += 1;
        }
    }

    printf("%d %d", dentro, fora);

    return 0;
}