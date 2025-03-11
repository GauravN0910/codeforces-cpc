#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<char> leftOperations(n), rightOperations(n);
    vector<long long> leftValues(n), rightValues(n);
    for(long long i=0; i<n; i++){
        cin>>leftOperations[i]>>leftValues[i]>>rightOperations[i]>>rightValues[i];
    }

    long long x = 1;
    long long y = 1;
    long long z = 0;

    for(long long i=n-1;i>=0;i--){
        long long leftMul = 0;
        long long leftAdd = 0;
        long long rightMul = 0;
        long long rightAdd = 0;

        if(leftOperations[i] == 'x'){
            leftMul = leftValues[i] - 1;
        }
        else{
            leftAdd = leftValues[i];
        }

        if(rightOperations[i] == 'x'){
            rightMul = rightValues[i] - 1;
        }
        else{
            rightAdd = rightValues[i];
        }

        long long a, b, c;
        long long totalAdd = leftAdd + rightAdd;
        if(y>=x){
            a = x + y*leftMul;
            b = y + y*rightMul;
            c = z + y*totalAdd;
            x = a; y = b; z = c;
        }
        else{
            a = x*leftMul + x;
            b = x*rightMul + y;
            c = z + x*totalAdd;
            x = a; y = b; z = c;
        }
    }
    cout<<x+y+z<<endl;
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