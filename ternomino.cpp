#include<iostream>
using namespace std;
int maxi;
int N,M;
int gtx[4]={-1,1,0,0}, gty[4]={0,0,-1,1};
int arr[501][501];
bool visited[501][501];
void rec(int x, int y, int num, int sum){
    if(num==4){
        if(maxi<sum) maxi=sum;
        return;
    }
    int tx,ty;
    for(int i=0; i<4; ++i){
        tx=x+gtx[i];
        ty=y+gty[i];
        if(visited[tx][ty]) continue;
        else if(tx<0 || tx>=N) continue;
        else if(ty<0 || ty>=M) continue;
        if(num==2){
            if(!visited[x+gty[i]][y+gtx[i]]){
                if(x+gty[i]<0 || x+gty[i]>=N);
                else if(y+gtx[i]<0 || y+gtx[i]>=M);
                else rec(tx,ty,num+2,sum+arr[tx][ty]+arr[x+gty[i]][y+gtx[i]]);
            }
        }
        visited[tx][ty]=true;
        rec(tx,ty,num+1, sum+arr[tx][ty]);
        visited[tx][ty]=false;
    }
}
int main(){//14500
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
        visited[i][j]=true;
        rec(i,j,1,arr[i][j]);
        visited[i][j]=false;
    }
    
    cout<<maxi<<'\n';
}