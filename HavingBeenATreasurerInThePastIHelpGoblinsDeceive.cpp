#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    string s;
    cin>>s;

    long long hyphenCount = 0;
    for(long long i=0;i<n;i++){
        if(s[i]=='-'){
            hyphenCount++;
        }
    }

    long long underCount = n - hyphenCount;

    long long ans = underCount * (hyphenCount/2) * (hyphenCount - hyphenCount/2);
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