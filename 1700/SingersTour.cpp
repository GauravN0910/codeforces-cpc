#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> concertTime(n);
    long long sum = 0;
    for(long long i=0;i<n;i++){
        cin>>concertTime[i];
        sum += concertTime[i];
    }

    if((sum % (n*(n+1)/2)) != 0){
        cout<<"NO"<<endl;
        return;
    }

    sum /= (n*(n+1)/2);

    vector<long long> ans(n);

    long long firstVal = sum;

    for(long long i=1;i<n;i++){
        long long x = (sum + concertTime[i-1] - concertTime[i]);
        if(x%n!=0 || x<=0){
            cout<<"NO"<<endl;
            return;
        }
        x /= n;
        ans[i] = x;
        firstVal -= x;
    }

    ans[0] = firstVal;

    for(long long i=0;i<n;i++){
        if(ans[i]<=0 || ans[i]>1e9){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

    for(long long i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}