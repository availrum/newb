#include<iostream>
using namespace std;
int cmp(int a, int b){
    return a>b ? a:b;
}
int tri[501][501];
int sol[501][501];
int main(){//1932
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t,marr=1,max=0;
    cin>>N;
    for(int i=0; i<N; ++i){
        // cin>>t;
        for(int j=0; j<marr; ++j){
            cin>>tri[i][j];
            if(i==0){
                sol[i][j]=tri[i][j];
                continue;
            }
            else if(i==1){
                sol[i][j]=sol[i-1][0]+tri[i][j];
                continue;
            }
            if(j==0) sol[i][j]=sol[i-1][j]+tri[i][j];
            else if(j==marr-1) sol[i][j]=sol[i-1][j-1]+tri[i][j];
            else sol[i][j]=cmp(sol[i-1][j-1]+tri[i][j],sol[i-1][j]+tri[i][j]);
        }
        marr++;
    }
    for(int i=0; i<N; ++i){
        if(sol[N-1][i]>max) max=sol[N-1][i];
        // cout<<sol[N-1][i];
    }
    cout<<max<<'\n';

}