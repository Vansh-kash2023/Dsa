#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int countDigit(long long x) {
    // Write your code here.
    int count=0;
    while(x>0){
        int lastdigit=x%10;
        x=x/10;
        count+=1;
    }
    return count;
}

int main(){
    cout<< countDigit(89795);
    return 0;
}