// 1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
// 2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two consecutive  fences have same colors.

#include<bits/stdc++.h>
using namespace std;

void paintFence(int n, int k)
{
    long int same = k * 1;
    long int diff = k * (k - 1);
    long int total = same + diff;
    
    for(int i = 3; i <=n ; i++)
    {
        same = diff * 1;
        diff = total * (k - 1);
        total = same + diff;
    }
    cout << total;
}

int main()
{
    int n , k;
    cin >> n >> k;
    paintFence(n , k);
}
