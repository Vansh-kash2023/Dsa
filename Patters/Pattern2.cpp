#include<iostream>
using namespace std;

void nForest(int n) {
	for(int i =0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout<<"* ";
		}
		for(int k=n; k<i-1; k--){
			cout<<" ";
		}
		cout<<endl;
	}
}


int main(){
    nForest(5);
    return 0;
}