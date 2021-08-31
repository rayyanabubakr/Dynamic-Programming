// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom- 
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(int** arr, int n, int m)
{
  int dp[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = arr[0][0];
  
  for (int j = 1; j < m ; j++)
  {
    dp[0][j] = arr[0][j] + dp[0][j - 1];
  }
  for (int i = 1; i < n ; i++)
  {
    dp[i][0] = arr[i][0] + dp[i - 1][0];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      dp[i][j] = arr[i][j] + min( dp[i][j - 1] , dp[i - 1][j] );
    }
  }
  int x = dp[n - 1][m - 1];
  return x;

}
int main()
{
  int n, m;
  cin >> n >> m;
  int** arr = new int* [n];
  for (int i = 0; i < n ; i++)
  {
    arr[i] = new int[m];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  cout << minCost(arr, n, m);
}
