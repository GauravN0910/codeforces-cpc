#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

bool contains7(long long n){
    string stringN = to_string(n);
    for(auto x:stringN){
        if(x=='7'){
            return true;
        }
    }
    return false;
}

void solve(){
    long long n;
    cin>>n;
    long long ans = 1e18;
    long long tempN = n;
    long long curNum = 9;
    for(long long i=0;i<10;i++){
        for(long long curAns=0;curAns<=10;curAns++){
            if(contains7(n)){
                ans = min(ans, curAns);
                break;
            }
            n += curNum;
        }
        curNum = (curNum*10) + 9;
        n = tempN;
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