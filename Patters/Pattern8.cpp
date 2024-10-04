#include<iostream>
using namespace std;

void nStarTriangle(int n) {
    for(int i=0; i<n; i++ ){
        for(int j= 1; j<=i; j++ ){
            cout<<" ";
        }

        for(int j=0; j<2*n-(2*i+1); j++){
            cout<<"*";
        }

        for(int j= 1;j<=i; j++ ){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    nStarTriangle(5);
    return 0;
}