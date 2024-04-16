#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<string, string> map = {{"00","12"}, {"01","01"},{ "02","02"}, {"03","03"}, {"04","04"}, {"05","05"}, {"06","06"}, {"07","07"},
                                {"08","08"},{ "09","09"}, {"10","10"}, {"11","11"}, {"12","12"}, {"13","01"}, {"14","02"}, {"15","03"},
                                {"16","04"}, {"17","05"}, {"18","06"}, {"19","07"}, {"20","08"}, {"21","09"}, {"22","10"}, {"23","11"}};

        string ans = "";
        string hour = map[s.substr(0,2)];
        string minute = s.substr(3,2);
        ans = hour + ":" + minute;
        if(stoi(s.substr(0,2))>=12){
            ans += " PM";
        }
        else{
            ans += " AM";
        }
        cout<<ans<<endl;
    }
}