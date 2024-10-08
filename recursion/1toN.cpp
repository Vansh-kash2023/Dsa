#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> printNos(int x) {
    // Write Your Code Here
    vector<int> result;
    if(x<1){
        return result;
    }

    result=printNos(x-1);
    result.push_back(x);

    return result;
}

int main(){
    vector<int> result = printNos(5); // Call the function with x = 5
    for (int num : result) {
        cout << num << " "; // Print each number in the vector
    }
    return 0;
}