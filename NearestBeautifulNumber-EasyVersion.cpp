#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

string solveK1(string& n){
    int len = n.size();
    string ans(len, '9');
    for(int i=8;i>=1;i--){
        string x(len, i + '0');
        if(x>=n){
            ans = x;
        }
    }
    return ans;
}

string solveK2(string& n){
    string ans = solveK1(n);
    int len = n.size();
    
    for(char x='0';x<='9';x++){
        for(char y=x+1;y<='9';y++){
            bool flag = true;
            for(int i=0;i<len;i++){
                if(n[i]<y){
                    string t = n;
                    if(t[i]<x){
                        t[i] = x;
                    }
                    else{
                        t[i] = y;
                    }

                    for(int idx=i+1;idx<len;idx++){
                        t[idx] = x;
                    }

                    if(ans>t){
                        ans = t;
                    }
                }

                if(n[i]!=x && n[i]!=y){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return n;
            }
        }
    }
    return ans;
}

void solve(){
	string n;
    int k;
	cin>>n>>k;
    
    if(k==1){
        cout<<solveK1(n)<<endl;
        return;
    }
    cout<<solveK2(n)<<endl;
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
