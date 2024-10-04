#include<iostream>
using namespace std;

void alphaHill(int n) {
    int index = 0;
    char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(int i=0; i<n; i++){
        for(int j=0; j<2*(n-i)-2; j++){
            cout<<" ";
        }
        for(int j=0; j<i; j++){
            cout<<arr[j]<<" ";
        }
        for(int j=0; j<1; j++){
            cout<<arr[index]<<" ";
            index+=1;
        }
        for(int j=i-1; j>=0; j--){
            cout<<arr[j]<<" ";
        }
        for(int j=0; j<2*(n-i)-2; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    alphaHill(5);
    return 0;
}