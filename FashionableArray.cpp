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
    sort(nums.begin(), nums.end());

    if(nums[0]%2 == nums[n-1]%2){
        cout<<0<<endl;
        return;
    } 
    else{
        int ans = 1e9;
        int x = 0;
        while(x<n && nums[x]%2 == nums[0]%2){
            x++;
        }
        ans = min(ans, x);
        int y = n-1;
        while(y>=0 && nums[y]%2 == nums[n-1]%2){
            y--;
        }
        ans = min(ans, n-1-y);
        cout<<ans<<endl;
        return;
    }
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