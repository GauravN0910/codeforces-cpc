#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string a;
    cin>>a;
    string ans = "";
    int n = a.size();
    for(int i=n-1;i>=0;i--){
        if(a[i]=='p'){
            ans.push_back('q');
        }
        else if(a[i]=='q'){
            ans.push_back('p');
        }
        else{
            ans.push_back('w');
        }
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