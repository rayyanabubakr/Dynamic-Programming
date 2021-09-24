// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
// i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxprofit(int arr[], int n)
{
    int sd = 0, bd = 0 , profit = 0;
    for(int i = 1; i < n ; i++)
    {
        if(arr[i] >= arr[i - 1])
        {
            sd++;
        }
        else
        {
            profit += arr[sd] - arr[bd];
            if(bd != sd)
            {
                i++;
            }
 
            sd = bd = i;
        }
    }
    profit += arr[sd] - arr[bd];
    
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
