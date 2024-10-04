#include<iostream>
using namespace std;


void nBinaryTriangle(int n) {
    int num = 0;
    for(int i = 1; i<=n; i++){
        if(i%2==0){
                num = 1;
            }else{
                num = 0;
            }
        for(int j = 0; j<i; j++){
            cout<<num;
            num = 1-num;
        }
        cout<<endl;
    }
}

int main(){
    nBinaryTriangle(6);
    return 0;
}