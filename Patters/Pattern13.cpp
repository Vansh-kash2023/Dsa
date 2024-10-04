#include<iostream>
using namespace std;

void TablePattern(int n){
    int num=1;
    for(int i= 0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<num<<" ";
            num+=1;
        }
        cout<<endl;
    }
}

int main(){
    TablePattern(5);
    return 0;
}