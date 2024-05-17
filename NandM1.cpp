#include<iostream>
using namespace std;
int N,M;
bool visited[9];
int graph[9];

void dfs(int cnt){
    if(cnt==M){ //출력개수가 만족되면
        for(int i=0; i<M; i++) cout<<graph[i]<<' '; //조합 크기만큼 출력
        cout<<'\n'; 
    }
    for(int i=0; i<N; i++){
        if(visited[i+1]) continue;    //방문했다면 다음으로
        visited[i+1]=true;    //방문처리
        graph[cnt]=i+1;   //출력할 0번부터 M-1번까지 값 저장
        dfs(cnt+1);
        visited[i+1]=false;   //재귀함수로 출력했으니 다른걸 보기위해 미방문처리
    }
}
int main(){//15649
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    dfs(0);
}