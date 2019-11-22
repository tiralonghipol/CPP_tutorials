#include <iostream>
#include <cstdlib>

using namespace std;

void increase(int  &p)
{
    p++;
}

int main()
{
    // int A[100];
    int a = 10;
    
    cout << a << endl;
    increase(a);
    cout << a << endl;

    return 0;
}