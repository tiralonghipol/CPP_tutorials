#include <iostream>

using namespace std;

int Sum(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

void WelcomMessage()
{
    cout << "Welcome to this program!" << endl;
}

int main()
{
    int x, y;
    
    WelcomMessage();

    cout << "Enter number 1: ";
    cin >> x;
    cout << "Enter number 2: ";
    cin >> y;
    cout << x << " + " << y << " = " << Sum(x, y) << endl;

    return 0;
}