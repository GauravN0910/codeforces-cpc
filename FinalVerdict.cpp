#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += nums[i];
    }
    
    if(sum == x * n){
        cout<<"YES"<<endl;
        return;
    }   
    else{
        cout<<"NO"<<endl;
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