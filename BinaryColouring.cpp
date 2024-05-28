#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        cout<<32<<endl;
        vector<int> ans(32, 0);

        for(int i=0;i<32;i++){
            if(x & (1<<i)){
                ans[i] = 1;
            }
        }

        for(int i=0;i<31;i++){
            if(ans[i]>1){
                ans[i]=0;
                ans[i+1]++;
                continue;
            }
            else if((ans[i]==1) && (ans[i+1]==1)){
                ans[i] = -1;
                ans[i+1]++;
            }
        }

        for(int i=0;i<32;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}