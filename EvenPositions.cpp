#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        s[0] = '(';
        for(int i=2;i<n-1;i+=2){
            if(s[i-1]=='('){
                s[i] = ')';
            }
            else{
                s[i] = '(';
            }
        }

        int ans = 0;
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                ans += i-stk.top();
                stk.pop();
            }
        }
        cout<<ans<<endl;
    }
}