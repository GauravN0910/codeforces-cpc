#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool checkerFn(int mid, vector<vector<int>>& joy, int m, int n){
    vector<int> friendVisited(n, 0);
    bool storeRep = false;
    for(int i=0;i<m;i++){
        int storeCount = 0;
        for(int j=0;j<n;j++){
            if(joy[i][j] >= mid){
                friendVisited[j] = 1;
                storeCount++;
            }
        }
        if(storeCount >= 2){
            storeRep = true;
        }
    }

    int friendCount = 0;
    for(int i=0;i<n;i++){
        friendCount += friendVisited[i];
    }

    return (storeRep && friendCount==n);
}

void solve(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> joy(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>joy[i][j];
        }
    }


    int low = 1, high = 1e9;
    int ans = 1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(checkerFn(mid, joy, m, n)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}