#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//12893
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int visited[N+1]={0,};
    vector<int> vec[N+1];
    int A,B;
    for(int i=0; i<M; ++i){
        cin>>A>>B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }
    queue<int> qu;
    bool flag=false;
    for(int i=1; i<=N; ++i){
        if(visited[i]) continue;
        qu.push(i);
        visited[i]=1;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=0; j<vec[x].size(); ++j){
                if(!visited[vec[x][j]]){
                    if(visited[x]==2) visited[vec[x][j]]=1;
                    else visited[vec[x][j]]=2;
                    qu.push(vec[x][j]);
                }
                else if(visited[x]==visited[vec[x][j]]){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
    }
    if(flag==false) cout<<"1"<<'\n';
    else cout<<"0"<<'\n';
}
