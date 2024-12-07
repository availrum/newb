#include<iostream>
#include<queue>
using namespace std;
int board[250502], sol[501][501];
int node[501][501];
int dirx[8]={1,1,1,0,0,-1,-1,-1};
int diry[8]={1,0,-1,1,-1,1,0,-1};
int R,C;

struct pos{
    int x;
    int y;
};

int find(int n){
    if(board[n]==n) return n;
    return board[n] = find(board[n]);
}

void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x == y) return;
    if(node[(x-1)/C+1][(x-1)%C+1]<node[(y-1)/C+1][(y-1)%C+1]) swap(x,y);
    board[x]=y;
}

int main(){//16957
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;
    for(int i=0; i<=R*C; ++i){
        board[i]=i;
    }
    
    bool visited[R+1][C+1];
    for(int i=1; i<=R*C; ++i){
        cin >> node[(i-1)/C+1][(i-1)%C+1];
        board[i]=i;
        visited[(i-1)/C+1][(i-1)%C+1]=false;
    }
    queue<pos> qu;
    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            if(visited[i][j]) continue;
            qu.push({i,j});
            visited[i][j]=true;
            while(!qu.empty()){
                int curx=qu.front().x;
                int cury=qu.front().y;
                qu.pop();
                int tx=curx,ty=cury;
                for(int k=0; k<8; ++k){
                    int tmpx=curx+dirx[k];
                    int tmpy=cury+diry[k];
                    if(tmpx<1 || tmpy<1) continue;
                    if(tmpx>R || tmpy>C) continue;
                    if(node[tmpx][tmpy] >= node[tx][ty]) continue;
                    tx=tmpx;
                    ty=tmpy;
                }
                if(tx != curx || ty != cury){
                    merge(C*(tx-1)+ty, C*(curx-1)+cury);
                    if(!visited[tx][ty]){
                        qu.push({tx,ty});
                        visited[tx][ty]=true;
                    }
                }
            }
        }
    }
    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            //[1][1] => [1], [2][1]=>[C+1] , [N][1]=>[N*C+1] ...[i][j]=>[N*(C-1)+j]
            int tmp=find(C*(i-1)+j);
            ++sol[(tmp-1)/C+1][(tmp-1)%C+1];
        }
    }

    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            cout<<sol[i][j];
            if(j!=C) cout<<' ';
            else cout<<'\n';
        }
    }
}
