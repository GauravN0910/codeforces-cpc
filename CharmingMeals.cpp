#include<bits/stdc++.h>
using namespace std;

int minDiff(vector<int>& app, vector<int>& main, int n, int shift){
    int min_diff = INT_MAX;
    for(int i=0;i<n;i++){
        min_diff = min(min_diff, abs(app[i] - main[(i+shift)%n]));
    }
    return min_diff;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> app(n);
        vector<int> main(n);

        for(int i=0;i<n;i++){
            cin>>app[i];
        }

        for(int i=0;i<n;i++){
            cin>>main[i];
        }

        sort(app.begin(), app.end());
        sort(main.begin(), main.end());

        int ans = 0;
        for(int shift=0; shift<n;shift++){
            ans = max(ans, minDiff(app, main, n, shift));
        }   
        cout<<ans<<endl;
    }
}