#include<iostream>
using namespace std;
int main(){ //25916
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int dok[N];
    for(int i=0; i<N; ++i){
        cin>>dok[i];
    }
    int lft=0, rgt=0, max_vol=0, vol=dok[rgt];
    while(lft<N){
        if(rgt>=N) break;

        if(vol>M){
            vol-=dok[lft];
            ++lft;
            if(lft>rgt){
                rgt=lft;
                vol+=dok[rgt];
            }
        }
        else{
            max_vol=max(max_vol,vol);
            ++rgt;
            if(rgt>=N) break;
            else vol+=dok[rgt];
        }
        // cout<<lft<<' '<<rgt<<' '<<vol<<'\n';
    }
    cout<<max_vol<<'\n';
}