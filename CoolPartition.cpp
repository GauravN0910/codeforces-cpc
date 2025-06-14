#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;

    int ans = 1;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    set<int> prevSet;
    prevSet.insert(nums[0]);

    set<int> curSet;
    for(int i=1;i<n;i++){
        if(prevSet.find(nums[i])!=prevSet.end()){
            prevSet.erase(nums[i]);
        }
        curSet.insert(nums[i]);
        if(prevSet.empty()){
            prevSet = curSet;
            curSet.clear();
            ans++;
        }
    }

    cout<<ans<<endl;
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