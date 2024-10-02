#include<iostream>
using namespace std;

void seeding(int n) {
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=n-i; j++){
			cout<<"* ";
		}
		cout<<endl;
	}
}

int main(){
    seeding(5);
    return 0;
}