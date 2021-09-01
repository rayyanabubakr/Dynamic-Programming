// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. You are required to calculate and print true or false, if there is a subset the elements of which add 
//      up to "tar" or not.

#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int targetSubsets(int arr[], int tar, int n)
{
  int dp[n + 1][tar + 1];
  for (int i = 0; i <= n ; i++)
  {
    for (int j = 0; j <= tar; j++)
    {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i <= n  ; i++)
  {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n ; i++)
  {
    for (int j = 1; j <= tar; j++)
    {
      if (j < arr[i - 1])
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j] = dp[i - 1][ j ] || dp[i - 1][j - arr[i - 1]];
      }
    }
  }

  return dp[n][tar];
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int target;
  cin >> target;
  int ans = targetSubsets(arr, target, n);
  if (ans == 1)
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
}
