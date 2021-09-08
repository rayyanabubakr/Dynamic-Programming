// 1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
// 2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void paintHouse(int **arr, int n, int k)
{
    int dp[n][k];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < k ; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    for(int j = 0; j  < k ; j++)
    {
        dp[0][j] = arr[0][j];
    }
    for(int i = 1; i < n ; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int m = 0; m < k; m++)
            {
                if(j != m)
                {
                    dp[i][j] = min(dp[i-1][m], dp[i][j]);   
                }
            }
            dp[i][j] += arr[i][j];
        }
    }
    int ans = INT_MAX;
    for(int i = 0 ; i < k ; i++)
    {
        ans = min( ans , dp[n-1][i]);
    }
        cout << ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int **arr = new int * [n];
    for(int i = 0 ; i < n; i++)
    {
        arr[i] = new int [k];
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < k ; j++)
        {
            cin >> arr[i][j];
        }
    }
    paintHouse(arr, n, k);
}
