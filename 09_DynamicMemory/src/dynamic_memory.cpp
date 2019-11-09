#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // int A[100];
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *A = new int[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << " " << endl;

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    delete[] A;

    return 0;
}