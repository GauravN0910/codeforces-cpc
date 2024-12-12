#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;

    int n = s.size();
    vector<int> digits(n);

    for(int i=0;i<n;i++){
        digits[i] = s[i]-'0';
    }

    for(int i=1;i<n;i++){
        while(i>=1 && digits[i] > digits[i-1] + 1 && digits[i] > 0){
            swap(digits[i], digits[i-1]);
            digits[i-1]--;
            if(i>1){
                i--;
            }
            else{
                break;
            }
        }
    }

    string ans = "";
    for(int i=0;i<n;i++){
        ans += (digits[i]+'0');
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