#include<iostream>
using namespace std;
int board[250001], sol[501][501];
int dirx[8]={1,1,1,0,0,-1,-1,-1};
int diry[8]={1,0,-1,1,-1,1,0,-1};
int R,C;

int find(int n){
    if(n==board[n]) return n;
    return board[n] = find(board[n]);
}

void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x == y) return;
    if(x<y) swap(x,y);
    board[x]=y;
}

int main(){//16957
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;
    int node[R+1][C+1];
    for(int i=0; i<=R; ++i){
        for(int j=0; j<=C; ++j){
            node[i][j]=0;
        }
    }
    for(int i=0; i<=R*C; ++i){
        board[i]=i;
    }
    int tmp;
    for(int i=1; i<=R*C; ++i){
        cin >> board[i];
        node[(i-1)/R+1][(i-1)%R+1]=board[i];
    }
    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            for(int k=0; k<8; ++k){
                int nx=i+dirx[k];
                int ny=j+diry[k];
                if(nx==0 || ny==0) continue;
                if(nx>R || ny>C) continue;
                if(node[nx][ny]>=node[i][j]) continue;
                // cout<<i<<' '<<j<<' '<<k<<'\n';
                merge(R*(i-1)+j, R*(nx-1)+ny);

                if(board[R*(i-1)+j]==R*(i-1)+j){
                    ++sol[i][j];
                }
                else{
                    sol[nx][ny] = sol[i][j]+1;
                    sol[i][j] = 0;
                }
            }
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