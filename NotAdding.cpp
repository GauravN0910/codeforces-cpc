#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


void solve(){
    int n;
    cin>>n;
    
    vector<int> nums(n);
    int maxNum = 1;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        maxNum = max(maxNum, nums[i]);
    }

        
    vector<bool> present(maxNum + 10, 0);
    for(int i=0;i<n;i++){
        present[nums[i]] = 1;
    }

    int ans = 0;
    for(int i=1;i<=maxNum;i++){
        int gcdVal = 0;
        for(int j=i;j<=maxNum;j+=i){
            if(present[j]){
                gcdVal = __gcd(gcdVal, j);
            }
        }
        ans += (gcdVal == i);
    }

    cout<<ans - n<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}