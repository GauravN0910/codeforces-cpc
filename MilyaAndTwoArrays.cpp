#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> mapA;
    map<int, int> mapB;

    if(n<=2){
        cout<<"NO"<<endl;
    }

    for(int i=0;i<n;i++){
        cin>>a[i];
        mapA[a[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        mapB[b[i]]++;
    }

    if((mapA.size() + mapB.size() >= 4)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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