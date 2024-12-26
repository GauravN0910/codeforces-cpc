#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<string> strings(n);
    for(int i=0;i<n;i++){
        cin>>strings[i];
    }

    string firstString = strings[0];
    for(int idx=0;idx<m;idx++){
        char temp = firstString[idx];
        for(char c='a';c<='z';c++){
            firstString[idx] = c;
            bool flag = true;  
            for(int i=0;i<n;i++){
                int diffCount = 0;
                for(int j=0;j<m;j++){
                    if(strings[i][j] != firstString[j]){
                        diffCount++;
                    }
                }
                if(diffCount>1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<firstString<<endl;
                return;
            }
        }
        firstString[idx] = temp;
    }
    cout<<-1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}