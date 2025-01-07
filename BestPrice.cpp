#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, k;
    cin>>n>>k;

    vector<long long> positive(n);
    vector<long long> negative(n);

    for(int i=0;i<n;i++){
        cin>>positive[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>negative[i];
    }

    long long ans = 0;

    vector<long long> allVals;
    for(int i=0;i<n;i++){
        allVals.push_back(positive[i]);
        allVals.push_back(negative[i]);
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    
    for(auto val:allVals){
        long long upperLimit = lower_bound(positive.begin(), positive.end(), val) - positive.begin();
        long long lowerLimit = lower_bound(negative.begin(), negative.end(), val) - negative.begin();
        long long numBadReviews = upperLimit - lowerLimit;

        if(k>=numBadReviews){
            ans = max(ans, (n-lowerLimit)*val);
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}