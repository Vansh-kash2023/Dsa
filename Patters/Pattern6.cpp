#include<iostream>
using namespace std;

void nNumberTriangle(int n) {
    for(int i = 0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    nNumberTriangle(5);
    return 0;
}