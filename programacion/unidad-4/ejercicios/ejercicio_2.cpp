/*
Dado tres valores determinar e imprimir una leyenda informando si “Forman triangulo” o “No
forman triangulo”.
Tener en cuenta el teorema de desigualdad de los triángulos: En todo triángulo la suma de las
longitudes de dos lados cualesquiera es siempre mayor a la longitud del lado restante.
*/

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

    if ((a + b > c) && (a + c > b) && (b + c > a)) cout << "Forman triangulo" << endl;
    else cout << "No forman triangulo" << endl;
}