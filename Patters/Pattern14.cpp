#include<iostream>
using namespace std;

void nLetterTriangle(int n) {
    char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(int i = 0; i<n; i++){
        for( int j= 0; j<=i; j++){
            cout<<arr[j];
        }
        cout<<endl;
    }
}

int main(){
    nLetterTriangle(5);
    return 0;
}