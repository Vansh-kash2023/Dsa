#include<iostream>
using namespace std;

void symmetry(int n) {
    for(int i =0; i<n; i++){
        for(int j=n-i; j>=1; j--){
            cout<<"*"<<" ";
        }
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        for(int j=n-i; j>=1; j--){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    for(int i =1; i<=n; i++){
        for(int j=0; j<i; j++){
            cout<<"*"<<" ";
        }
        for(int j=0; j<2*n-2*i; j++){
            cout<<" ";
        }
        for(int j=0; j<i; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

int main(){
    symmetry(3);
    return 0;
}