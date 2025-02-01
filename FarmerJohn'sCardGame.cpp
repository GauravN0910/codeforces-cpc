#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> cards(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cards[i][j];
        }
    }

    for(auto& cowCardSet:cards){
        sort(cowCardSet.begin(), cowCardSet.end());
    }

    for(auto cowCardSet:cards){
        for(int i=1;i<m;i++){
            if(cowCardSet[i] - cowCardSet[i-1] != n){
                cout<<-1<<endl;
                return;
            }
        }
    }

    vector<int> cowOrder(n);
    for(int i=0;i<n;i++){
        vector<int> cowCardSet = cards[i];
        int firstCard = cowCardSet[0];
        cowOrder[firstCard] = i;
    }

    for(int i=0;i<n;i++){
        cout<<cowOrder[i]+1<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}