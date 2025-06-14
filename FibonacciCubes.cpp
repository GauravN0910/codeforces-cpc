#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<int> fib(n+1);
    fib[1] = 1;
    fib[2] = 2;
    for(int i=3;i<=n;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(int i=0;i<m;i++){
        vector<int> dimension(3);
        cin>>dimension[0]>>dimension[1]>>dimension[2];

        sort(dimension.begin(), dimension.end());
        if(dimension[0]>=fib[n] && dimension[2]>=(fib[n] + fib[n-1])){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;

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