#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> diff(2*n);
    for(long long i=0;i<2*n;i++){
        cin>>diff[i];
    }

    sort(diff.begin(), diff.end());

    vector<long long> nums(n);

    for(long long i=0;i<n;i++){
        if(diff[2*i] != diff[2*i + 1]){
            cout<<"NO"<<endl;
            return;
        }
        nums[i] = diff[2*i];
    }

    for(long long i=1;i<n;i++){
        if(nums[i]==nums[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    long long flag = true;
    long long sum = 0;
    for(long long i=n-1;i>=0;i--){
        nums[i] -= sum;
        if(nums[i]>0 && nums[i]%(2*(i+1))==0){
            long long aVal = nums[i]/(2*(i+1));
            sum += 2*aVal;
        }
        else{
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}