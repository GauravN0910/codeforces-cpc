#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long fact[11];

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long minPerms = LLONG_MAX;

    string ans = s;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string temp = s;
            temp[i] = temp[j];

            
            map<char, int> map;
            for(int i=0;i<n;i++){
                map[temp[i]]++;
            }

            long long permutations = fact[n];

            for(char c='a';c<='z';c++){
                if(map.count(c)){
                    permutations /= fact[map[c]];
                }
            }

            if(permutations < minPerms){
                minPerms = permutations;
                ans = temp;
            }

        }
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0]=1;
    for(int i=1;i<=10;i++){
        fact[i]=fact[i-1]*i;
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


