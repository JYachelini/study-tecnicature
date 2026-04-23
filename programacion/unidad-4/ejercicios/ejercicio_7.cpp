/*
Dados un mes y año correspondiente informar cuantos días tiene el mes.
*/

#include <iostream>

using namespace std;

int main()
{
    int año, mes;
    bool biciesto;
    cout << "Ingresar año: ";
    cin >> año;
    cout << "Ingresar mes: ";
    cin >> mes;

    if ((año % 4 == 0 && año % 100 != 0) || año % 400 == 0)
    {
        biciesto = true;
    }
    else
        biciesto = false;

    switch (mes)
    {
    case 1:
        cout << 31 << endl;
    case 2:
        if (biciesto)
            cout << 29 << endl;
        else
            cout << 28 << endl;
    case 3:
        cout << 31 << endl;
    case 4:
        cout << 30 << endl;
    case 5:
        cout << 31 << endl;
    case 6:
        cout << 30 << endl;
    case 7:
        cout << 31 << endl;
    case 8:
        cout << 31 << endl;
    case 9:
        cout << 30 << endl;
    case 10:
        cout << 31 << endl;
    case 11:
        cout << 30 << endl;
    case 12:
        cout << 31 << endl;
    }
    return 0;
}