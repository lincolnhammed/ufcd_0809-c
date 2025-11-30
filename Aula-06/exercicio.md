#define _USE_MATH_DEFINES // deve ser incluído antes de <math.h>
#include <math.h>
#include <stdio.h>
/*
Desenvolver um programa modular em C que utilize funções para calcular
áreas e perímetros de diferentes figuras geométricas: triângulo, círculo e
quadrilátero.
O programa deve apresentar um menu de opções e executar os cálculos
conforme a escolha do utilizador.
O programa deve exibir um menu com as seguintes opções:
 
=== CÁLCULO DE ÁREAS E PERÍMETROS ===
(T)riângulo
(C)írculo
(Q)uadrilátero
(S)Sair
Escolha uma opção:
 
O programa deve validar se as medidas inseridas podem formar um triângulo.
Para isso, use a condição de existência do triângulo:
a + b > c
b + c > a
a + c > b
 
Se a condição não for satisfeita, o programa deve mostrar uma mensagem de
erro: "As medidas inseridas não formam um triângulo válido."

Área: s = (a + b + c) / 2;
     area = sqrt(s * (s - a) * (s - b) * (s - c));
Perímetro: P = A + B + C
 
No caso do círculo, o utilizador deve introduzir o raio. O pi será uma
constante.
Área: A = π * r²
Perímetro (circunferência): P = 2 * π * r
 
No caso do quadrilátero, considere um retângulo.
Área: A = base * altura
Perímetro: P = 2 * (base + altura)
 
Os resultados devem ser apresentados com duas casas decimais.
 
Deve perguntar ao utilizar se quer identificar o tipo de triângulo depois
de conhecer as medidas: Equilátero(todos iguais), Isósceles (2 lados = e 1
diferente), Escaleno (todos diferentes)
*/
 
int main()
{
   printf("%f", M_PI);
  return 0;
}
Funções:
Cálculos de áreas e perímetros
Menu
Classificação de triângulo
Validação de triângulo