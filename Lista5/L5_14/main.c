#include <stdio.h> 
#include <stdlib.h>

typedef struct{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);

int ComparaString(char * str1, char * str2);

int main(){
    int qtdCand, i = 0, j = 0;

    scanf("%d", &qtdCand); 

    tCandidato candidatos[qtdCand];
    int impresso[qtdCand];
    
    for(i = 0; i < qtdCand; i++){
        candidatos[i] = LeCandidato();
        impresso[i] = 0;
    }

    for (i = 0; i < qtdCand; i++) {
        for (j = i+1; j < qtdCand; j++) {
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)){
                if (!impresso[i]) {
                    ImprimeCandidato(candidatos[i]);
                    impresso[i] = 1;
                }
                if (!impresso[j]) {
                    ImprimeCandidato(candidatos[j]);
                    impresso[j] = 1;
                }
                
            }
        }
    }

    return 0; 
}

tCandidato LeCandidato(){
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

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

