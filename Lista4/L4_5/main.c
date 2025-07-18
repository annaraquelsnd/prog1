#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} tPonto;

tPonto InicializarPonto(int x, int y);
tPonto LerPonto();
void ImprimirPonto(tPonto ponto);
tPonto AlterarX(tPonto ponto, int x);
tPonto AlterarY(tPonto ponto, int y);
int GetX(tPonto ponto);
int GetY(tPonto ponto);
tPonto MoverPonto(tPonto ponto, int x, int y);
float ditanciaEntrePontos(tPonto ponto1, tPonto ponto2);
int GetQuadrante(tPonto ponto);
tPonto GetSimetrico(tPonto ponto);

tPonto InicializarPonto(int x, int y){
    tPonto ponto;
    ponto.x = x;
    ponto.y = y;

    return ponto;
}

tPonto LerPonto(){
    int x = 0, y = 0;

    scanf("%d %d", &x, &y);

    return InicializarPonto(x, y);
}

void ImprimirPonto(tPonto ponto){
    printf("(%d,%d)", ponto.x, ponto.y);
}

tPonto AlterarX(tPonto ponto, int x){
    ponto.x = x;

    return ponto;
}
tPonto AlterarY(tPonto ponto, int y){
    ponto.y = y;

    return ponto;
}

int GetX(tPonto ponto){
    return ponto.x;
}

int GetY(tPonto ponto){
    return ponto.y;
}

tPonto MoverPonto(tPonto ponto, int x, int y){
    ponto.x += x;
    ponto.y += y;

    return ponto;
}

float ditanciaEntrePontos(tPonto ponto1, tPonto ponto2){
    float dist = 0;

    dist = sqrt(pow((ponto2.x-ponto1.x),2)+pow((ponto2.y-ponto1.y),2));

    return dist;
}

int GetQuadrante(tPonto ponto){
    if(ponto.x == 0 || ponto.y == 0){
        return 0;
    } else if (ponto.y > 0){
        if (ponto.x > 0){
            return 1;
        } else {
            return 2;
        }
    } else {
        if (ponto.x > 0){
            return 4;
        } else {
            return 3;
        }
    }

}
tPonto GetSimetrico(tPonto ponto){
    return InicializarPonto(-ponto.x, -ponto.y);
}

int main(){
    int n = 0, cont = 0;
    tPonto ponto1, ponto2;

    scanf("%d", &n);

    ponto1 = LerPonto();
    printf("-\n");

    for (cont = 1; cont < n; cont++){
        ponto2 = ponto1;
        ponto1 = LerPonto();
        
        printf("%.2f\n", ditanciaEntrePontos(ponto2, ponto1));

    }

    return 0;
}