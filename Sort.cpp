#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        string a, b;
        cin>>a>>b;
        vector<vector<int>> prefixSumA(n+1, vector<int>(26, 0));
        vector<vector<int>> prefixSumB(n+1, vector<int>(26, 0));

        for(int i=1;i<=n;i++){
            prefixSumA[i] = prefixSumA[i-1];
            prefixSumB[i] = prefixSumB[i-1];
            int ch = a[i-1] - 'a';
            prefixSumA[i][ch] = prefixSumA[i-1][ch] + 1;
            ch = b[i-1] - 'a';
            prefixSumB[i][ch] = prefixSumB[i-1][ch] + 1;
        }

        while(q--){
            int l, r;
            cin>>l>>r;
            int mismatchCount = 0;
            for(int i=0;i<26;i++){
                int charCountA = prefixSumA[r][i] - prefixSumA[l-1][i];
                int charCountB = prefixSumB[r][i] - prefixSumB[l-1][i];
                mismatchCount += abs(charCountA - charCountB);
            }
            int ans = mismatchCount/2;
            cout<<ans<<endl;
        }
    }
}