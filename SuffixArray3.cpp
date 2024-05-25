#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& index, vector<int>& equiClass){
    int n = index.size();
    vector<int> count(n);
    for(auto x:equiClass){
        count[x]++;
    }
    vector<int> temp(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i=1;i<n;i++){
        pos[i] = pos[i-1] + count[i-1];
    }

    for(auto x:index){
        int y = equiClass[x];
        temp[pos[y]] = x;
        pos[y]++; 
    }

    index = temp;
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
        for(int i=0;i<n;i++){
            index[i] = (index[i] - (1<<k) + n) % n;
        }

        counting_sort(index, equiClass);
        vector<int> equi_new(n);
        equi_new[index[0]] = 0;
        for(int i=1;i<n;i++){
            pair<int, int> prev = {equiClass[index[i-1]], equiClass[(index[i-1] + (1<<k))%n]};
            pair<int, int> curr = {equiClass[index[i]], equiClass[(index[i] + (1<<k))%n]};
            if(prev==curr){
                equi_new[index[i]] = equi_new[index[i-1]];
            }
            else{
                equi_new[index[i]] = equi_new[index[i-1]] + 1;
            }
        }
        equiClass = equi_new;
        k++;
    }

    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    cout<<endl;
}