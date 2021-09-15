// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are give a number fee, representing the transaction fee for every transaction.
// 4. You are required to print the maximum profit you can make if you are allowed infinite transactions, but has to pay "fee" for every closed transaction.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxprofit(int arr[], int n, int fee)
{
    int cash = 0, hold = -arr[0];                 
	for(int i = 1; i < n; ++i){
		cash = max(cash, hold + arr[i] - fee);        
		hold = max(hold, cash - arr[i]);   
	}
	return cash;
    
}
int main()
{
    int n, fee;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> arr[i];
    }
    cin >> fee;
    cout << maxprofit(arr, n, fee);
}
