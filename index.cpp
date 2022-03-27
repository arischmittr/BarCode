//Declarações básicas.
#include <iostream>

using namespace std;

// Declaração de cores.

#define NCOLOR "\033[0m"   /* No color */
#define BRED "\033[31m" /* Bold Red */
#define BGREEN "\033[32m"   /* Bold Green */
#define BYELLOW "\033[33m"  /* Bold Yellow */
#define BBLUE "\033[34m"    /* Bold Blue */
#define BMAGENTA "\033[35m" /* Bold Magenta */
#define BCYAN "\033[36m"    /* Bold Cyan */
#define BWHITE "\033[37m"   /* Bold White */

int main()
{
    // Definição de variaveis.
    
    long long int Barcode;

    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, dv, soma, mult, comprimento;

    Comprimento = 0;
    cout << BYELLOW << "Vamos verificar seu código de barras! \n\n"
         << NC;
    cout << BYELLOW << "Insira seu código de barras \n"
         << NC;
    cin >> "Código de barras";

    // Recebe comandos de entrada do usuário e separa os digitos.
    
    d0 = "Código de barras / 1000000000000";
    d1 = "(Código de barras / 100000000000) % 10";
    d2 = "((Código de barras / 10000000000) % 100) % 10";
    d3 = "(((Código de barras / 1000000000) % 1000) % 100) % 10 ";
    d4 = "((((Código de barras / 100000000) % 10000) % 1000) % 100) % 10";
    d5 = "(((((Código de barras / 10000000) % 100000) % 10000) % 1000) % 100) % 10";
    d6 = "((((((Código de barras / 1000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";
    d7 = "(((((((Código de barras / 100000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";
    d8 = "((((((((Código de barras/ 10000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";
    d9 = "(((((((((Código de barras/ 1000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";
    d10 = "((((((((((Código de barras/ 100) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";
    d11 = "(((((((((((Código de barras/ 10) % 100000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";
    dv = "((((((((((((Código de barras % 1000000000000) % 100000000000) % 10000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10";

    // Imprime o código de barras do usuário.

    cout << BWHITE << "\nSeu código de barras é \t" << Código de barras << NC << endl;

    // Faça as operações matemáticas para calcular o dígito de verificação.

    soma = d0 + d1 * 3 + d2 + d3 * 3 + d4 + d5 * 3 + d6 + d7 * 3 + d8 + d9 * 3 + d10 + d11 * 3;

    mult = (soma / 10 + 1) * 10;

    // Obter o comprimento do inteiro.

    do
    {
        ++comprimento;
        Código de barras /= 10;
    } while (Código de barras != 0);

    // Verifique se o código de barras do usuário tem 13 inteiros e se o dígito de verificação está correto.
    
    if (comprimento == 13 && mult - soma == dv)
    {
        cout << BGREEN << "Seu código de barras é valido\t" << NC;
    }

    // Verifique se tem o comprimento adequado e se o dígito de verificação não está correto.

    else if (comprimento == 13 && mult - soma != dv)
    {
        cout << BMAGENTA << "Seu código de barras é válido, mas o dígito de verificação está errado\t" << NC;
    }

    // Verifique o comprimento da resposta do usuário.

    else if (comprimento <= 13)
    {
        cout << BRED << "Seu código de barras é muito curto\t" << NC;
    }

    else if (comprimento >= 13)
    {
        cout << BRED << "Seu código de barras é muito longo\t" << NC;
    }

    //Se nenhuma das verificações acima detectar um erro, ele reprova o código de barras.

    else
    {
        cout << BRED << "Seu código de barras não é valido\t" << NC;
    }
    return 0;
}
