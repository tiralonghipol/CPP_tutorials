#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Cat
{
private:
    int age;
    string name;

public:
    Cat(string na, int ag); // constructor
    int getAge();
    string getName();
    void Meow();
    void Introduce();
};

