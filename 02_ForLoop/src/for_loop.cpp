#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Line number = " << i << endl;
        system("read -p 'Press Enter to continue...' var");
        // equivalent of Windows: system("pause");
    }

    return 0;
}