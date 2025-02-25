#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void printAns(int k, vector<pair<int, int>>& ans, int y, int x){
    if(k==0){
        return;
    }

    long long n = 0;
    while((n*(n-1))/2 < k){
        n++;
    }
    if((n*(n-1))/2 > k){
        n--;
    }

    long long remaining = k - (n*(n-1))/2;
    
    for(long long xCoord=1;xCoord<=n;xCoord++){
        ans.push_back({xCoord + x, y});
    }
    printAns(remaining, ans, y+1, x+500);
}

void solve(){
    long long k;
    cin>>k;
    vector<pair<int, int>> ans;
    printAns(k, ans, 0, 0);
    cout<<ans.size()<<endl;
    for(auto [x, y]:ans){
        cout<<x<<" "<<y<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}