#include<iostream>
#include<queue>
using namespace std;
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
int main(){//2468
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N][N], maxi=1,hmax=0;
    bool visited[N][N];
    queue<int> qux,quy;
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
        cin>>arr[i][j];
        if(arr[i][j]>hmax) hmax=arr[i][j];
    }
    for(int height=0; height<hmax; ++height){
        int tmp=0;
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) visited[i][j]=false;
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
            if(!visited[i][j] && arr[i][j]>height){
                qux.push(i);
                quy.push(j);
                visited[i][j]=true;
            }
            else continue;
            while(!qux.empty()){
                int x=qux.front();
                int y=quy.front();
                qux.pop();
                quy.pop();
                for(int k=0; k<4; ++k){
                    if(visited[x+dirx[k]][y+diry[k]]) continue;
                    else if(x+dirx[k]<0 || x+dirx[k]>=N) continue;
                    else if(y+diry[k]<0 || y+diry[k]>=N) continue;
                    else if(arr[x+dirx[k]][y+diry[k]]<=height) continue;
                    qux.push(x+dirx[k]);
                    quy.push(y+diry[k]);
                    visited[x+dirx[k]][y+diry[k]]=true;
                }
            }
            ++tmp;
        }
        if(maxi<tmp) maxi=tmp;
    }
    cout<<maxi<<'\n';
}