#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// GFG
// long long sumOfSeries(long long n) {
//         // code here
//         long long dup = n;
//         long long result = 0;
//         if(dup!=0){
//             long long multiplication = (dup*dup*dup);
//             dup--;
//             result = multiplication + sumOfSeries(dup);
//         }
//         return result;
//     }

// Code360
long long sumFirstN(long long n)
{
    // Write your code here.
    long long dup = n;
    long long sum = 0;
    if (dup != 0)
    {
        long long digit = dup;
        dup--;
        sum = digit + sumFirstN(dup);
    }
    return sum;
}

int main()
{
    // long long a = sumOfSeries(5);
    // cout<<a;
    long long b = sumFirstN(4);
    cout << b;
    return 0;
}