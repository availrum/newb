#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //16265
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int tcase=0; tcase<t; ++tcase){
        int N;
        cin>>N;
        string st="";
        while(N){
            int tmp=N%26;
            N/=26;
            if(tmp!=0) st+=(char)(tmp+'A'-1);
            else{
                st+='Z';
                --N;
            }
        }
        reverse(st.begin(),st.end());
        cout<<st<<'\n';
    }
}