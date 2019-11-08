#include "ship_battle.h"

using namespace std;

void Clear()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
void Show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void SetShips()
{
    int s = 0;
    while (s < maxShips)
    {
        int x = rand() % rows;
        int y = rand() % cols;
        if (matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y)
{
    if (matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int NumberOfShips()
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 1)
                count++;
        }
    }
    return count;
}

int main()
{
    srand(time(NULL));
    int p1, p2;
    char yn;
    Clear();
    SetShips();
    // Show();
    // cout << "----------------" << endl;
    while (1)
    {
        cout << "Enter p1 p2: ";
        cin >> p1 >> p2;
        if (p1 == -1 && p2 == -1)
            Show();
        if (Attack(p1, p2))
            cout << "Hit!" << endl;
        else
            cout << "Miss!" << endl;
        cout << "Number of ships left: " << NumberOfShips() << endl;
        cout << "Surrender? (y/n) ";
        cin >> yn;
        if (yn == 'y')
            break;
    }
    cout << "Game Over! "<< endl;
    Show();
    return 0;
}