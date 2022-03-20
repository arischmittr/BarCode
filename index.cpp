// Basic declarations.

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// Color declarations
#define BarcodeTS BarcodeT.str() /* Define Varible */

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

    string Barcode;
    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, dv, soma, mult;
    stringstream BarcodeT;

    // Introduction to the project and wait for User input

    cout << BYELLOW << "Let's verify your Barcode! \n\n"
         << NC;
    cout << BYELLOW << "Insert your Barcode \n"
         << NC;
    cin >> Barcode;

    // Takes Characters from user input and tranfrom to integer

    d0 = Barcode[0] - '0';
    d1 = Barcode[1] - '0';
    d2 = Barcode[2] - '0';
    d3 = Barcode[3] - '0';
    d4 = Barcode[4] - '0';
    d5 = Barcode[5] - '0';
    d6 = Barcode[6] - '0';
    d7 = Barcode[7] - '0';
    d8 = Barcode[8] - '0';
    d9 = Barcode[9] - '0';
    d10 = Barcode[10] - '0';
    d11 = Barcode[11] - '0';
    dv = Barcode[12] - '0';

    // Insert the integers into a Special type String

    BarcodeT << d0 << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << d9 << d10 << d11 << dv;

    // Print user Barcode

    cout << BWHITE << "\nYour Barcode is \t" << BarcodeTS << NC << endl;

    // Make the mathematical operations to calculate the verification digit

    soma = d0 + d1 * 3 + d2 + d3 * 3 + d4 + d5 * 3 + d6 + d7 * 3 + d8 + d9 * 3 + d10 + d11 * 3;

    mult = (soma / 10 + 1) * 10;

    // Check if USer Barcode has 13 Integers and if the verification digit is correct

    if (BarcodeTS.length() == 13 && mult - soma == dv)
    {
        cout << BGREEN << "Your Barcode is Valid\t" << NC;
    }
    else if (BarcodeTS.length() == 13 && mult - soma != dv)
    {
        cout << BMAGENTA << "Your Barcode is Valid, but the Verify Digit is Wrong\t" << NC;
    }
    else
    {
        cout << BRED << "Your Barcode is not Valid\t" << NC;
    }
}
