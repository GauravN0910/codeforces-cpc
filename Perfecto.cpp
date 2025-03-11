#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    long long totalSum = (n*(n+1))/2;
    long long root = sqrt(totalSum);
    if(root*root==totalSum){
        cout<<-1<<endl;
        return;
    }
    for(long long i=1;i<=n;i++){
        long long sumSoFar = (i*(i+1))/2;
        long long rootSum = sqrt(sumSoFar);
        if(rootSum*rootSum==sumSoFar){
            cout<<i+1<<" "<<i<<" ";
            i++;
        }
        else{
            cout<<i<<" ";
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

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}