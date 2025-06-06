#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int find(int* arr, int n){
    if(arr[n]==n) return n;
    return arr[n]=find(arr,arr[n]);
}
void merge(int a, int b, int* arr){
    int x=find(arr,a);
    int y=find(arr,b);
    if(x==y) return;
    if(x<y) swap(x,y);
    arr[x]=y;
}
int main(){//11559
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N=12,M=6;
    char field[N][M];
    string st;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<M; ++j){
            field[i][j]=st[j];
        }
    }
    int time=0, cnt=0;
    while(true){
        int current=0;
        char cur[N][M];
        bool visited[N][M];
        queue<pair<int,int>> qu;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                cur[i][j]=field[i][j];
                visited[i][j]=false;
            }
        }
        int arr[91];
        for(int i=0; i<=90; ++i){
            arr[i]=i;
        }
        for(int iterx=0; iterx<N; ++iterx){
            for(int itery=0; itery<M; ++itery){
                if(visited[iterx][itery] || cur[iterx][itery]=='.') continue;
                qu.push({iterx,itery});
                visited[iterx][itery]=true;
                while(!qu.empty()){
                    int x=qu.front().first;
                    int y=qu.front().second;
                    qu.pop();
                    for(int i=0; i<4; ++i){
                        int nx=x+dirx[i];
                        int ny=y+diry[i];
                        if(nx>=N || nx<0) continue;
                        if(ny>=M || ny<0) continue;
                        if(visited[nx][ny]) continue;
                        if(cur[nx][ny]=='.') continue;
                        if(cur[x][y]!=cur[nx][ny]) continue;
                        visited[nx][ny]=true;
                        merge(x+N*y, nx+N*ny, arr);
                        qu.push({nx,ny});
                    }
                }
            }
        }
        unordered_map<int,int> check, sol;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                int tmp=find(arr,i+j*N);
                ++check[tmp];
            }
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                int tmp=find(arr,i+j*N);
                if(check[tmp]>=4){
                    cur[i][j]='.';

                    if(!sol[tmp]){
                        ++current;
                        sol[tmp]=1;
                    }
                }
            }
        }

        // cout<<'\n';
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<M; ++j){
        //         int tmp=find(arr,i+j*N);
        //         cout<<tmp<<' ';
        //     }
        //     cout<<'\n';
        // }

        // cnt+=current;// 만약 그룹별로 연쇄 회수를 카운트하면 이 방식으로 계산산
        if(!current) break;

        for(int j=0; j<M; ++j){
            queue<int> grav,zero;
            for(int i=N-1; i>=0; --i){
                if(cur[i][j]!='.') grav.push(cur[i][j]);
                else zero.push(cur[i][j]);
            }
            int idx=N-1;
            while(!grav.empty()){
                int value=grav.front();
                grav.pop();
                field[idx][j]=value;
                --idx;
            }
            while(!zero.empty()){
                zero.pop();
                field[idx][j]='.';
                --idx;
            }
        }
        // cout<<'\n';
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<M; ++j){
        //         cout<<field[i][j];
        //     }
        //     cout<<'\n';
        // }
        ++cnt;
    }
    cout<<cnt<<'\n';
}