#include<iostream>
#include<queue>
using namespace std;
int arri[4]={-1,1,0,0};
int arrj[4]={0,0,-1,1};
int arr[600][600];
bool visited[600][600];
int main(){//21736
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,t;
    cin>>N>>M;
    queue<int> qux;
    queue<int> quy;
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<M; ++j){
            if(st[j]=='O') arr[i][j]=1;
            else if(st[j]=='P') arr[i][j]=2;
            else if(st[j]=='I'){
                arr[i][j]=3;
                qux.push(i);
                quy.push(j);
                visited[i][j]=true;
            }
            // cout<<visited[i][j]<<' ';
        }
        // cout<<'\n';
    }
    int cnt=0;
    while(!qux.empty()){
        int x=qux.front();
        int y=quy.front();
        qux.pop();
        quy.pop();
        for(int i=0; i<4; ++i){
            int nx=x+arri[i];
            int ny=y+arrj[i];
            if(visited[nx][ny] || arr[nx][ny]==0) continue;
            if(nx<0 || nx>=N) continue;
            if(ny<0 || ny>=M) continue;
            // cout<<nx<<' '<<ny<<'\n';
            if(arr[nx][ny]==2) ++cnt;
            qux.push(nx);
            quy.push(ny);
            visited[nx][ny]=true;
        }
    }
    if(cnt!=0) cout<<cnt<<'\n';
    else cout<<"TT"<<'\n';
}