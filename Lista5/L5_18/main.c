#include <stdio.h>

int MultiplicaLinhaColuna(int l1, int c1, int matriz1[l1][c1], int l2, int c2, int matriz2[l2][c2], int linha, int coluna);
void ImprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

void ImprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]){
    int i = 0, j =0;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d", matriz[i][j]);
            if (j != colunas-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}   

int MultiplicaLinhaColuna(int l1, int c1, int matriz1[l1][c1], int l2, int c2, int matriz2[l2][c2], int linha, int coluna){
    int i = 0, soma = 0,  multiplicacao = 0;
    while (i < c1) {
        multiplicacao = matriz1[linha][i] * matriz2[i][coluna];
        soma += multiplicacao;
        i++;
    }
    return soma;
    
}

int main(){
    int n = 0, cont = 0;
    scanf("%d", &n);

    int i = 0, j = 0;

    for (cont = 0; cont < n; cont++) {
        int c1 = 0, l1 = 0, c2 = 0, l2 = 0;
        scanf("%d %d", &c1, &l1);
        int matriz1[l1][c1];

        for (i = 0; i < l1; i++) {
            for (j = 0; j < c1; j++) {
                scanf("%d", &matriz1[i][j]);
            }
        }

        scanf("%d %d", &c2, &l2);
        int matriz2[l2][c2];
        
        for (i = 0; i < l2; i++) {
            for (j = 0; j < c2; j++) {
                scanf("%d", &matriz2[i][j]);
            }
        }

        if (c1 == l2){
            int matrizResultante[l1][c2];
            for (i = 0; i < l1; i++) {
                for (j = 0; j < c2; j++) {
                    matrizResultante[i][j] = MultiplicaLinhaColuna(l1, c1, matriz1, l2, c2, matriz2, i, j);
                }
            }

            ImprimirMatriz(l1, c2, matrizResultante);

        } else {
            printf("IMPOSSIVEL\n\n");
        }
        

    }
    
    return 0;
}