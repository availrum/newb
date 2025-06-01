#include<iostream>
#include<queue>
using namespace std;
struct pos{
    int x;
    int y;
};
int main(){//3190
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int board[N][N];
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            board[i][j]=0;
        }
    }
    int tmpx,tmpy;
    for(int i=0; i<K; ++i){
        cin>>tmpx>>tmpy;
        board[tmpx-1][tmpy-1]=1;
    }
    int L;
    cin>>L;
    queue<pair<int,char>> change_head; 
    int change_time;
    char change_dir;
    for(int i=0; i<L; ++i){
        cin>>change_time>>change_dir;
        change_head.push({change_time,change_dir});
    }
    
    int current_time=0;
    int dir=0;
    queue<pos> qu;
    qu.push({0,0});
    board[0][0]=-1;
    pos tail={0,0};
    while(!qu.empty()){
        if(!change_head.empty()){
            if(current_time==change_head.front().first){
                char head=change_head.front().second;
                change_head.pop();
                if(head=='D'){
                    ++dir;
                    dir%=4;
                }
                else if(head=='L'){
                    --dir;
                    if(dir<0) dir=3;
                }
            }
        }

        if(dir==0){
            int befx=-1, befy=-1;
            bool add_tail=false;
            queue<pos> new_qu;
            while(!qu.empty()){
                int x=qu.front().x;
                int y=qu.front().y;
                qu.pop();
                if(befx==-1){
                    if(y+1>=N || board[x][y+1]==-1){
                        // for(int j=0; j<N; ++j){
                        //     for(int k=0; k<N; ++k){
                        //         cout<<board[j][k]<<' ';
                        //     }
                        //     cout<<'\n';
                        // }
                        cout<<current_time+1<<'\n';
                        return 0;
                    }
                    else if(board[x][y+1]==1){
                        new_qu.push({x,y+1});
                        add_tail=true;
                        board[x][y+1]=-1;
                    }
                    else if(board[x][y+1]==0){
                        new_qu.push({x,y+1});
                        board[x][y+1]=-1;
                    }
                    befx=x, befy=y;
                }
                else{
                    // cout<<'\n'<<"else test"<<'\n';
                    new_qu.push({befx,befy});
                    befx=x, befy=y;
                }
            }
            if(add_tail) new_qu.push({befx,befy});
            else board[befx][befy]=0;
            qu=new_qu;
        }
        else if(dir==1){
            int befx=-1, befy=-1;
            bool add_tail=false;
            queue<pos> new_qu;
            while(!qu.empty()){
                int x=qu.front().x;
                int y=qu.front().y;
                qu.pop();
                if(befx==-1){
                    if(x+1>=N || board[x+1][y]==-1){
                        // for(int j=0; j<N; ++j){
                        //     for(int k=0; k<N; ++k){
                        //         cout<<board[j][k]<<' ';
                        //     }
                        //     cout<<'\n';
                        // }
                        cout<<current_time+1<<'\n';
                        return 0;
                    }
                    else if(board[x+1][y]==1){
                        new_qu.push({x+1,y});
                        add_tail=true;
                        board[x+1][y]=-1;
                    }
                    else if(!board[x+1][y]){
                        new_qu.push({x+1,y});
                        board[x+1][y]=-1;
                    }
                    befx=x, befy=y;
                }
                else{
                    // cout<<'\n'<<"else test"<<'\n';
                    // if(i!=iter-1) 
                    new_qu.push({befx,befy});
                    befx=x, befy=y;
                }
            }
            if(add_tail) new_qu.push({befx,befy});
            else board[befx][befy]=0;
            qu=new_qu;
        }
        else if(dir==2){
            int befx=-1, befy=-1;
            bool add_tail=false;
            queue<pos> new_qu;
            while(!qu.empty()){
                int x=qu.front().x;
                int y=qu.front().y;
                qu.pop();
                if(befx==-1){
                    if(y-1<0 || board[x][y-1]==-1){
                        // for(int j=0; j<N; ++j){
                        //     for(int k=0; k<N; ++k){
                        //         cout<<board[j][k]<<' ';
                        //     }
                        //     cout<<'\n';
                        // }
                        cout<<current_time+1<<'\n';
                        return 0;
                    }
                    else if(board[x][y-1]==1){
                        new_qu.push({x,y-1});
                        add_tail=true;
                        board[x][y-1]=-1;
                    }
                    else if(board[x][y-1]==0){
                        new_qu.push({x,y-1});
                        board[x][y-1]=-1;
                    }
                    befx=x, befy=y;
                }
                else{
                    // cout<<'\n'<<"else test"<<'\n';
                    // if(i!=iter-1) 
                    new_qu.push({befx,befy});
                    befx=x, befy=y;
                }
            }
            if(add_tail) new_qu.push({befx,befy});
            else board[befx][befy]=0;
            qu=new_qu;
        }
        else if(dir==3){
            int befx=-1, befy=-1;
            bool add_tail=false;
            queue<pos> new_qu;
            while(!qu.empty()){
                int x=qu.front().x;
                int y=qu.front().y;
                qu.pop();
                if(befx==-1){
                    if(x-1<0 || board[x-1][y]==-1){
                        // for(int j=0; j<N; ++j){
                        //     for(int k=0; k<N; ++k){
                        //         cout<<board[j][k]<<' ';
                        //     }
                        //     cout<<'\n';
                        // }
                        cout<<current_time+1<<'\n';
                        return 0;
                    }
                    else if(board[x-1][y]==1){
                        new_qu.push({x-1,y});
                        add_tail=true;
                        board[x-1][y]=-1;
                    }
                    else if(!board[x-1][y]){
                        new_qu.push({x-1,y});
                        board[x-1][y]=-1;
                    }
                    befx=x, befy=y;
                }
                else{
                    // cout<<'\n'<<"else test"<<'\n';
                    // if(i!=iter-1) 
                    new_qu.push({befx,befy});
                    befx=x, befy=y;
                }
            }
            if(add_tail) new_qu.push({befx,befy});
            else board[befx][befy]=0;
            qu=new_qu;
        }
        ++current_time;
        // cout<<current_time<<'\n';
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<N; ++j) cout<<board[i][j]<<' ';
        //     cout<<'\n';
        // }
        // cout<<'\n';
    }
    cout<<current_time<<'\n';
}