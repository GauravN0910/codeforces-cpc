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

    int ans = 0;
    for(int i=0;i<n;i++){
        int targetValue = nums[i];
        vector<int> difference;
        int same = 0;
        for(int j=0;j<n;j++){
            if(nums[j]==targetValue){
                same++;
            }
            else if(nums[j]>targetValue){
                difference.push_back(nums[j] - targetValue);
            }
        }

        if(same>=n/2){
            cout<<-1<<endl;
            return;
        }

        map<int, int> count;
        for(auto val:difference){
            set<int> factor;
            for(int i=1;i*i<=val;i++){
                if(val%i==0){
                    factor.insert(val/i);
                    factor.insert(i);
                }
            }
            for(auto x:factor){
                count[x]++;
            }
            for(auto elem:count){
                if(elem.second + same >= n/2){
                    ans = max(ans, elem.first);
                }
            }
        }
    }
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