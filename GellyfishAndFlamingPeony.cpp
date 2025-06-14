#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int gcdVal = nums[0];
    for (int i = 1; i < n; i++) {
        gcdVal = __gcd(gcdVal, nums[i]);
    }

    int numGCD = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == gcdVal) {
            numGCD++;
        }
    }
    if (numGCD) {
        cout<<(n - numGCD)<<endl;
        return;
    }

    vector<bool> visited(5001, false);
    vector<int> uniqueNums;
    for (int x : nums) {
        if (!visited[x]) {
            visited[x] = true;
            uniqueNums.push_back(x);
        }
    }

    vector<int> depth(5001, 1e9);
    queue<int> q;
    for (int x : uniqueNums) {
        depth[x] = 0;
        q.push(x);
    }

    int ans = 0;
    while (!q.empty()) {
        int val = q.front();
        q.pop();
        for (int next : uniqueNums) {
            int nextVal = __gcd(val, next);
            if (depth[nextVal] > depth[val] + 1) {
                depth[nextVal] = depth[val] + 1;
                if (nextVal == gcdVal) {
                    ans = depth[nextVal];
                    cout<<ans + (n-1)<<endl;
                    return;
                }
                q.push(nextVal);
            }
        }
    }
    ans = ans + (n-1);
    cout<<ans<<endl;
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