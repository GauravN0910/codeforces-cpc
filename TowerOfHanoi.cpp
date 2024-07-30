#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, char a, char b, char c, vector<pair<char, char>>& ans){
    if(n==0){
        return;
    }
    hanoi(n-1, a, c, b, ans);
    ans.push_back({a, b});
    hanoi(n-1, c, b, a, ans);
}

int main(){
    int n;
    cin>>n;
    vector<pair<char, char>> ans;
    hanoi(n, '1', '3', '2', ans);
    cout<<ans.size()<<endl;
    for(auto [x, y]:ans){
        cout<<x<<" "<<y<<endl;
    }
}