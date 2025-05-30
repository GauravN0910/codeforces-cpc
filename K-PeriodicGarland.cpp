#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int oneCount = 0;

    for(int i=0;i<n;i++){
        oneCount += (s[i]=='1');
    }

    int ans = oneCount;
    for(int start=0;start<k;start++){
        int sum = 0;
        for(int i=start;i<n;i+=k){
            if(s[i]=='1'){
                sum++;
            }
            else{
                sum--;
            }
            
            sum = max(sum, 0);
            ans = min(ans, oneCount - sum);
        }
    }
    cout<<ans<<endl;
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