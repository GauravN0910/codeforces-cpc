#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int sumXY = (nums[0] + nums[n-1])/(n+1);
    int diffYX = (nums[0] - nums[n-1])/(n-1);

    int Y = (sumXY + diffYX)/2;
    int X = sumXY - Y;
    
    if(X<0 || Y<0){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        int result = X*(i+1) + Y*(n-i);
        if(nums[i]!=result){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    return;
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