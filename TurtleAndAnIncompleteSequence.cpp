#include<bits/stdc++.h>
using namespace std;

bool check(long long a, long long b){
    for(int i=0;i<32;i++){
        if((b>>i)==a)return true;
    }
    return false;
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    long long i = 0;
    while(i<n && nums[i]==-1) i++;
    long long j=i+1;
    while(j<n && nums[j]==-1) j++;

    if(i==n){
        for(int i=0;i<n;i++){
            nums[i] = 1;
			if(i%2==0)nums[i]++;
        }
    }
    else{
        for(int k=i-1;k>=0;k--){
            if(nums[k+1] == 1){
                nums[k] = 2;
            }
            else{
                nums[k] = nums[k+1]>>1;
            }
        }
        for(;i<n;i++){
            if(i==j) j++;
            while(j<n && nums[j]==-1) j++;

            if(j==n){
                if(i+1<n){
                    if(nums[i]==1){
                        nums[i+1]=2;
                    }
                    else{
                        nums[i+1] = nums[i]>>1;
                    }
                }
            }
            else{
                if(i+1<j){
                    if(!check(nums[i], nums[j])){
                        nums[i+1] = nums[i]>>1;
                    }
                    else{
                        if(nums[i]==nums[j]){
                            nums[i+1] = nums[i] << 1;
                        }
                        else{
                            if(check((nums[i]<<1)+1, nums[j])){
                                nums[i+1] = (nums[i]<<1)+ 1;
                            }
                            else{
                                nums[i+1] = (nums[i]<<1);
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<n-1;i++){
        if((nums[i+1] == nums[i]/2) || (nums[i] == (nums[i+1]/2))){
		}
        else{
            cout<<"-1"<<endl;
            return;
        }
    }

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}