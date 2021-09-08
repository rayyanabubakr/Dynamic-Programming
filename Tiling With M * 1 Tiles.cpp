// 1. You are given a number n and a number m separated by line-break representing the length and breadth of a m * n floor.
// 2. You've an infinite supply of m * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.
#include<bits/stdc++.h>
using namespace std;

int tile(int n, int m)
{

  int count[n + 1];
  count[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (i > m)
      count[i] = count[i - 1] + count[i - m];

    else if (i < m || i == 1)
      count[i] = 1;

    else
      count[i] = 2;
  }

  return count[n];
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << tile(n, m);
}
