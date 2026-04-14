#include <iostream>
using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    
    cout << "Enter A value: ";
    cin >> a;
    
    cout << "Enter B value: ";
    cin >> b;

    int result = sumar(a, b);
    
    cout << "Sum of A and B is: " << result << endl;
    
    return result;
}

