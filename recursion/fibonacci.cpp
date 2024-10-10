#include<bits/stdc++.h>
using namespace std;

// vector<int> generateFibonacciNumbers(int n) {
//     // Write your code here.
//     if(n==1){
//         vector<int> res;
//         int num1 = 0;
//         res.push_back(num1);
//         return res;
//     }
//     else if(n==2){
//         vector<int> res;
//         int num1 = 0;
//         int num2 = 1;
//         res.push_back(num1);
//         res.push_back(num2);
//         return res;
//     }
//     vector<int> res;
//     int num1 = 0;
//     int num2 = 1;
//     res.push_back(0);
//     res.push_back(1);
//     int num3;
//     for(int i = 0; i<n-2; i++){
//         num3 = num1 + num2;
//         res.push_back(num3);
//         num1=num2;
//         num2=num3;
//     }
//     return res;
// }

int fib(int n) {
        if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
    }

int main(){
    // vector<int> s = generateFibonacciNumbers(5);
    // for(auto it:s){
    //     cout<<it<<" ";
    // }
    int b = fib(3);
    cout<<b;
    return 0;
}