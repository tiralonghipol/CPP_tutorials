#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Dog
{
private:
    int age;
    string name;

public:
    Dog(string na, int ag); // constructor
    int getAge();
    string getName();
    void Bark();
    void Introduce();
};

