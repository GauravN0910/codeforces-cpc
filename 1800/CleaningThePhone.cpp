#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

static bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve(){
    long long n, m;
    cin>>n>>m;
    vector<long long> memory(n);
    vector<long long> convenience(n);

    for(long long i=0;i<n;i++){
        cin>>memory[i];
    }
    long long oneCount = 0;
    for(long long i=0;i<n;i++){
        cin>>convenience[i];
        if(convenience[i] == 1){
            oneCount++;
        }
    }

    vector<pair<long long, long long>> phone(n);
    for(long long i=0;i<n;i++){
        phone[i] = {convenience[i], memory[i]};
    }

    sort(phone.begin(), phone.end(), cmp);

    long long twoSum = 0;
    long long oneSum = 0;
    for(long long i=oneCount;i<n;i++){
        twoSum += phone[i].second;
    }

    long long right = n-1;
    long long ans = 1e18;
    long long left = 0;
    for(left=0;left<oneCount;left++){
        while(right>=oneCount && twoSum + oneSum - phone[right].second >= m){
            twoSum -= phone[right].second;
            right--;
        }
        if(twoSum + oneSum >= m){
            ans = min(ans, left + 2*(right - oneCount + 1));
        }
        oneSum += phone[left].second;
    }

    while(right>=oneCount && twoSum + oneSum - phone[right].second >= m){
        twoSum -= phone[right].second;
        right--;
    }
    if(twoSum + oneSum >= m){
        ans = min(ans, left + 2*(right - oneCount + 1));
    }
    
    if(ans == 1e18){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;   
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}