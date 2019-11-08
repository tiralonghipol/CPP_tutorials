#include "dog.h"

int Dog::getAge()
{
    return age;
}

string Dog::getName()
{
    return name;
}

void Dog::Bark()
{
    cout << "Bau! " << endl;
}

void Dog::Introduce()
{
    Bark();
    cout << "My name is " << name << " and I am " << age << "." << endl;
}

Dog::Dog(string na, int ag)
{
    age = ag;
    name = na;
}