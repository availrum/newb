#include<iostream>
#include<map>
#include<queue>
using namespace std;
bool graph[101][101];
bool sol[101][101];

int main(){//11403
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,in,tmp;
    queue<int> bfsx,bfsy;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>in;
            graph[i][j]=in;
            // sol[i][j]=in;
        }
    }
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout<<graph[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j]==0) continue;
            graph[i][j]=1;
            sol[i][j]=1;
            map<vector<int>,int> visited;
            bfsx.push(i);
            bfsy.push(j);
            while(!bfsy.empty()){
                int x=bfsx.front();
                int y=bfsy.front();
                sol[x][y]=true;
                tmp=y;
                // bfsx.pop();
                bfsy.pop();
                for(int k=0; k<N; k++){
                    if(graph[y][k]==0) continue;
                    sol[x][k]=true;
                    if(!visited[{x,k}]){
                        bfsy.push(k);
                        visited[{x,k}]=1;
                    }
                }
                // if(graph[x][y])//03 16 34 35 40 56 62 >> 0/3562 1/62 2/0 3/456023 4/034562 5/62 6/2

            }
            bfsx.pop();

        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<sol[i][j]<<' ';
        }
        cout<<'\n';
    }

}