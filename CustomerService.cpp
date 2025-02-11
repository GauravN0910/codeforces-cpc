#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<vector<long long>> queues(n, vector<long long>(n));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            cin>>queues[i][j];
        }
    }

    vector<long long> remainingPeople(n, 0);
    for(long long i=0;i<n;i++){
        long long count = 0;
        for(long long j=n-1;j>=0;j--){
            if(queues[i][j] == 1){
                count++;
            }
            else{
                break;
            }
        }
        remainingPeople[i] = count;
    }

    sort(remainingPeople.begin(), remainingPeople.end());
    long long res_mex = 0;
    for(int i=0;i<n;i++){
        if(remainingPeople[i]>=res_mex){
            res_mex++;
        }
    }

    cout<<res_mex<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}