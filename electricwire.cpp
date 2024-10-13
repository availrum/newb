#include<iostream>
using namespace std;
int main(){//2565
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,max1=0,max2=0;
    cin>>N;
    int tlp1[501]={0,},tlp2[501]={0,},tp1,tp2;
    for(int i=0; i<N; ++i){
        cin>>tp1>>tp2;
        if(max1<tp1) max1=tp1;
        if(max2<tp2) max2=tp2;
        tlp1[tp1-1]=i+1;
        tlp2[tp2-1]=i+1;
    }
    int sol[501][501];
    for(int i=0; i<=max1; ++i) for(int j=0; j<=max2; ++j) sol[i][j]=0;
    for(int i=1; i<=max1; ++i){
        for(int j=1; j<=max2; ++j){
            if(tlp1[i-1]==tlp2[j-1] && tlp1[i-1]!=0) sol[i][j]=sol[i-1][j-1]+1;
            else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
        }
    }
    cout<<N-sol[max1][max2]<<'\n';
    // for(int i=0; i<=max1; ++i){
    //     for(int j=0; j<=max2; ++j) cout<<sol[i][j]<<' ';
    //     cout<<'\n';
    // }
}