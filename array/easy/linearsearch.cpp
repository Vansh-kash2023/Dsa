#include<bits/stdc++.h>
using namespace std;

int linearSearch(int *arr, int n, int x)
{
    //Write your code here
    int index = -1;
    for(int i = 0; i<n; i++){
        if(arr[i]==x){
            index=i;
            break;
        }
    }
    return index;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int res = linearSearch( arr, 6, 6);
    cout<<res;
    return 0;
}