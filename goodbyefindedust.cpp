#include<iostream>
#include<queue>
using namespace std;

int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};

int main(){//17144
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R,C,T;
    cin>>R>>C>>T;
    int arr[R][C];
    int apu=-2, apd=-2;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin>>arr[i][j];
            if(arr[i][j]==-1){
                if(apu==-2) apu=i;
                else apd=i;
            }
        }
    }
    for(int i=1; i<=T; ++i){
        int arrtmp[R][C];
        queue<pair<int,int>> qu;
        for(int j=0; j<R; ++j){
            for(int k=0; k<C; ++k){
                arrtmp[j][k]=0;
                if(arr[j][k]>4) qu.push({j,k});
            }
        }
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            int tmp=arr[x][y]/5;
            for(int j=0; j<4; ++j){
                int nx=x+dirx[j];
                int ny=y+diry[j];
                if(nx<0 || nx>=R) continue;
                if(ny<0 || ny>=C) continue;
                if(arr[nx][ny]==-1) continue;
                arr[x][y]-=tmp;
                arrtmp[nx][ny]+=tmp;
            }
        }
        for(int j=0; j<R; ++j){
            for(int k=0; k<C; ++k){
                if(arr[j][k]==-1) continue;
                arr[j][k]+=arrtmp[j][k];
            }
        }
        /////////////////////////////////////
        for(int j=apu-1; j>0; --j) arr[j][0]=arr[j-1][0];
        for(int j=0; j<C-1; ++j) arr[0][j]=arr[0][j+1]; 
        for(int j=0; j<apu; ++j) arr[j][C-1]=arr[j+1][C-1];
        for(int j=C-1; j>0; --j){
            if(arr[apu][j-1]==-1) arr[apu][j]=0;
            else arr[apu][j]=arr[apu][j-1];
        }
        ////////////////////////////////////////////////
        for(int j=apd+1; j<R-1; ++j) arr[j][0]=arr[j+1][0];
        for(int j=0; j<C-1; ++j) arr[R-1][j]=arr[R-1][j+1];
        for(int j=R-1; j>apd; --j) arr[j][C-1]=arr[j-1][C-1];
        for(int j=C-1; j>0; --j){
            if(arr[apd][j-1]==-1) arr[apd][j]=0;
            else arr[apd][j]=arr[apd][j-1];
        }
    }
    int cnt=0;
    // cout<<'\n';
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            if(arr[i][j]==-1) continue;
            cnt+=arr[i][j];
            // cout<<arr[i][j]<<' ';
        }
        // cout<<'\n';
    }
    cout<<cnt<<'\n';
}