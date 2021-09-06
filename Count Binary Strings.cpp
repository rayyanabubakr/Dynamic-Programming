// 1. You are given a number n.
// 2. You are required to print the number of binary strings of length n with no consecutive 0's.

#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;

int binaryStrings(const int n)
{
    int dp0[n + 1], dp1[n + 1];
    dp0[1] = 1;
    dp1[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        dp0[i] = dp1[i - 1];
        dp1[i] = dp0[i - 1] + dp1[i - 1];
    }
    
    return dp0[n] + dp1[n];
}
int main()
{
    int n;
    cin >> n;
    cout << binaryStrings(n);
}
