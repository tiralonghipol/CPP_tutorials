#include <iostream>
#include <stdlib.h>

const int rows = 5;
const int cols = 5;
int matrix[rows][cols];

int maxShips = 5;

void Clear();
void Show();
void SetShips();
bool Attack(int x,int y);
int NumberOfShips();