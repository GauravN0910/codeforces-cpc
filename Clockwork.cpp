#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> clocks(n);
    for(int i=0;i<n;i++){
        cin>>clocks[i];
    }

    for(int i=0;i<n;i++){
        int left = i;
        int right = n - i - 1;
        int maxDistance = max(left, right);

        if(clocks[i]<=2*maxDistance){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}