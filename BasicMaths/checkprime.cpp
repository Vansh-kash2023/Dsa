#include<iostream>
using namespace std;

bool isPrime(int n)
{
	// Write your code here.
    int count=0;
    for(int i = 1; i<=n; i++){
        if(n%i==0){
            count+=1;
        }
    }
    if(count ==2) cout<<"YES";
    else cout<<"NO";
}

int main(){
    isPrime(3);
    return 0;
}