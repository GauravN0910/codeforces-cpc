#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        bool letter = false;
        bool valid = true;

        int lastNumIdx = -1;

        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9' && !letter){
                lastNumIdx = i;
            }
            else if(s[i]>='0' && s[i]<='9' && letter){
                valid = false;
                break;
            }
            else if(s[i]>='a' && s[i]<='z'){
                letter = true;
            }
            else{
                valid = false;
                break;
            }
        }

        if(valid){
            string nums = s.substr(0, lastNumIdx+1);
            string chars = s.substr(lastNumIdx+1, n-lastNumIdx+1);

            string sortedNums = nums;
            sort(sortedNums.begin(), sortedNums.end());
            string sortedChars = chars;
            sort(sortedChars.begin(), sortedChars.end());

            if(nums!=sortedNums || chars!=sortedChars){
                valid = false;
            }
        }

        if(valid){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
}