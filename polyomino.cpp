#include<iostream>
using namespace std;
int main(){ //1343
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st,sol="";
    cin>>st;
    int cnt=0;
    for(int i=0; i<=st.length(); ++i){
        if(i==st.length()){
            if(cnt==4) sol+="AAAA";
            else if(cnt==2) sol+="BB";
            else if(cnt==0) ;
            else sol="-1";
            break;
        }
        if(st[i]=='X'){
            ++cnt;
            if(cnt==4){
                sol+="AAAA";
                cnt=0;
            }
        }
        else{
            if(cnt==4) sol+="AAAA";
            else if(cnt==2) sol+="BB";
            else if(cnt==0) ;
            else{
                sol="-1";
                break;
            }
            sol+=".";
            cnt=0;
        }
    }
    cout<<sol<<'\n';
}