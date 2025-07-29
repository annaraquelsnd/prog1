#include <stdio.h>
#include <stdlib.h>

int ComparaString(char * str1, char * str2);

int ComparaString(char * str1, char * str2){
    int i = 0;
    int tamanho1 = 0, tamanho2 = 0;

    while (str1[tamanho1]) {
        tamanho1++;
    }

    while (str2[tamanho2]) {
        tamanho2++;
    }

    if (tamanho1 != tamanho2) {
        return 0;
    }

    while (str1[i] && str2[i]) {
        if (str1[i] == str2[i]) {
            i++;
        } else {
            return 0;
        }
    }
    return 1;
}

int main(){
    char str1[1000];
    char str2[1000];

    while ( scanf("%s", str1) == 1 && scanf("%s", str2) == 1){
        if (ComparaString(str1, str2)){
            printf("IGUAL\n"); 
        } else {
            printf("DIFERENTE\n");
        }
    }
    return 0;
}