#include<bits/stdc++.h>
using namespace std;

long long factorial[10];

const long long mod = 1e9 + 7;

void solve(){
    long long n, d;
    cin>>n>>d;

    vector<long long> ans;
    if(n>=7){
        ans.push_back(1);
        ans.push_back(3);
        if(d==5){
            ans.push_back(5);
        }
        ans.push_back(7);
        ans.push_back(9);
    }

    else{
        long long numSum = factorial[n] * d;
        ans.push_back(1);
        if(numSum%3==0){
            ans.push_back(3);
        }
        if(d==5){
            ans.push_back(5);
        }

        long long remainder = 0;
        for(long long i=0;i<factorial[n];i++){
            long long num = remainder*10 + d;
            remainder = num%7;
        }

        if(remainder==0){
            ans.push_back(7);
        }

        if(numSum%9==0){
            ans.push_back(9);
        }
    }

    for(auto val:ans){
        cout<<val<<" ";
    }
    cout<<endl;
}   

int main(){
    factorial[0] = 1;
    for(long long i=1;i<=9;i++){
        factorial[i] = i * factorial[i-1];
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}