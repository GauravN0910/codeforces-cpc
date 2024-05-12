#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, vector<long long>& counts, long long n, long long k){
    long long res = 0;
    for(int i=1;i<=n;i++){
        res += max(0ll, mid-counts[i]);
    }
    return res<=k;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        vector<long long> counts(n+1);
        for(long long i=1;i<=n;i++){
            cin>>counts[i];
        }

        long long low = 0;
        long long high = 2*1e12;
        long long x;

        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(mid, counts, n, k)){
                x = mid;
                low = mid+1;
            }
            else{
                high = mid-1;    
            }
        }

        long long ans = x*n - (n-1);
        for(int i=1;i<=n;i++){
            if(counts[i]>x){
                ans++;
            }
            else{
                k -= (x-counts[i]);
            }
        }
        cout<<ans+k<<endl;
    }
}