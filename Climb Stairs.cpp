// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. In one move, you are allowed to climb 1, 2 or 3 stairs.
// 4. You are required to print the number of different paths via which you can climb to the top.

#include <iostream>
using namespace std;
int cs(int n) {
  // write your code here
  int f[n + 2];
  int i;


  f[0] = 1;
  f[1] = 1;
  f[2] = 2;

  for (i = 3; i <= n; i++)
  {

    f[i] = f[i - 1] + f[i - 2] +f[i - 3];
  }
  
  return f[n];
}

int main() {
  int n;
  cin >> n;
  cout << cs(n) << endl;
}
