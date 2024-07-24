#include<iostream>
#include<queue>
using namespace std;
int shorte[300001];
bool visited[300001];
int main(){//1697
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K,x,y;
    queue<int> qu;
    cin>>N>>K;
    qu.push(N);
    visited[N]=true;
    while(!qu.empty()){
        x=qu.front();
        qu.pop();
        // cout<<x<<' '<<shorte[x]<<'\n';
        if(x==K) break;
        if(K>=x){
            if(!visited[x-1]){
                qu.push(x-1);
                visited[x-1]=true;
                shorte[x-1]=shorte[x]+1;
            }
            if(!visited[2*x] && abs(2*x-K)<=abs(K-x)){
                qu.push(2*x);
                visited[2*x]=true;
                shorte[2*x]=shorte[x];
            }
            if(!visited[x+1]) {
                qu.push(x+1);
                visited[x+1]=true;
                shorte[x+1]=shorte[x]+1;
            }
        }
        else if(K<x){
            if(visited[x-1]) continue;
            qu.push(x-1);
            visited[x-1]=true;
            shorte[x-1]=shorte[x]+1;
        }
    }
    cout<<shorte[K]<<'\n';
}