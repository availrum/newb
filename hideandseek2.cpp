#include<iostream>
#include<queue>
using namespace std;
int shorte[300001];
int cnt[300001];
bool visited[300001];
int main(){//12851
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int N,K,x,y;
    queue<int> qu;
    cin>>N>>K;
    qu.push(N);
    visited[N]=true;
    cnt[N]=1;
    while(!qu.empty()){
        x=qu.front();
        qu.pop();
        if(K>=x){
            if(!visited[x+1]) {
                qu.push(x+1);
                visited[x+1]=true;
                shorte[x+1]=shorte[x]+1;
                cnt[x+1]=cnt[x];
            }
            else if(shorte[x+1]==shorte[x]+1) cnt[x+1]+=cnt[x];

            if(!visited[x-1] && x-1>=0){
                qu.push(x-1);
                visited[x-1]=true;
                shorte[x-1]=shorte[x]+1;
                cnt[x-1]=cnt[x];
            }
            else if(shorte[x-1]==shorte[x]+1) cnt[x-1]+=cnt[x];

            if(!visited[2*x] && abs(2*x-K)<=abs(K-x)){
                qu.push(2*x);
                visited[2*x]=true;
                shorte[2*x]=shorte[x]+1;
                cnt[2*x]=cnt[x];
            }
            else if(shorte[2*x]==shorte[x]+1) cnt[2*x]+=cnt[x];
            
        }
        else if(K<x){
            if(!visited[x-1]){
                qu.push(x-1);
                visited[x-1]=true;
                shorte[x-1]=shorte[x]+1;
                cnt[x-1]=cnt[x];
            }
            else if(shorte[x-1]==shorte[x]+1) cnt[x-1]+=cnt[x];
        }
    }
    cout<<shorte[K]<<'\n';
    cout<<cnt[K]<<'\n';
}