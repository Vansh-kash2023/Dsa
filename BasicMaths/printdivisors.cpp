#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int printDivisors(int n){
// Write your code here
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}

// int* printDivisors(int n, int &size){
//   int *d=new int[n];
//   int count=0;
//   for(int i=1;i<=n;i++){
//     if(n%i==0)
//       d[count++]=i;
//   }
//   size=count;
//   return d;
// }


int main(){
    printDivisors(10);
    return 0;
    // int n = 12;
    // int size;
    // int* divisors = printDivisors(n, size);

    // // Print the divisors
    // for (int i = 0; i < size; i++) {
    //     cout << divisors[i] << " ";
    // }

    // // Deallocate the memory
    // delete[] divisors;

    // return 0;
}