#include<iostream>
#include<map>
#include<queue>
using namespace std;
bool graph[1001][1001];
bool visited[1001][1001];

int main(){//14940
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,in,tmp;
    queue<int> bfsx,bfsy;
    map<vector<int>,int> det;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>in;
            graph[i][j]=in;
            if(in==2){
                bfsx.push(i);
                bfsy.push(j);
                graph[i][j]=0;
                visited[i][j]=true;
                // cout<<"dd"<<'\n';

            }
        }
    }
    // cout<<'\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout<<graph[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(!bfsx.empty()){
        int x=bfsx.front();
        int y=bfsy.front();
        bfsx.pop();
        bfsy.pop();
        for(int i=-1; i<=1; i++){
            if(x+i<0 || x+i>N-1) continue;
            for(int j=-1; j<=1; j++){
                if(y+j<0 || y+j>M-1) continue;
                if(i!=0 && j!=0) continue;
                if(visited[x+i][y+j]==true || graph[x+i][y+j]==false) continue;
                visited[x+i][y+j]=true;
                bfsx.push(x+i);
                bfsy.push(y+j);
                det[{x+i,y+j}]=det[{x,y}]+1;
            }
        }

    }
    // cout<<'\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(det[{i,j}]==0 && graph[i][j]==1){
                cout<<"-1";
            }
            else{
                cout<<det[{i,j}];
            }
            if(j!=M-1) cout<<' ';
        }
        cout<<'\n';
    }

}