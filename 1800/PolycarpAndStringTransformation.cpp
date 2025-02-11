#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;
    int n = s.size();

    string order = "";
    map<char, int> count;
    map<char, int> stringChars;
    for(int i=n-1;i>=0;i--){
        if(!count.count(s[i])){
            order += s[i];
        }
        count[s[i]]++;
    }

    int sz = order.size();
    int initialLength = 0;
    reverse(order.begin(), order.end());
    for(int i=0;i<sz;i++){
        int stepNum = i+1;
        initialLength += count[order[i]]/(stepNum);
        stringChars[order[i]] = count[order[i]]/(stepNum);
    }

    string initialString = s.substr(0, initialLength);
    
    
    string checkerString = initialString;
    string tempString = initialString;
    for(auto x:order){
        string nextTempString = "";
        for(auto y:tempString){
            if(x != y){
                checkerString += y;
                nextTempString += y;
            }
        }
        tempString = nextTempString;
    }

    if(checkerString != s){
        cout<<-1<<endl;
        return;
    }
    else{
        cout<<initialString<<" "<<order<<endl;
        return;
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