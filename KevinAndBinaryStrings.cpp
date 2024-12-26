#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;

    int n = s.size();
    cout<<1<<" "<<n<<" ";

    int firstZeroIdx = -1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            firstZeroIdx = i;
            break;
        }
    }

    if(firstZeroIdx==-1){
        cout<<n<<" "<<n<<endl;
        return;
    }
    else{
        int remainingLen = n - firstZeroIdx;
        int l2 = 1;
        int r2 = remainingLen;
        string ansString = "";
        string remainingString = s.substr(firstZeroIdx, remainingLen);
        for(int i=0;i<=firstZeroIdx;i++){
            string x = s.substr(i, remainingLen);
            string tempString = "";
            for(int idx=0;idx<remainingLen;idx++){
                if(x[idx]==remainingString[idx]){
                    tempString += '0';
                }
                else{
                    tempString += '1';
                }
            }
            if(tempString>ansString){
                ansString = tempString;
                l2 = i+1;
                r2 = l2 + remainingLen - 1;
            }
        }
        cout<<l2<<" "<<r2<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}