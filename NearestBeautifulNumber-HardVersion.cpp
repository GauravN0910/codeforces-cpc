#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string n;
    int k;
    cin>>n>>k;

    while(true){
        set<char> digits;
        for(char c: n){
            digits.insert(c);
        }
        if(digits.size() <= k){
            cout<<n<<endl;
            return;
        }

        int idx = 0;
        digits.clear();
        while(idx<n.size()){
            digits.insert(n[idx]);
            if(digits.size() > k){
                while(n[idx]=='9'){
                    idx--;
                }
                n[idx]++;
                for(int i=idx+1;i<n.size();i++){
                    n[i] = '0';
                }
                break;
            }
            idx++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}