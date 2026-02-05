#include <stdio.h>
#include <locale.h>
#define MAX 5

/* 

 */

float mostra_qt_pares_e_mostra(float *notas,int qt){
        float soma=0;
        for (size_t i = 0; i < qt; i++){
        
        soma+=notas[i];
        printf("%d° nota: %.2f\n", i+1, notas[i]);

        }
    return soma;
}

int main() {

    float notas[MAX];
    setlocale(LC_ALL,"Portuguese");
    for (size_t i = 0; i < 2; i++)
    {
        printf ("insire %d valor:",i+1);
        scanf("%f", &notas[i]);
    }
    
    float res = mostra_qt_pares_e_mostra(notas,MAX);
    printf("%.2f", res);
    return 0;
}

