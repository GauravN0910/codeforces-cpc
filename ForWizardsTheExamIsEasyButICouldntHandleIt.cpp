#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans = 0;
    int lAns = 0;
    int rAns = 0;

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]){
                count++;
            }
            else if(nums[j]<nums[i]){
                count--;
            }


            if(count<ans){
                lAns = i;
                rAns = j;
                ans = count;
            }
        }
    }

    cout<<lAns+1<<" "<<rAns+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}