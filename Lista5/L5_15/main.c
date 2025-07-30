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
void OrdenaCrescente(tCandidato * vet, int qtd);
void ConcatenaString(char * str1, char * str2, char * strOut);
int CandidatoAehMenorQueCandidatoB(tCandidato candA, tCandidato candB);
int MenorEntreAeB(tCandidato * vet, int a, int b);

int main(){
    int qtdCand, i = 0, j;
    scanf("%d", &qtdCand); 
    tCandidato candidatos[qtdCand];

    for(i = 0; i < qtdCand; i++){
        candidatos[i] = LeCandidato();
    }

    OrdenaCrescente(candidatos, qtdCand);
    for(i = 0; i < qtdCand; i++){
        ImprimeCandidato(candidatos[i]);
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

void OrdenaCrescente(tCandidato * vet, int qtd){
    int candidato = 0, indexMenor = 0;
    
    tCandidato aux;

    for (candidato = 0; candidato < qtd-1; candidato++) {
        indexMenor = MenorEntreAeB(vet, candidato+1, qtd);
        if (CandidatoAehMenorQueCandidatoB(vet[indexMenor], vet[candidato])) {
            aux = vet[candidato];
            vet[candidato] = vet[indexMenor];
            vet[indexMenor] = aux;
        }
        
    }
    
}

void ConcatenaString(char * str1, char * str2, char * strOut){
    int i = 0, j = 0;

    while (str1[i]) {
        strOut[i] = str1[i];
        i++;
    }

    while (str2[j]) {
        strOut[i] = str2[j];
        j++;
        i++;
    }

    strOut[i] = '\0';
    
}

int CandidatoAehMenorQueCandidatoB(tCandidato candA, tCandidato candB){
    char nomeCompletoA[42];
    ConcatenaString(candA.nome, candA.sobrenome, nomeCompletoA);

    char nomeCompletoB[42];
    ConcatenaString(candB.nome, candB.sobrenome, nomeCompletoB);
    
    int tamanhoA = 0, tamanhoB = 0;

    while (nomeCompletoA[tamanhoA]) {
        tamanhoA++;
    }

    while (nomeCompletoB[tamanhoB]) {
        tamanhoB++;
    }

    int a = 0, b = 0;
    while (b < tamanhoB && a < tamanhoA) {
        
        if (nomeCompletoA[a] < nomeCompletoB[b]) {
            return 1;
        } else if (nomeCompletoA[a] > nomeCompletoB[b]){
            return 0;
        } else {
            b++;
            a++;
        }
        
    }

    if (a < tamanhoA) {
        return 0;
    } else if (b < tamanhoB) {
        return 1;
    } else {
        return 0;
    }

}

int MenorEntreAeB(tCandidato * vet, int a, int b){
    int indexMenor = a;
    a++;
    while (a < b) {
        if(CandidatoAehMenorQueCandidatoB(vet[a], vet[indexMenor])){
            indexMenor = a;
        }
        a++;
    }

    return indexMenor;
    
}