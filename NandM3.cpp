#include<iostream>
using namespace std;
int N,M;
bool visited[9];
int graph[9];
void dfs(int cnt){
    if(cnt==M){ //출력개수가 만족되면
        for(int i=0; i<M; i++) {
            cout<<graph[i]<<' '; //조합 크기만큼 출력
        }
        cout<<'\n'; 
        return; //출력한 재귀는 끝내기
    }
    for(int i=0; i<N; i++){//0(1 )-1-2-3-4>
        graph[cnt]=i+1;
        dfs(cnt+1);
    }
}
int main(){//15651
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    dfs(0);
}