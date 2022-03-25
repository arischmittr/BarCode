// Basic declarations.
#include <iostream>

using namespace std;

// Color declarations
#define NC "\033[0m"        /* No Color */
#define BRED "\033[31m"     /* Bold Red */
#define BGREEN "\033[32m"   /* Bold Green */
#define BYELLOW "\033[33m"  /* Bold Yellow */
#define BBLUE "\033[34m"    /* Bold Blue */
#define BMAGENTA "\033[35m" /* Bold Magenta */
#define BCYAN "\033[36m"    /* Bold Cyan */
#define BWHITE "\033[37m"   /* Bold White */

int main()
{
    // Define Varibles
    long long int Barcode;

    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, dv, soma, mult, length;

    length = 0;
    cout << BYELLOW << "Let's verify your Barcode! \n\n"
         << NC;
    cout << BYELLOW << "Insert your Barcode \n"
         << NC;
    cin >> Barcode;

    // Takes user input and separete digits
    d0 = Barcode / 1000000000000;
    d1 = (Barcode / 100000000000) % 10;
    d2 = ((Barcode / 10000000000) % 100) % 10;
    d3 = (((Barcode / 1000000000) % 1000) % 100) % 10;
    d4 = ((((Barcode / 100000000) % 10000) % 1000) % 100) % 10;
    d5 = (((((Barcode / 10000000) % 100000) % 10000) % 1000) % 100) % 10;
    d6 = ((((((Barcode / 1000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d7 = (((((((Barcode / 100000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d8 = ((((((((Barcode / 10000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d9 = (((((((((Barcode / 1000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d10 = ((((((((((Barcode / 100) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    d11 = (((((((((((Barcode / 10) % 100000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;
    dv = ((((((((((((Barcode % 1000000000000) % 100000000000) % 10000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000) % 100) % 10;

    // Print out User Barcode

    cout << BWHITE << "\nYour Barcode is \t" << Barcode << NC << endl;

    // Make the mathematical operations to calculate the verification digit

    soma = d0 + d1 * 3 + d2 + d3 * 3 + d4 + d5 * 3 + d6 + d7 * 3 + d8 + d9 * 3 + d10 + d11 * 3;

    mult = (soma / 10 + 1) * 10;

    // get lebght of integer

    do
    {
        ++length;
        Barcode /= 10;
    } while (Barcode != 0);

    // Check if User Barcode has 13 Integers and if the verification digit is correct
    if (length == 13 && mult - soma == dv)
    {
        cout << BGREEN << "Your Barcode is Valid\t" << NC;
    }

    // Check if it has the proprer lenght and if the verification digit is not correct

    else if (length == 13 && mult - soma != dv)
    {
        cout << BMAGENTA << "Your Barcode is Valid, but the Verify Digit is Wrong\t" << NC;
    }
    else if (length <= 13)
    {
        cout << BRED << "Your Barcode is to short\t" << NC;
    }

    else if (length >= 13)
    {
        cout << BRED << "Your Barcode is to long\t" << NC;
    }

    // if none of the above checks catch a mistake it reproves the barcode

    else
    {
        cout << BRED << "Your Barcode is not Valid\t" << NC;
    }
    return 0;
}