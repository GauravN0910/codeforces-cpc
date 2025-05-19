#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;   
    int low = 0;
    int high = n;
    int ansMex = 0;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(n/max(mid, k)>m || (n/max(mid, k)==m && n%max(mid, k)>=mid)){
            ansMex = mid;                                                               
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    vector<int> ans(n, 1e9);
    for(int i=0;i<ansMex;i++){
        for(int j=i;j<n;j+=max(ansMex, k)){
            ans[j] = i;
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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