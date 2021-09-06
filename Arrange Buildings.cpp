// 1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
// 2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
// 3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

#include<iostream>
using namespace std;

long long int arrangeBuildings(int n)
{
    int dpb[n + 1], dps[n + 1];
    dpb[1] = 1;
    dps[1] = 1;
    for(int i = 2; i <=n ; i++)
    {
        dpb[i] = dps[i - 1];
        dps[i] = dps[i - 1] + dpb[i - 1];
    }
    long long int total = dps[n] + dpb[n];
    return total * total; 
    
}

int main()
{
    int n;
    cin >> n;
    cout << arrangeBuildings(n);
}
