#include <iostream>
#include <stdlib.h>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    void printP()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
