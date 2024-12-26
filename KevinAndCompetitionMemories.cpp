#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, m;
    cin>>n>>m;

    vector<long long> ratings(n);
    vector<long long> problems(m);
    long long totalKevinSolvable = 0;

    for(long long i=0;i<n;i++){
        cin>>ratings[i];
    }
    long long kevinRating = ratings[0];

    for(long long i=0;i<m;i++){
        cin>>problems[i];
        if(problems[i]<=kevinRating){
            totalKevinSolvable++;
        }
    }
    sort(problems.begin(), problems.end());
    sort(ratings.begin(), ratings.end());
    
    
    for(long long k=1;k<=m;k++){
        long long ans = 0;
        long long numContest = m/k;
        long long problemsUsed = numContest * k;

        long long remaining = problemsUsed - totalKevinSolvable;
        long long tempSolvable = totalKevinSolvable;
        long long remainingStartIdx = m - remaining;

        ans += tempSolvable/k;
        tempSolvable = tempSolvable % k;

        while(remainingStartIdx<m){
            long long probDifficulty = problems[remainingStartIdx];
            long long rank = lower_bound(ratings.begin(), ratings.end(), probDifficulty) - ratings.begin();
            rank = n - rank;
            rank++;
            remainingStartIdx += k;
            ans += rank;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}