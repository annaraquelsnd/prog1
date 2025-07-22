#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0, i = 0, itemA = 0, itemB = 0, estaContido = 0, parcial = 0;

    /* Receber entrada */
    scanf("%d", &n1);
    int vetorA[n1];
    for (i = 0; i < n1; i++){
        scanf("%d", &vetorA[i]);
    }

    scanf("%d", &n2);
    int vetorB[n2];
    for (i = 0; i < n2; i++){
        scanf("%d", &vetorB[i]);
    }

    /* Verificar se A está contido em B */
    while(itemB < n2){
        itemA = 0;
        while (itemA < n1){
            if (vetorA[itemA] == vetorB[itemB]){
                itemA++;
                itemB++;

                if (itemB == n2){
                    break;
                }

            } else {
                itemB++;
                break;
            }
        }
            
        if (itemA == n1){
            break;
        }
            
    }

    if (itemA == n1) {
        estaContido = 1;
    }


    if (estaContido) {
        printf("TODOS");
    } else {
        /* Se não está contido, verificar se está parcialmente contido */
        itemA = 0;
        itemB = 0;

        while (itemA < n1) {
            while (itemB < n2) {
                if(vetorA[itemA] == vetorB[itemB]){
                    printf("PARCIAL");
                    parcial = 1;
                    break;
                } else {
                    itemB++;
                }
                
            }

            if (parcial == 1){
                break;
            }

            itemA++;
            itemB = 0;
            
        }

        /* Se não está contido nem parcialmente contido: */
        if (parcial == 0){
            printf("NENHUM");
        }
        
        
    }
    

}