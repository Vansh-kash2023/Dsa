#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int evenlyDivides(int N){
        vector<int> v;
        int Temp = N;
        while(Temp>0){
            int lastdigit = Temp%10;
            v.push_back(lastdigit);
            Temp=Temp/10;
        }
        vector<int>::iterator myItr;
        int count=0;
        for(myItr=v.begin(); myItr!=v.end(); myItr++){
            if(*myItr != 0){
                if(N % *myItr==0){
                count+=1;
                }
            }else{
                continue;
            }
        }
        return count;
    }
};

int main(){
    
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.evenlyDivides(N)<<endl;
    
    return 0;
}