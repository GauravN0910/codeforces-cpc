#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int permA[200005];
int permB[200005];

map<int, int> indA;

void helperFn(int from, int to, vector<pair<int, int>>& ans){
    if(from==to){
        return;
    }

    ans.push_back({from, to});
    swap(permA[from], permA[to]);
    indA[permA[from]] = from;
    indA[permA[to]] = to;
    swap(permB[from], permB[to]);
}

void solve(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>permA[i];
        indA[permA[i]] = i;
    }
    for(int i=1;i<=n;i++){
        cin>>permB[i];
    }

    int matchIdx = 0;
    for(int i=1;i<=n;i++){
        if(permA[i] == permB[i]){
            if(n%2==0 || matchIdx){
                cout<<-1<<endl;
                return;
            }
            matchIdx = i;
        }
        else if(permB[indA[permB[i]]] != permA[i]){
            cout<<-1<<endl;
            return;
        }
    }

    vector<pair<int, int>> ans;

    if(n%2){
        helperFn(matchIdx, (n+1)/2, ans);
    }
    for(int i=1;i<=n/2;i++){
        helperFn(indA[permB[i]], n-i+1, ans);
    }

    cout<<ans.size()<<endl;
    for(auto [from, to]: ans){
        cout<<from<<" "<<to<<endl;
    }
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