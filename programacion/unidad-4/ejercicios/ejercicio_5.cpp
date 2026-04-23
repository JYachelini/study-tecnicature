/*
Dado un triángulo representado por sus lados L1, L2, L3. Informar si el triángulo es rectángulo o
no. Recuerde que en todo triángulo rectángulo el cuadrado de la hipotenusa es igual a la suma de
los cuadrados de los catetos
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Ingrese a: ";
    cin >> a;

    cout << "Ingrese b: ";
    cin >> b;

    cout << "Ingrese c: ";
    cin >> c;

    int max = a, cateto1 = b, cateto2 = c;

    if (max < b)
    {
        max = b;
        cateto1 = a;
        cateto2 = c;
    }
    if (max < c)
    {
        max = c;
        cateto1 = a;
        cateto2 = b;
    }
    if (max * max == (a * a + b * b + c * c - max * max))
        cout << "Es rectangulo";
    else
        cout << "No es rectangulo";
    /*
    int hipotenusa = max * max;
    int rectangulo = hipotenusa == (cateto1 * cateto1 + cateto2 * cateto2);

    if (rectangulo) cout << "Es rectangulo";
    else cout << "No es rectangulo";
    */

    return 0;
}