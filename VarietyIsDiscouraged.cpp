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

    map<int, int> count;
    for(int i=0;i<n;i++){
        count[nums[i]]++;
    }

    vector<bool> isUnique(n, false);
    for(int i=0;i<n;i++){
        if(count[nums[i]]==1){
            isUnique[i] = true;
        }
    }

    int ans = 0;
    int leftAns = -1;
    int rightAns = -1;
    int start = -1;
    for(int i=0;i<n;i++){
        if(isUnique[i]){
            if(start==-1){
                start = i;
            }
        }
        else{
            if(start!=-1){
                int curLen = i - start;
                if(curLen>ans){
                    ans = curLen;
                    leftAns = start;
                    rightAns = i - 1;
                }
                start = -1;
            }
        }
    }
    if(start!=-1){
        int curLen = n - start;
        if(curLen>ans){
            ans = curLen;
            leftAns = start;
            rightAns = n - 1;
        }
    }

    if(ans>0){
        cout<<leftAns + 1<<" "<<rightAns+1<<endl;
    }
    else{
        cout<<0<<endl;
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