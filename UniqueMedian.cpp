#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    long long ans = (n*(n+1))/2;

    for(long long x=1;x<=10;x++){
        for(long long y=x+1;y<=10;y++){
            vector<long long> prefixSum(n, 1e9);
            for(long long i=0;i<n;i++){
                if(nums[i]<=x){
                    prefixSum[i] = -1;
                }
                else if(nums[i]>=y){
                    prefixSum[i] = 1;
                }
            }

            for(long long i=1;i<n;i++){
                prefixSum[i] += prefixSum[i-1];
            }

            map<long long, long long> count;

            long long xIdx = -1;
            long long yIdx = -1;
            long long idx = -1;
            for(long long i=0;i<n;i++){
                if(nums[i]==x){
                    xIdx = i;
                }
                if(nums[i]==y){
                    yIdx = i;
                }

                while(idx<min(xIdx, yIdx)){
                    if(idx==-1){
                        count[0]++;
                    }
                    else{
                        count[prefixSum[idx]]++;
                    }
                    idx++;
                }
                
                ans -= count[prefixSum[i]];
            }
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