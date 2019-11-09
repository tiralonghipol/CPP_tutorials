#include "parent.h"

using namespace std;

int main()
{
    Parent mike;
    Child paolo;

    mike.PrintVarP();
    paolo.SetP(20);
    paolo.PrintVarP();
    
    return 0;
}