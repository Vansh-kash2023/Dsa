#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<3; i++){
        for( auto it:nums){
            if(i==it){
                res.push_back(it);
            }
        }
    }
    for(auto it:res){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> color = {0,1,1,2,0,2,0,1,0,2,2,0,1};
    sortColors(color);
    return 0;
}