#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> pieces(n);

    long long total = 0;
    for(long long i=0;i<n;i++){
        cin>>pieces[i];
    }

    long long ans = 0;
    for(int i=0;i<n;i++){
        total += pieces[i];
        int x = sqrt(total);
        if(x%2 && x*x==total){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}