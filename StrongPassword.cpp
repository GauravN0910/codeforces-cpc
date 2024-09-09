#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n;
        n = s.size();
        string ans = "";
        int idx = -1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                idx = i;
                break;
            }
        }

        if(idx==-1){
            ans += (s[0] + 1)%26 + 'a';
            ans += s;
        }

        else{
            for(int i=0;i<=idx;i++){
                ans += s[i];
            }
            ans += (s[idx] + 1)%26 + 'a';
            for(int i=idx+1;i<n;i++){
                ans += s[i];
            }
        }
        cout<<ans<<endl;
    }
}