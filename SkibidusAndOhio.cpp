#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout<<1<<endl;
            return;
        }
    }
    cout<<n<<endl;
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