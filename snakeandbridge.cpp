#include<iostream>
#include<queue>
using namespace std;
int arr[101];
int visited[101];
int main(){//16928
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int tmp=0;
    for(int i=0; i<N+M; ++i){
        cin>>tmp;
        cin>>arr[tmp];
    }
    queue<int> qu;
    qu.push(1);
    // cout<<'\n'<<qu.front()<<'\n';
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=1; i<=6; ++i){
            if(x+i>100) break;
            if(visited[x+i]) continue;
            if(!arr[x+i]){
                qu.push(x+i);
                visited[x+i]=visited[x]+1;
            }
            else if(!visited[arr[x+i]]){
                qu.push(arr[x+i]);
                visited[arr[x+i]]=visited[x]+1;
                visited[x+i]=visited[x]+1;
            }
        }
    }
    cout<<visited[100]<<'\n';
}