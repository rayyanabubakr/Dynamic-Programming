// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed a single transaction.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxprofit(int arr[], int n)
{
    int profit= 0, min_price=INT_MAX;
    for(int i = 0 ; i < n ; i++)
    {
       if(arr[i] < min_price)
       {
           min_price = arr[i];
       }
       int curr_prof = arr[i] - min_price;
       if(curr_prof > profit)
       {
           profit = curr_prof;
       }
    }
    return profit;
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
