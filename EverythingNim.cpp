#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n+1);
        for(int i=1;i<=n;i++){
            cin>>nums[i];
        }

        sort(nums.begin(), nums.end());

        int maxi = 1;
        int mex = 1;

        for(int i=1;i<=n;i++){
            maxi = max(maxi, nums[i]);
            if(nums[i]==mex){
                mex++;
            }
        }

        int ans = min(mex, maxi);
        if(ans%2){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
}