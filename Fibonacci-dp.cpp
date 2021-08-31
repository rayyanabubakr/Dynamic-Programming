// 1. You are given a number n.
// 2. You are required to print the nth element of fibonnaci sequence.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int fib(int n)
{

  int f[n + 2];
  int i;


  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
    f[i] = f[i - 1] + f[i - 2];
  }
  
  return f[n];
}


int main() {
  int n;
  cin >> n;
  int memo[n + 1];
  memset(memo, 0, n + 1);
  cout << fib(n) << endl;
  return 0;
}
