#include <stdio.h>

int main(){
    char texto[500][500];
    int i = 0;

    while (scanf("%*[^A-Za-z]") != EOF) {
        scanf("%[A-Za-z]", texto[i]);
        i++;
    }
    
    i--;
    while (i >= 0) {
        printf("%s ", texto[i]);
        i--;
    }
    
}