/*
Dado un número entero de 5 dígitos informar por pantalla si es capicúa. Un número es capicúa si
se puede leer en ambos sentidos el mismo valor, por ejemplo el número 1441 es capicúa pero
1414 no lo es.
*/

#include <iostream>

using namespace std;

int main(){
    int valor;
    cout << "Ingrese valor: ";
    cin >> valor;

    if(valor < 10000) {
        cout << "Valor ingresado muy bajo. Minimo 5 digitos.";
        return 0;
    }

    int pos_1, pos_2, pos_4, pos_5;

    pos_1 = valor / 10000;
    cout << "Posicion 1 " << pos_1 << endl;
    pos_2 = (valor / 1000) % 10;
    cout << "Posicion 2 " << pos_2 << endl;
    pos_4 = (valor % 100) / 10;
    cout << "Posicion 4 " << pos_4 << endl;
    pos_5 = valor % 10;
    cout << "Posicion 5 " << pos_5 << endl;

    if(pos_1 == pos_5 && pos_2 == pos_4) cout << "Capicúa" << endl;
    else cout << "No es capicúa" << endl;
    return 0;
}