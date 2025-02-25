#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    
    int nPower3 = 1;
    for(int i=1;i<=n;i++){
        nPower3 = (nPower3*3);
    }

    /*Mask in Base 3 - To choose from multipliers -1, 0 and 1*/
    for(int mask=1;mask<nPower3;mask++){
        int sum = 0;
        int temp = mask;
        for(int idx=1;idx<=n;idx++){
            int sign = temp % 3;
            temp = temp/3;
            if(sign==2){
                sign = -1;
            }
            sum += sign*nums[idx];
        }
        if(sum==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}