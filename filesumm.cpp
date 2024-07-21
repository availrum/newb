#include<iostream>
using namespace std;
const int maxi=2147483647;
int memo[501][501];
int rec(int a, int b, int* c){
    if(a==b){
        if(a==0) return c[a];
        else return c[b]-c[b-1];
    }
    int partsum;
    if(a==0) partsum=c[b];
    else partsum=c[b]-c[a-1];
    int val=maxi;
    if(memo[a][b]!=0) val=memo[a][b];
    else{
        for(int i=a; i<b; ++i) val=min(val,rec(a,i,c)+rec(i+1,b,c)+partsum);
        memo[a][b]=val;
    }
    return val;
}
int main(){//11066
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,page;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>page;
        int file[page]={0,},filesum[page]={0,};
        for(int j=0; j<page; ++j) for(int k=0; k<page; ++k) memo[j][k]=0;
        for(int j=0; j<page; ++j){
            cin>>file[j];
            if(j>0) filesum[j]=filesum[j-1]+file[j];
            else if(j==0) filesum[j]=file[j];
            // cout<<filesum[j]<<'\n';
        }
        int tot=maxi;
        for(int j=0; j<page-1; ++j){
            tot=min(tot,rec(0,j,filesum)+rec(j+1,page-1,filesum));
        }
        cout<<tot<<'\n';
    }
}