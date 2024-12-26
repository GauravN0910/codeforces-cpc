#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    set<int> used;
    vector<int> nums(n);
    vector<int> ans(n);
    int randElem = 1;

    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(used.find(nums[i])==used.end()){
            ans[i] = nums[i];
            used.insert(nums[i]);
        }
        else{
            while(used.find(randElem)!=used.end()){
                randElem++;
            }
            ans[i] = randElem;
            used.insert(randElem);
            randElem++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}