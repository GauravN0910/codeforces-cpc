#include<bits/stdc++.h>
using namespace std;

bool check(int sz, string s){
    int mismatch = 0;
    string x = s.substr(0, sz);
    for(int i=0;i<s.size();i++){
        if(x[i%sz] != s[i]){
            mismatch++;
        }
    }
    return mismatch<=1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = n;
        for(int i=1;i*i<=n;i++){
            if((n%i)==0){
                if(check(i, s)){
                    ans = min(ans, i);
                }
                if(check(n/i, s)){
                    ans = min(ans, n/i);
                }
            }
        }
        reverse(s.begin(), s.end());
        for(int i=1;i*i<=n;i++){
            if((n%i)==0){
                if(check(i, s)){
                    ans = min(ans, i);
                }
                if(check(n/i, s)){
                    ans = min(ans, n/i);
                }
            }
        }
        cout<<ans<<endl;
    }
}