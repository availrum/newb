#include<iostream>
#include<queue>
using namespace std;
struct pos{
    int x;
    int y;
    int val=0;
};
int difx[8]={2,1,-1,-2,-2,-1,1,2};
int dify[8]={1,2,2,1,-1,-2,-2,-1};
int main(){//7562
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,I;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>I;
        int arr[I][I];
        bool visited[I][I];
        for(int i=0; i<I; ++i){
            for(int j=0; j<I; ++j){
                arr[i][j]=2147483647;
                visited[i][j]=false;
            }
        }
        pos tmp, end;
        tmp.val=0, end.val=0;
        cin>>tmp.x>>tmp.y;
        queue<pos> qu;
        // cout<<tmp.val<<'\n';
        cin>>end.x>>end.y;
        qu.push(tmp);
        visited[tmp.x][tmp.y]=true;
        while(!qu.empty()){
            pos cur=qu.front();
            qu.pop();
            for(int i=0; i<8; ++i){
                int cx=cur.x+difx[i];
                int cy=cur.y+dify[i];
                if(cx>=I || cx<0) continue;
                if(cy>=I || cy<0) continue;
                if(visited[cx][cy]) continue;
                if(arr[cx][cy]<=cur.val+1) continue;
                pos inpos;
                inpos.x=cx, inpos.y=cy; inpos.val=cur.val+1;
                qu.push(inpos);
                arr[cx][cy]=inpos.val;
            }
        }
        if(arr[end.x][end.y]!=2147483647) cout<<arr[end.x][end.y]<<'\n';
        else cout<<"0"<<'\n';
    }
}