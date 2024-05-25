#include<bits/stdc++.h>
using namespace std;

void radixSort(vector<pair<pair<int, int>, int>>& a){
    int n = a.size();
    {
        vector<int> count(n);
        for(auto x:a){
            count[x.first.second]++;
        }
        vector<pair<pair<int, int>, int>> temp(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i=1;i<n;i++){
            pos[i] = pos[i-1] + count[i-1];
        }

        for(auto x:a){
            int y = x.first.second;
            temp[pos[y]] = x;
            pos[y]++;
        }
        a = temp;
    }
    {
        vector<int> count(n);
        for(auto x:a){
            count[x.first.first]++;
        }
        vector<pair<pair<int, int>, int>> temp(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i=1;i<n;i++){
            pos[i] = pos[i-1] + count[i-1];
        }

        for(auto x:a){
            int y = x.first.first;
            temp[pos[y]] = x;
            pos[y]++;
        }
        a = temp;
    }
}

int main(){
    string s;
    cin>>s;
    s += '$';
    int n =  s.size();

    vector<int> equiClass(n), index(n);
    {
        vector<pair<char, int>> a(n);
        for(int i=0;i<n;i++){
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for(int i=0;i<n;i++){
            index[i] = a[i].second;
        }
        equiClass[index[0]] = 0;
        for(int i=1;i<n;i++){
            if(a[i].first == a[i-1].first){
                equiClass[index[i]] = equiClass[index[i-1]];
            }
            else{
                equiClass[index[i]] = equiClass[index[i-1]] + 1;
            }
        }
    }

    int k=0;
    while((1<<k) < n){
        vector<pair<pair<int, int>, int>> a(n);
        for(int i=0;i<n;i++){
            a[i] = {{equiClass[i], equiClass[(i+(1<<k))%n]}, i};
        }
        radixSort(a);
        for(int i=0;i<n;i++){
            index[i] = a[i].second;
        }
        equiClass[index[0]] = 0;
        for(int i=1;i<n;i++){
            if(a[i].first == a[i-1].first){
                equiClass[index[i]] = equiClass[index[i-1]];
            }
            else{
                equiClass[index[i]] = equiClass[index[i-1]] + 1;
            }
        }
        k++;
    }

    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
}