#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, k, x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    x--;

    string ans = "";
    long long ways = 0;
    for(long long i=n-1;i>=0;i--){
        if(s[i]=='a'){
            ans += 'a';
            continue;
        }
        ways += k;
        if(i==0 || s[i-1]=='a'){
            long long remainder = (x%(ways+1));
            x = x/(ways+1);
            for(long long j=0;j<remainder;j++){
                ans += 'b';
            }
            ways = 0;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
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