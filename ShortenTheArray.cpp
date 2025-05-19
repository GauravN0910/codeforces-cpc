#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct TrieNode{
    TrieNode* children[2];
    int latestIdx;

    TrieNode(){
        children[0] = NULL;
        children[1] = NULL;
        latestIdx = -1;
    }
};

int find(TrieNode* root, int num, int k){
    TrieNode* node = root;
    int ans = -1;
    bool flag = true;

    for(int bit=29;flag && bit>=0;bit--){
        int xBit = (num>>bit)&1;
        int kBit = (k>>bit)&1;
        if(kBit == 1){
            if(node->children[xBit^1] != NULL){
                node = node->children[xBit^1];
            }
            else{
                flag = false;
            }
        }

        else{
            if(node->children[xBit^1] != NULL){
                ans = max(ans, node->children[xBit^1]->latestIdx);
            }
            if(node->children[xBit] != NULL){
                node = node->children[xBit];
            }
            else{
                flag = false;
            }
        }
    }

    if(flag){
        ans = max(ans, node->latestIdx);
    }
    return ans;
}

void add(TrieNode* root, int num, int idx){
    TrieNode* node = root;
    node->latestIdx = max(node->latestIdx, idx);

    for(int bit=29;bit>=0;bit--){
        int currBit = (num>>bit)&1;
        if(node->children[currBit] == NULL){
            node->children[currBit] = new TrieNode();
        }
        node = node->children[currBit];
        node->latestIdx = max(node->latestIdx, idx);
    }
}

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    TrieNode* trie = new TrieNode();
    int ans = n + 1;

    for(int i=0;i<n;i++){
        add(trie, nums[i], i);
        int idx = find(trie, nums[i], k);
        if(idx != -1){
            ans = min(ans, i - idx + 1);
        }
    }

    if(ans == n + 1){
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

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}