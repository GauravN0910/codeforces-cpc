#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<int> a(n+1);
        vector<int> b(m+1);
        map<int, int> count;
        map<int, int> idx;

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
            count[b[i]]++;
            idx[b[i]]=i;
        }
        
        int ans = 0;
        int cnt = 0;
        for(int i=n;i>=n-m+1;i--){
            count[a[i]]--;
            if(count[a[i]]>=0 && idx[a[i]]>=1 && idx[a[i]]<=m){
                cnt++;
            }
        }

        if(cnt>=k){
            ans++;
        }

        for(int i=n-m;i>=1;i--){
            count[a[i]]--;
            if(count[a[i]]>=0 && idx[a[i]]>=1 && idx[a[i]]<=m){
                cnt++;
            }
            count[a[i+m]]++;
            if(count[a[i+m]]>0 && idx[a[i+m]]>=1 && idx[a[i+m]]<=m){
                cnt--;
            }
            if(cnt>=k){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}