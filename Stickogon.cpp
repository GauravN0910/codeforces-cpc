#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        map<int, int> count;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            count[x]++;
        }

        int ans = 0;
        for(auto elem:count){
            ans += elem.second/3;
        }
        cout<<ans<<endl;
    }
}