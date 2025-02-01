#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, l, r;
    cin>>n>>l>>r;
    priority_queue<long long, vector<long long>, greater<long long>> left;
    priority_queue<long long> segmentL, segmentR;
    priority_queue<long long, vector<long long>, greater<long long>> right;
    for(long long i=1;i<=n;i++){
        long long x;
        cin>>x;
        if(i<l){
            left.push(x);
        }
        else if(i>r){
            right.push(x);
        }
        else{
            segmentL.push(x);
            segmentR.push(x);
        }
    }

    long long ans = 1e18;
    long long sum = 0;

    while(!left.empty() && !segmentL.empty()){
        long long leftTop = left.top();
        long long segTop = segmentL.top();
        if(leftTop<segTop){
            sum += leftTop;
            left.pop();
            segmentL.pop();
        }
        else{
            break;
        }
    }

    while(!segmentL.empty()){
        long long top = segmentL.top();
        segmentL.pop();
        sum += top;
    }

    ans = min(ans, sum);

    sum = 0;
    while(!right.empty() && !segmentR.empty()){
        long long rightTop = right.top();
        long long segTop = segmentR.top();
        if(rightTop<segTop){
            sum += rightTop;
            right.pop();
            segmentR.pop();
        }
        else{
            break;
        }
    }

    while(!segmentR.empty()){
        long long top = segmentR.top();
        segmentR.pop();
        sum += top;
    }
    ans = min(ans, sum);
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