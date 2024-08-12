#include<iostream>
#include<queue>
using namespace std;
int main(){//5014
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int F,S,G,U,D;
    cin>>F>>S>>G>>U>>D;
    int visited[F+1]={0,};
    queue<int> qu;
    qu.push(S);
    visited[S]=1;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        if(x+U<=F){
            if(!visited[x+U] || visited[x+U]>visited[x]+1){
                visited[x+U]=visited[x]+1;
                qu.push(x+U);
            }
        }
        if(x-D>=1){
            if(!visited[x-D] || visited[x-D]>visited[x]+1){
                visited[x-D]=visited[x]+1;
                qu.push(x-D);
            }
        }
        // cout<<x<<' ';
    }
    // cout<<'\n';
    if(visited[G]) cout<<visited[G]-1<<'\n';
    else cout<<"use the stairs"<<'\n';
}