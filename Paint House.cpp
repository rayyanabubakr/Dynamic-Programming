// 1. You are given a number n, representing the number of houses.
// 2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void paintHouse(int** arr, int n)
{
  long long int dp[n][3];

  dp[0][0] = arr[0][0];
  dp[0][1] = arr[0][1];
  dp[0][2] = arr[0][2];

  for (int i = 1 ; i < n; i++)
  {
    dp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) + arr[i][0];
    dp[i][1] = min(dp[i - 1][0],dp[i - 1][2]) + arr[i][1];
    dp[i][2] = min(dp[i - 1][0],dp[i - 1][1]) + arr[i][2];
  }
 cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

int main()
{
  int n;
  cin >> n;
  int** arr = new int* [n];
  for (int i = 0; i < n ; i++)
  {
    arr[i] = new int [3];
  }
  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> arr[i][j];
    }
  }
    paintHouse(arr, n);
}
