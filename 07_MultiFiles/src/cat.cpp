#include "cat.h"

int Cat::getAge()
{
    return age;
}

string Cat::getName()
{
    return name;
}

void Cat::Meow()
{
    cout << "Meow! " << endl;
}

void Cat::Introduce()
{
    Meow();
    cout << "My name is " << name << " and I am " << age << "." << endl;
}

Cat::Cat(string na, int ag)
{
    age = ag;
    name = na;
}