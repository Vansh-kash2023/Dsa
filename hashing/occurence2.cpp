#include<bits/stdc++.h>
using namespace std;

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
    int c = 0;
    for(auto it:arr){
        if(it==x){
            c+=1;
        }
    }
    return c;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,5,4,6,2};
    cout<< count(arr, 10, 6);
    return 0;
}