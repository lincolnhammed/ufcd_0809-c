#include <stdio.h>

float celciusParaFahrenheit(float c){
return (c*1.8)+32;
}
int main() {
    printf("Qual a temperatura a trasformar em Fahrenheit");
    float num;
    scanf(" %f",&num);
    float novaTemperatura=celciusParaFahrenheit(num);
    printf("A temperatura em Fahrenheit é: %2.f",novaTemperatura);

    return 0;
}