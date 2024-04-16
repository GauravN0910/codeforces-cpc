#include<bits/stdc++.h>
using namespace std;

vector<int> BinDec = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100,
                        10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000};

int dp[100001];

bool dfs(int n){
    if(n==1){
        return true;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    bool ans = false;

    for(int x:BinDec){
        if(n%x==0){
            ans = ans || dfs(n/x);
        }
    }
    return dp[n]=ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(dp, -1, sizeof(dp));

        bool ans = dfs(n);
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}