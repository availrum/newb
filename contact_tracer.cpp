#include<iostream>
using namespace std;
int main(){ //20225
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,n,p;
    while(cin>>m>>n>>p){
        if(m==0 && n==0 && p==0) break;
        bool infected[m+1]={false};
        infected[p]=true;
        int user1, user2;
        for(int i=0; i<n; ++i){
            cin>>user1>>user2;
            if(infected[user1] || infected[user2]){
                infected[user1]=true;
                infected[user2]=true;
            }
        }
        int cnt=0;
        for(int i=1; i<=m; ++i){
            if(infected[i]) ++cnt;
        }
        cout<<cnt<<'\n';
    }
}