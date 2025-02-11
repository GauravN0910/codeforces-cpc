#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    if(abs(n-m)>k || (n<k && m<k)){
        cout<<-1<<endl;
        return;
    }

    char maxChar = '0';
    char minChar = '1';
    if(m>n){
        swap(n, m);
        maxChar = '1';
        minChar = '0';
    }


    for(int i=1;i<=k;i++){
        cout<<maxChar;
    }
    int remainingMax = n-k;
    for(int i=1;i<=remainingMax;i++){
        cout<<minChar<<maxChar;
    }
    int remainingLength = m - remainingMax;
    for(int i=1;i<=remainingLength;i++){
        cout<<minChar;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt" , "r" , stdin);
    // freopen("output.txt" , "w" , stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}