#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    long long sum = 0;
    vector<long long> nums(n);
    map<long long, long long> map;
    priority_queue<long long> pq;

    for(long long i=0;i<n;i++){
        cin>>nums[i];
        map[nums[i]]++;
    }

    for(long long i=0;i<=n;i++){
        cout<<max(-1LL, map[i] + sum)<<" ";
        while(map[i]){
            map[i]--;
            pq.push(i);
        }
        if(!pq.empty()){
            sum += i-pq.top();
            pq.pop();
        }
        else{
            sum = -1e18;
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
