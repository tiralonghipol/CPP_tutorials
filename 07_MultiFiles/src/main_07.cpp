#include "cat.h"
#include "dog.h"

using namespace std;

int main()
{
    Cat cat1("CJ",5);
    Dog dog1("Fido", 8);

    cat1.Introduce();
    dog1.Introduce();
    
    return 0;
}