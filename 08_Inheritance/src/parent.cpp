#include "parent.h"

Parent::Parent()
{
    varS = 5;
    varP = 10;
}

void Parent::PrintVarP()
{
    cout << "P = " << varP << endl;
}

void Parent::PrintVarS()
{
    cout << "S = " << varS << endl;
}

void Child::SetP(int a)
{
    varP = a;
}