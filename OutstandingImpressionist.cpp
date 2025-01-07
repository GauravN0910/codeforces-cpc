#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;

    vector<pair<int, int>> impressions(n);
    map<int, int> freq;

    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        impressions[i] = {l, r};
        if(l==r){
            freq[l]++;
        }
    }

    vector<int> values;
    for(auto elem:freq){
        values.push_back(elem.first);
    }

    sort(values.begin(), values.end());

    string ans = "";

    for(auto [l, r]:impressions){
        if(l!=r){
            int lx = lower_bound(values.begin(), values.end(), l) - values.begin();
            int rx = upper_bound(values.begin(), values.end(), r) - values.begin();

            if(rx-lx < r-l+1){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }

        else{
            if(freq[l]==1){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
    }  
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}