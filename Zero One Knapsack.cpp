// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without 
//      overflowing it's capacity.

// Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item 
//                again and again.

#include<iostream>
using namespace std;

int knapsack(int profits[], int weights[],int capacity, int n)
{
    int dp[n + 1][capacity + 1];
    for(int i = 0; i <= n ; i++)
    {
        for(int j = 0; j <= capacity ; j++)
        {
            if(i == 0  || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            else if(j < weights[i])
            {
             
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max( dp[i - 1][j] , dp[i - 1][ j - weights[i]] + profits[i]);
            }
        }
    }
    return dp[n][capacity];
}
int main()
{
  int n;
  cin >> n;
  int profits[n], weights[n];
  for (int i = 1 ; i <= n; i++)
  {
    cin >> profits[i];
  }
  for (int i = 1 ; i <= n ; i++)
  {
    cin >> weights[i];
  }
  int capacity;
  cin >> capacity;
  cout << knapsack(profits, weights, capacity, n);

  return 0;

}
