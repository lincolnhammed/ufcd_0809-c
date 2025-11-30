#define _USE_MATH_DEFINES // deve ser incluído antes de <math.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float verificaTriangulo(float a, float b, float c);
float semiPerimetro(float a, float b, float c);

float perimetro(float a, float b, float c)
{

    if (1 == verificaTriangulo(a, b, c))
    {
        float p = a + b + c;
        return p;
    }
    else
    {
        return 0;
    }
}
float areaTriangulo(float a, float b, float c)
{
    if (semiPerimetro(a, b, c) != 0)
    {

        float s = semiPerimetro(a, b, c);
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }
    else
        return 0;
}
float semiPerimetro(float a, float b, float c)
{
    if (1 == verificaTriangulo(a, b, c))
    {
        float sPerimetro = (a + b + c) / 2;
        return sPerimetro;
    }
    else
    {
        return 0;
    }
}
float verificaTriangulo(float a, float b, float c)
{
    if (a < b + c && b < a + c && c < a + b)
    {
        return 1; // é triângulo
    }
    else
    {
        return 0; // não é triângulo
    }
}
float calcularTriangulo(float a, float b, float c)
{
    if (1 == verificaTriangulo(a, b, c))
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
void menuPerimetro()
{
    int num = 0;
    float a, b, c;
    printf(" Escolha uma opção:\n");
    printf("(1)Triangulo \n");
    printf("(2)semiTriangulo \n");
    printf("(3)area \n");
    printf("(4)perimetro \n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
    {
        printf("Digite os tres lados: ");
        scanf("%f %f %f", &a, &b, &c);
        int triangulo = calcularTriangulo(a, b, c);

        if (triangulo == 1)
        {
            printf("Triangulo\n");
        }
        else
            printf("Nao é triangulo\n");
        break;
    }
    case 2:
    {
        printf("Digite os tres lados: ");
        scanf("%f %f %f", &a, &b, &c);
        float sp = semiPerimetro(a, b, c);
        if (sp != 0)
        {
            printf("O semiPerimetro Triangulo é: %f \n", sp);
        }
        else
            printf("Nao é triangulo\n");
        break;
    }
    case 3:
    {
        printf("Digite os tres lados: ");
        scanf("%f %f %f", &a, &b, &c);
        float at = areaTriangulo(a, b, c);
        if (at != 0)
        {
            printf("A area do Triangulo é: %f \n", at);
        }
        else
            printf("Nao é triangulo\n");
        break;
    }
    case 4:
    {
        printf("Digite os tres lados: ");
        scanf("%f %f %f", &a, &b, &c);
        float p = perimetro(a, b, c);
        if (p != 0)
        {
            printf("o perimetro do Triangulo é: %f \n", p);
        }
        else
            printf("Nao é triangulo\n");
        break;
    }
    break;
    default:
        printf("Opção invalida");
        break;
    }
}
float areaCirculo(float r)
{

    double area = M_PI * r * r;
    return area;
}
float perimetroCirculo(float raio)
{
    float p = 2 * M_PI * raio;
    return p;
}
void menuCirculo()
{
    int opcao;
    float r = 0;
    printf("=== CÍRCULO ===\n");
    printf("(1) Área\n");
    printf("(2) Perímetro (circunferência)\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("Digite o raio: ");
    scanf("%f", &r);
    if (opcao == 1 && r > 0)
    {
        r = areaCirculo(r);
        printf("Área do círculo: %.2f\n", r);
    }
    else if (opcao == 2 && r > 0)
    {

        r = perimetroCirculo(r);
        printf("Perímetro do círculo: %.2f\n", r);
    }
    else
    {
        printf("Numero inválido.\n");
    }
}
float perimetroQuadrilatero(float base, float altura)
{
    float perimetro = 2 * (base + altura);
    return perimetro;
}
float areaQuadrilatero(float base, float altura)
{
    float area = base * altura;
    return area;
}
void menuQuadrilatero()
{
    float base, altura;
    int opcao;

    printf("=== QUADRILÁTERO (RETÂNGULO) ===\n");
    printf("(1) Área\n");
    printf("(2) Perímetro\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("Digite a base: ");
    scanf("%f", &base);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    if (base <= 0 || altura <= 0)
    {
        printf("Valores inválidos.\n");
        return;
    }

    if (opcao == 1)
    {
        printf("Área do retângulo: %.2f\n", areaQuadrilatero(base, altura));
    }
    else if (opcao == 2)
    {
        printf("Perímetro do retângulo: %.2f\n", perimetroQuadrilatero(base, altura));
    }
    else
    {
        printf("Opção inválida.\n");
    }
}
int main()
{
    char op;
    char maiuscula;

    do
    {
        printf("=== CÁLCULO DE ÁREAS E PERÍMETROS ===\n");
        printf("(T)Triângulo\n");
        printf("(C)Círculo\n");
        printf("(Q)Quadrilátero\n");
        printf("(S)Sair\n");
        printf(" Escolha uma opção:\n");
        scanf(" %c", &maiuscula);
        op = toupper(maiuscula);
        switch (op)
        {
        case 'T':
        {
            menuPerimetro();
            break;
        }
        case 'C':
        {
            menuCirculo();
            break;
        }
        case 'Q':
            menuQuadrilatero();
            break;
        case 'S':

            break;

        default:
            printf("Opção invalida,aqui");
            break;
        }

    } while (op != 'S');

    return 0;
}
