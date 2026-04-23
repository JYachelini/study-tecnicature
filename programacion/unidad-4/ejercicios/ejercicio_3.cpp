/*
Dado un número entero que representa una hora con formato de 24 horas, pasarla al formato de
AM-PM e imprimirla por pantalla. Ejemplo 1327 resulta 1:27 PM
*/

#include <iostream>

using namespace std;

int main(){
    int numero;
    cout << "Ingresar numero:";
    cin >> numero;

    int hour = numero / 100;
    int minutes = numero % 100;

    string time;
    if(hour < 12) time = " AM";
    else time = " PM";

    if(minutes < 10) cout << hour << ":" << "0" << minutes << time << endl;
    else cout << hour << ":" << minutes << time << endl;
}