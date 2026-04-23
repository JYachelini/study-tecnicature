/*Solicitar al usuario que ingrese 3 notas y calcular el promedio e informarlo por pantalla de la
siguiente forma:
∙ Si es menor a 4, mostrar Insuficiente
∙ Si está entre 4 y 6 mostrar Regular
∙ Si está entre 6 y 8 mostrar Bien
∙ Si está entre 8 y 9 mostrar Muy Bien
∙ Si está entre 9 y 10 mostrar Sobresaliente */

#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cout << "Ingresa valor a: ";
    cin >> a;
    cout << "Ingresa valor b: ";
    cin >> b;
    cout << "Ingresa valor c: ";
    cin >> c;

    int promedio = (a + b + c) / 3;

    if (promedio < 4) cout << "Insuficiente" << endl;
    else if (promedio < 6) cout << "Regular" << endl;
    else if (promedio < 8) cout << "Bien" << endl;
    else if (promedio < 10) cout << "Muy bien" << endl;
    else cout << "Sobresaliente" << endl;
}