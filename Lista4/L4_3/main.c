#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

void ImprimirData(tData data);
tData CorrigirData(tData data);
tData LerData();
int EhBisexto(tData data);

tData CorrigirData(tData data){
    if (data.mes > 12){
        data.mes = 12;
    } else if (data.mes < 1){
        data.mes = 1;
    }

    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 ||data.mes == 10 || data.mes == 12){
        if (data.dia > 31){
            data.dia = 31;
        }
    } else if (data.mes == 2){
        if (data.ano%4 == 0){
            if (data.dia > 29){
                data.dia = 29;
            }
        } else {
            if (data.dia > 28){
                data.dia = 28;
            }
        }
    } else {
        if (data.dia > 30){
            data.dia = 30;
        }
    }

    return data;
}

tData LerData(){
    tData data;
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

    data = CorrigirData(data);

    return data;
}

void ImprimirData(tData data){
    printf("'%02d/%02d/%d'", data.dia, data.mes, data.ano);
}

int EhBisexto(tData data){
    if (data.ano%4 == 0){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n = 0, contador = 0;
    tData data;

    scanf("%d", &n);

    for (contador = 0; contador < n; contador++){
        data = LerData();
        ImprimirData(data);

        if(EhBisexto(data)){
            printf(":Bisexto\n");
        } else {
            printf(":Normal\n");
        }

    }
    

    return 0;
}