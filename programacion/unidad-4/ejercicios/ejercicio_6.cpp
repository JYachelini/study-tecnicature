/*
Dado un año informar si es bisiesto o no. Tener en cuenta que un año es bisiesto si cumple los
siguientes criterios:
∙ Es divisible entre 4.
∙ Si termina en 00, es divisible entre 400 (2000 y 2400 sí son bisiestos. 2100, 2200 y 2300 no
lo son).
*/

#include <iostream>

using namespace std;

int main()
{
    int año;
    cout << "Ingresar año: ";
    cin >> año;

    if ((año % 4 == 0 && año % 100 != 0) || año % 400 == 0)
    {
        cout << "Año bisiesto." << endl;
        return 0;
    }
    cout << "No es año bisiesto." << endl;
    return 0;
}