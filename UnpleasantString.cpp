#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<vector<int>> nextPos(n+1, vector<int>(26));

    for(int i=0;i<k;i++){
        nextPos[n][i] = n+1;
    }

    for(int i=n-1;i>=0;i--){
        nextPos[i] = nextPos[i+1];
        int charIdx = s[i] - 'a';
        nextPos[i][charIdx] = i+1;
    }

    vector<int> dp(n+2, 0);
    dp[n+1] = 0;

    for(int i=n;i>=0;i--){
        int minAdd = INT_MAX;
        for(int j=0;j<k;j++){
            minAdd = min(minAdd, dp[nextPos[i][j]]);
        }
        dp[i] = minAdd + 1;
    }

    int q;
    cin>>q;
    while(q--){
        string x;
        cin>>x;
        int position = 0;
        for(auto c: x){
            int charIdx = c - 'a';
            position = nextPos[position][charIdx];
            if(position == n+1){
                break;
            }
        }
        cout<<dp[position]<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}