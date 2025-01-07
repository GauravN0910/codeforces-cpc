#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long binExp(long long n, long long pow){
    if(pow==0){
        return 1;
    }
    long long ans = binExp(n, pow/2);
    if(pow%2){
        return ((ans*ans)%mod * n)%mod;
    }
    return (ans*ans)%mod;
}

void solve(){
    long long n, q;
    cin>>n>>q;

    vector<long long> A(n);
    vector<long long> B(n);

    for(long long i=0;i<n;i++){
        cin>>A[i];
    }

    for(long long i=0;i<n;i++){
        cin>>B[i];
    }

    vector<long long> ACopy = A;
    vector<long long> BCopy = B;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long prevAns = 1;
    for(long long i=0;i<n;i++){
        prevAns = (prevAns * min(A[i], B[i]))%mod;
    }
    cout<<prevAns<<" ";

    for(long long i=0;i<q;i++){
        long long type;
        cin>>type;
        long long x;
        cin>>x;
        
        if(type==1){
            long long numForSearch = ACopy[x-1];
            long long idx = upper_bound(A.begin(), A.end(), numForSearch) - A.begin() - 1;
            long long curAns = (prevAns*binExp(min(A[idx], B[idx]), mod-2))%mod;
            ACopy[x-1] += 1;
            A[idx] += 1;
            curAns = (curAns * min(A[idx], B[idx]))%mod;
            prevAns = curAns;
            cout<<curAns<<" ";
        }
        else if(type==2){
            long long numForSearch = BCopy[x-1];
            long long idx = upper_bound(B.begin(), B.end(), numForSearch) - B.begin() - 1;
            long long curAns = (prevAns*binExp(min(A[idx], B[idx]), mod-2))%mod;
            BCopy[x-1] += 1;
            B[idx] += 1;
            curAns = (curAns * min(A[idx], B[idx]))%mod;
            prevAns = curAns;
            cout<<curAns<<" ";
        }
    }
    
    cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}