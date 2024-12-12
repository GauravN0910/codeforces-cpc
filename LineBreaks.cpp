#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> strings(n);
    vector<int> strLengths(n);

    for(int i=0;i<n;i++){
        cin>>strings[i];
        strLengths[i] = strings[i].size();
    }

    int sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(sum + strLengths[i] > m){
            break;
        }
        sum += strLengths[i];
        ans++;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}