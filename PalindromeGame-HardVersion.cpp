#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool isPalindrome(string s){
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zeroCount = 0;
    for(auto c: s){
        if(c == '0'){
            zeroCount++;
        }
    }
    
    int flag = isPalindrome(s);
    int quotient = zeroCount / 2;
    if(flag){
        if(zeroCount % 2 == 0 || zeroCount == 1){
            cout<<"BOB"<<endl;
        }
        else{
            cout<<"ALICE"<<endl;
        }
        return;
    }

    if(zeroCount == 2 && n%2 && s[n/2] == '0'){
        cout<<"DRAW"<<endl;
        return;
    }
    cout<<"ALICE"<<endl;
    return;
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