#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool intersect(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first){
        swap(a, b);
    }
    return a.second>b.first && a.second<b.second;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> chords;
    vector<bool> visited(2*n+1, false);
    for(int i=0;i<k;i++){
        int x, y;
        cin>>x>>y;
        if(x > y) swap(x, y);
        visited[x] = 1;
        visited[y] = 1;
        chords.push_back({x, y});
    }

    vector<int> notVisited;
    for(int i=1;i<=2*n;i++){
        if(!visited[i]){
            notVisited.push_back(i);
        }
    }

    int remainingChords = n - k;
    for(int i=0;i<remainingChords;i++){
        chords.push_back({notVisited[i], notVisited[i+remainingChords]});
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(intersect(chords[i], chords[j])){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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