#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//11725
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr[N+1];
    for(int i=0; i<N-1; ++i){
        int tmp1=0,tmp2=0;
        cin>>tmp1>>tmp2;
        arr[tmp1].push_back(tmp2);
        arr[tmp2].push_back(tmp1);
    }
    queue<int> qu;
    bool visited[N+1]={0,};
    int sol[N+1]={0,};
    qu.push(1);
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=0; i<arr[x].size(); ++i){
            if(!visited[arr[x][i]]){
                sol[arr[x][i]]=x;
                qu.push(arr[x][i]);
                visited[arr[x][i]]=true;
            }
        }
    }
    for(int i=2; i<=N; ++i) cout<<sol[i]<<'\n';
}