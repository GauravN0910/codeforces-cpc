#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int factor(int x){
    int ans=0;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            ans++;
            x/=i;
        }
    }
    if(x>1){
        ans++;
    }
    return ans;
}

void solve(){
    int a, b, k;
    cin>>a>>b>>k;
    
    if(a>b){
        swap(a, b);
    }

    int factA = factor(a);
    int factB = factor(b);

    int high = factA + factB;
    int low = (b%a==0 && a!=b)?1:2;
    
    if(low<=k && k<=high){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}