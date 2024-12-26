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

    vector<long long> bits(20, 0);

    for(auto num:nums){
        for(long long bit=0;bit<20;bit++){
                if(num & (1<<bit)){
                    bits[bit]++;
                }
        }
    }

    long long ans = 0;

    while(true){
        bool flag = false;
        for(long long bit=0;bit<20;bit++){
            if(bits[bit]){
                flag = true;
                break;
            }
        }
        if(!flag){
            break;
        }

        long long num = 0;
        for(long long bit=0;bit<20;bit++){
            if(bits[bit]){
                num += (1<<bit);
                bits[bit]--;
            }
        }
        ans += num*num;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
    while(t--){
        solve();
    }
}