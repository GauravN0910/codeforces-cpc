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

    sort(nums.begin(), nums.end());

    int idx = -1;
    for(int i=n-1;i>=1;i--){
        if(nums[i]==nums[i-1]){
            idx = i-1;
            break;
        }
    }

    if(idx==-1){
        cout<<-1<<endl;
        return;
    }

    int side = nums[idx];
    vector<int> newSides;
    for(int i=0;i<n;i++){
        if(i!=idx && i!=idx+1){
            newSides.push_back(nums[i]);
        }
    }

    sort(newSides.begin(), newSides.end());

    if(newSides.size()<=1){
        cout<<-1<<endl;
        return;
    }
    else{
        int top = -1;
        int bottom = -1;
        int curSum = 2*side;
        bool flag = false;
        int sz = newSides.size();

        for(int i=1;i<sz;i++){
            int diff = newSides[i] - newSides[i-1];
            if(diff<curSum){
                top = newSides[i];
                bottom = newSides[i-1];
                flag = true;
                break;
            }
        }

        if(!flag){
            cout<<-1<<endl;
            return;
        }
        else{
            cout<<side<<" "<<side<<" "<<top<<" "<<bottom<<endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}