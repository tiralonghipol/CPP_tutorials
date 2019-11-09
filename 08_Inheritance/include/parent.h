#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Parent
{
private:
    int varS;
    void PrintVarS();

public:
    Parent();
    int varP;
    void PrintVarP();
protected:
    int varX;
    void PrintX();
    void SetX(int x);
};

class Child : public Parent
{

public:
    void SetP(int a);
};
