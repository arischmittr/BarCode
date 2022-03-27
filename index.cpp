//Declarações básicas.
#include <iostream>

using namespace std;

// Declaração de cores.

#define NC "\033[0m"   /* No color */
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

    comprimento = 0;

    cout << BYELLOW << "Vamos verificar seu Barcode! \n\n"
         << NC;
    cout << BYELLOW << "Insira seu Barcode\n"
         << NC;
    cin >> Barcode;

    // Recebe comandos de entrada do usuário e separa os digitos.

    d0 = Barcode/ 1000000000000 ;
    d1 = (Barcode / 100000000000) % 10 ;
    d2 = ((Barcode / 10000000000) % 100) % 10;
    d3 = (((Barcode / 1000000000) % 1000) % 100) % 10;
    d4 =((((Barcode / 100000000) % 10000) % 1000) % 100) % 10;
    d5 = (((((Barcode/ 10000000) % 100000) % 10000) % 1000) % 100) % 10;
    d6 = ((((((Barcode / 1000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d7 = (((((((Barcode/ 100000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d8 = ((((((((Barcode/ 10000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d9 =(((((((((Barcode/ 1000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d10 = ((((((((((Barcode/ 100) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d11 = (((((((((((Barcode/ 10) % 100000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    dv = ((((((((((((Barcode/ 1000000000000% 1000000000000) % 100000000000) % 10000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;

    // Imprime o código de barras do usuário.

    cout << BWHITE << "\nSeu Barcode é \t" << Barcode << NC << endl;

    // Faça as operações matemáticas para calcular o dígito de verificação.

    soma = d0 + d1 * 3 + d2 + d3 * 3 + d4 + d5 * 3 + d6 + d7 * 3 + d8 + d9 * 3 + d10 + d11 * 3;

    mult = (soma / 10 + 1) * 10;

    // Obter o comprimento do inteiro.

    do
    {
        ++comprimento;
        Barcode /= 10;
    } while (Barcode!= 0);

    // Verifique se o código de barras do usuário tem 13 inteiros e se o dígito de verificação está correto.

    if (comprimento == 13 && mult - soma == dv)
    {
        cout << BGREEN << "Seu Barcode é valido\t" << NC;
    }

    // Verifique se tem o comprimento adequado e se o dígito de verificação não está correto.

    else if (comprimento == 13 && mult - soma != dv)
    {
        cout << BMAGENTA << "Seu Barcode é válido, mas o dígito de verificação está errado\t" << NC;
    }

    // Verifique o comprimento da resposta do usuário.

    else if (comprimento <= 13)
    {
        cout << BRED << "Seu Barcode é muito curto\t" << NC;
    }

    else if (comprimento >= 13)
    {
        cout << BRED << "Seu Barcode muito longo\t" << NC;
    }

    //Se nenhuma das verificações acima detectar um erro, ele reprova o código de barras.

    else
    {
        cout << BRED << "Seu Barcode não é valido\t" << NC;
    }
    return 0;
