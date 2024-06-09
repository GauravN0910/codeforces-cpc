#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> count(n+1);
    int level = 0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            level++;
        }
        else{
            level--;
        }
        ans += count[level];
        if(level){
            count[(level-1)>>1] = 0;
        }
        count[level]++;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}