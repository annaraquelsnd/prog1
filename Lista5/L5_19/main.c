#include <stdio.h>

void ImprimirMatriz(int linhas, int colunas, char matriz[linhas][colunas]){
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%c ", matriz[i][j]);
        }

        printf("\n");
        
    }
    printf("\n");
}

int main(){
    int horas = 0, tempo = 0, w = 0, h = 0, i = 0, j = 0, terra_inicio = 0, terra_final = 0;
    scanf("%d", &horas);
    scanf("%d %d", &w, &h);

    char foto[h][w];

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            scanf(" %c", &foto[i][j]);
            if (foto[i][j] == '0') {
                terra_inicio++;
            }
        }
    }

    for (tempo = 0; tempo < horas; tempo++){
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (foto[i][j] == (char) tempo+'1') {
                    if (foto[i+1][j] == '0' && i+1 < h){
                        foto[i+1][j] = (char) tempo+'2';
                    }

                    if (foto[i-1][j] == '0' && i-1 >= 0){
                        foto[i-1][j] = (char) tempo+'2';
                    }

                    if (foto[i][j+1] == '0' && j+1 < w){
                        foto[i][j+1] = (char) tempo+'2';
                    }

                    if (foto[i][j-1] == '0'&& j-1 >= 0){
                        foto[i][j-1] = (char) tempo+'2';
                    }
                }   
            }
        }
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (foto[i][j] == '0') {
                terra_final++;
            }
        }
    }

    printf("%d %d\n", terra_inicio, terra_final);
    
}