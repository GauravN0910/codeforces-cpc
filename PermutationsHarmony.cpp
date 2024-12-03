#include<bits/stdc++.h>
using namespace std;

int fact[8] = {1,1,2,6,24,120,720,5040};

void solve(){
    int n, k;
    cin>>n>>k;

    if(min(n, k)==1){
        if(n*k==1){
            cout<<"YES"<<endl;
            cout<<1<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }

    else if(n<8 && (k>fact[n] || fact[n]==k+1)){
        cout<<"NO"<<endl;
        return;
    }

    else if((n%2==0 && k%2)){
        cout<<"NO"<<endl;
        return;
    }

    else{
        vector<vector<int>> usedPerms;
        vector<vector<int>> allPermutations;
        vector<int> permutation(n);
        for(int i=0;i<n;i++){
            permutation[i]=i+1;
        }

        if(k%2){
            int colSum = (n+1)*3/2;
            int q = n/2;
            vector<int> perm2(n, q+1), perm3(n, n);

            for(int i=1;i<n;i++){
                perm2[i] = perm3[i-1];
                perm3[i] = colSum - permutation[i] - perm2[i];
            }
            allPermutations = usedPerms = {permutation, perm2, perm3};
            k-=3;
        }

        while(k){
            vector<int> inversePerm(n);
            for(int i=0;i<n;i++){
                inversePerm[i] = n + 1 - permutation[i];
            }
            bool flag = false;
            for(auto perm:usedPerms){
                flag |= (perm==permutation);
                flag |= (perm==inversePerm);
            }

            if(!flag){
                allPermutations.push_back(permutation);
                allPermutations.push_back(inversePerm);
                k-=2;
            }
            next_permutation(permutation.begin(), permutation.end());
        }
        cout<<"YES"<<endl;
        for(auto perm:allPermutations){
            for(auto x:perm){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}