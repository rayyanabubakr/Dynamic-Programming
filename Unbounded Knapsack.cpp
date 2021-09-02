// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without 
//     overflowing it's capacity.
// Note -> Each item can be taken any number of times. You are allowed to put the same item again 
//                   and again.

#include<iostream>
using namespace std;

int knapsack(int profits[], int weights[], int capacity, int n)
{
  int dp[capacity + 1];
  for (int i = 0 ; i <= capacity; i++)
  {
    dp[i] = 0;
  }
  for (int i = 0; i <= capacity  ; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (weights[j] <= i)
      {
        dp[i] = max( dp[i], dp[ i - weights[j]] + profits[j]);
      }
    }
  }
  return dp[capacity];
}
int main()
{
  int n;
  cin >> n;
  int profits[n], weights[n];
  for (int i = 0 ; i < n; i++)
  {
    cin >> profits[i];
  }
  for (int i = 0 ; i < n ; i++)
  {
    cin >> weights[i];
  }
  int capacity;
  cin >> capacity;
  cout << knapsack(profits, weights, capacity, n);

  return 0;

}
