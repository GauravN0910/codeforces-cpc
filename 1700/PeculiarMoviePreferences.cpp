#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<string> scenes(n);
    for(int i=0;i<n;i++){
        cin>>scenes[i];
    }

    map<string, int> map;
    for(int i=0;i<n;i++){
        map[scenes[i]]++;
        string x = scenes[i];
        reverse(x.begin(), x.end());
        if(map.count(x) || (x.size()>1 && map.count(x.substr(0, 2)))){
            cout<<"YES"<<endl;
            return;
        }
        for(char c='a';c<='z';c++){
            if(map.count(x+c)){
                cout<<"YES"<<endl;
                return;
            }
        }   
    }
    cout<<"NO"<<endl;
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}