#include<bits/stdc++.h>
using namespace std;

bool solve(){
    int n, k;
    cin>>n>>k;
    vector<int> heights(n);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    int minHeight = heights[0];
    int maxHeight = heights[0];

    for(int i=1;i<n;i++){
        minHeight = max(heights[i], minHeight - k + 1);
        maxHeight = min(maxHeight + k - 1, heights[i] + k - 1);
        if(minHeight>maxHeight){
            return false;
        }
    }

    if(!(heights[n-1]>=minHeight && heights[n-1]<=maxHeight)){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        bool flag = solve();
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}