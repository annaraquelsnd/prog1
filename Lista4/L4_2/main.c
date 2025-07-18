#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

void ImprimirData(tData data);
tData CorrigirData(tData data);
tData LerData();
int DatasIguais(tData d1, tData d2);

int DatasIguais(tData d1, tData d2) {
    return d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano;
}

tData LerData(){
    tData data;
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

    data = CorrigirData(data);

    return data;
}

void ImprimirData(tData data){
    printf("'%02d/%02d/%d'\n", data.dia, data.mes, data.ano);
}

tData CorrigirData(tData data){
    if (data.mes > 12){
        data.mes = 12;
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

int main(){
    tData dataInicio, dataFim;
    dataInicio = LerData();
    dataFim = LerData(); 

    while (!(DatasIguais(dataInicio, dataFim))){
        ImprimirData(dataInicio);

        if (dataInicio.mes == 1 || dataInicio.mes == 3 || dataInicio.mes == 5 || dataInicio.mes == 7 || dataInicio.mes == 8 ||dataInicio.mes == 10 || dataInicio.mes == 12){
            if (dataInicio.dia == 31){
                if (dataInicio.mes == 12){
                    dataInicio.ano += 1;
                    dataInicio.mes = 1;
                } else {
                    dataInicio.mes += 1;
                }
                dataInicio.dia = 1;
                
            } else {
                dataInicio.dia += 1;
            }
        } else if (dataInicio.mes == 2){
            if (dataInicio.ano%4 == 0){
                if (dataInicio.dia == 29){
                    if (dataInicio.mes == 12){
                        dataInicio.ano += 1;
                        dataInicio.mes = 1;
                    } else {
                        dataInicio.mes += 1;
                    }
                    dataInicio.dia = 1;
                } else {
                    dataInicio.dia += 1;
                }
            } else {
                if (dataInicio.dia == 28){
                    if (dataInicio.mes == 12){
                        dataInicio.ano += 1;
                        dataInicio.mes = 1;
                    } else {
                        dataInicio.mes += 1;
                    }
                    dataInicio.dia = 1;
                } else {
                    dataInicio.dia += 1;
                }
            }
        } else {
            if (dataInicio.dia == 30){
                if (dataInicio.mes == 12){
                    dataInicio.ano += 1;
                    dataInicio.mes = 1;
                } else {
                    dataInicio.mes += 1;
                }
                dataInicio.dia = 1;
                
            } else {
                dataInicio.dia += 1;
            }
        }
    }
    
    return 0;
}