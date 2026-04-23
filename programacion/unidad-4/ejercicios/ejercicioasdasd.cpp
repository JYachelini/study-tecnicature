#include <iostream>

using namespace std;
bool esPar(int a)
{
    if (a % 2 == 0)
        return true;
    return false;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10, y = 20;
    int r = x;
    swap(x, y);
    cout << x << " " << y << " " << r;
    return 0;
}