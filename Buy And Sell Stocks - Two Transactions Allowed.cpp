// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include<iostream>
#include <array>
#include<bits/stdc++.h>
using namespace std;

int maxprofit(int price[], int n)
{
    int profit[n];
    int max_price = price[n-1]; 
    for(int i = 0 ; i < n ; i++)
    {
        profit[i] = 0;
    }
    for (int i=n-2;i>=0;i--) 
    { 
        if (price[i] > max_price) 
            max_price = price[i]; 
  
        profit[i] = max(profit[i+1], max_price-price[i]); 
    } 
    int min_price = price[0]; 
    for (int i=1; i<n; i++) 
    { 
        if (price[i] < min_price) 
            min_price = price[i]; 
  
        
        profit[i] = max(profit[i-1], profit[i] + (price[i]-min_price) ); 
    } 
    int result = profit[n-1]; 
  
    return result; 
} 
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> arr[i];
    }
    cout << maxprofit(arr, n);
}
