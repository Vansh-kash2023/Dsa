#include<iostream>
using namespace std;

int calcGCD(int n, int m){
    // Write your code here.
    int smaller;
    if(m<n){
        smaller=m;
    }else{
        smaller = n;
    }
    int gcd =0;
    for(int i=1; i<=smaller; i++){
        if(n%i==0 && m%i==0){
            gcd = i;
        }
    }
    return gcd;
}

int main(){
    cout<<calcGCD(40,80);
    return 0;
}