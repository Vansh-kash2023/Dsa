#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// int count=0;
// int printNtimes(int n){
//     if (count==n){
//         return 0;
//     }else{
//         cout<<"Vansh"<<" ";
//         count+=1;
//         printNtimes(n);
//     }
// }

vector<string> printNTimes(int n) {
    // Write your code here.
    vector<string>vec;
    if(n<1){
        return vec;
    }
    cout<<"Coding Ninjas"<<" ";
    printNTimes(n-1);
}

int main(){
    // printNtimes(5);
    printNTimes(5);
    return 0;
}