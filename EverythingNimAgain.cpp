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
        bool flag = 1;
        sort(nums.begin(), nums.end());
        if(nums[1]>1 || n==1){
            cout<<"Alice"<<endl;
        }
        else{
            for(int i=2;i<=n;i++){
                if(nums[i]!=nums[i-1]){
                    flag = 1-flag;
                    if(nums[i]-nums[i-1]>1){
                        break;
                    }
                }
            }
            if(flag){
                cout<<"Alice"<<endl;
            }
            else{
                cout<<"Bob"<<endl;
            }
        }
    }
}