// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
// 4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from 
//      any row in the left wall.
// 5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug out from the mine.

#include<iostream>
#include<algorithm>
using namespace std;

int maxGold(int** arr, int r, int c)
{
  int cost = 0;
  for (int j = 1 ; j < c; j++)
  {
    for (int i = 0 ; i < r; i++)
    {
      if (i == 0)
      {
        arr[i][j] += max(arr[i][j - 1], arr[i + 1][j - 1]);
      }
      else if (i == r - 1)
      {
        arr[i][j] += max(arr[i - 1][j - 1], arr[i][j - 1]);
      }
      else
      {
        arr[i][j] += max(max(arr[i - 1][j - 1], arr[i][j - 1 ]), arr[i + 1][j-1]);
      }
    }
  }
  for (int i = 0 ; i < r; i++)
  {
    cost = max(cost,arr[i][c-1]);
  }

  return cost;
}
int main()
{
  int r, c;
  cin >> r >> c;
  int** arr = new int* [r];
  for (int i = 0; i < r ; i++)
  {
    arr[i] = new int [c];
  }
  for (int i = 0; i < r ; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr[i][j];
    }
  }
  cout << maxGold(arr, r, c);
}
