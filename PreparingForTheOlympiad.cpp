#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<int> numsM(n);
    vector<int> numsS(n);
    for(int i=0;i<n;i++){
        cin>>numsM[i];
    }

    for(int i=0;i<n;i++){
        cin>>numsS[i];
    }

    int ans = 0;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            ans += numsM[i];
        }
        else{
            if(numsM[i]>numsS[i+1]){
                ans += (numsM[i] - numsS[i+1]);
            }
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