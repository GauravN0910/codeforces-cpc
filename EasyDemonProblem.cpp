#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, m, q;
    cin>>n>>m>>q;
    long long sumA = 0;
    long long sumB = 0;
    vector<long long> numsA(n);
    vector<long long> numsB(m);
    map<long long, long long> mapA;
    map<long long, long long> mapB;
    
    for(long long i=0;i<n;i++){
        cin>>numsA[i];
        sumA += numsA[i];
    }

    for(long long i=0;i<m;i++){
        cin>>numsB[i];
        sumB += numsB[i];
    }

    for(long long i=0;i<n;i++){
        mapA[sumA - numsA[i]]++;
    }

    for(long long i=0;i<m;i++){
        mapB[sumB - numsB[i]]++;
    }

    while(q--){
        long long x;
        cin>>x;
        bool flag = false;
        for(long long factor=1;factor*factor<=abs(x);factor++){
            if(x%factor==0){
                if(x>0){
                    if((mapA.count(factor) && mapB.count(abs(x)/factor)) || (mapB.count(factor) && mapA.count(abs(x)/factor)) ||
                    (mapA.count(-1*factor) && mapB.count(-1*abs(x)/factor)) || (mapB.count(-1*factor) && mapA.count(-1*abs(x)/factor))){
                        flag = true;
                        cout<<"YES"<<endl;
                        break;
                    }
                }
                else{
                    if((mapA.count(factor) && mapB.count(-1*abs(x)/factor)) || (mapB.count(-1*factor) && mapA.count(abs(x)/factor)) ||
                    (mapA.count(-1*factor) && mapB.count(abs(x)/factor)) || (mapB.count(factor) && mapA.count(-1*abs(x)/factor))){
                        flag = true;
                        cout<<"YES"<<endl;
                        break;
                    }
                }
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
    while(t--){
        solve();
    }
}