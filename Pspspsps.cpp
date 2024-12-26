#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(s[0]=='s'){
        s[0] = '.';
    }

    if(s[n-1]=='p'){
        s[n-1] = '.';
    }

    bool foundS = false;
    bool foundP = false;

    for(int i=0;i<n;i++){
        if(s[i]=='s'){
            foundS = true;
        }
        if(s[i]=='p'){
            foundP = true;
        }
    }

    if(foundS && foundP){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}