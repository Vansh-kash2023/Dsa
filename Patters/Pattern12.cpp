#include<iostream>
using namespace std;

void numberCrown(int n) {
    int space = 2*(n-1);
    for(int i= 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            cout<<j+1<<" ";
        }
        
        for(int j= 1; j<=space; j++){
            cout<<" ";
        }

        for(int j = i; j>=1; j--){
            cout<<j<<" ";
        }

        cout<<endl;
        space-=2;
    }
}

int main(){
    numberCrown(3);
    return 0;
}