#include<iostream>
using namespace std;

void nForest(int n) {
	for(int i =0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"* ";
		}
		cout<<endl;
	};
}


int main(){
    nForest(6);
    return 0;
}