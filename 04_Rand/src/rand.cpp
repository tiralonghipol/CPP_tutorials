#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int num, numrand;
    string name;
    char yn = 'a';
    srand(time(NULL));

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Hello, " << name << " want to play a game? (y/n): ";
    cin >> yn;

    
    if (yn == 'n' || yn == 'N')
    {
        cout << "Oh, maybe next time :(" << endl;
        return 0;
    }

    while (true)
    {
        cout << "Guess PC number [0,5]: ";
        cin >> num;
        numrand = rand() % 5;
        if (numrand == num)
            cout << "You win!" << endl;
        else if (num == -1)
            break;
        else
            cout << "You lose!" << endl;
    }
    return 0;
}