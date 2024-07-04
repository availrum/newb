#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int N,M;
bool visited[9];
int graph[9];
int numb[9];
unordered_map<string,int> ma;

void dfs(int cnt){
    if(cnt==M){ //출력개수가 만족되면
        string st="";
        for(int i=0; i<M; ++i){
            st+=graph[i];
            if(i!=M-1) st+=" ";
        }
        if(ma[st]!=0) return; 
        else ++ma[st];
        for(int i=0; i<M; i++) cout<<graph[i]<<' '; //조합 크기만큼 출력
        cout<<'\n';
        return;
    }
    for(int i=0; i<N; i++){
        if(visited[i]) continue;    //방문했다면 다음으로
        visited[i]=true;    //방문처리
        graph[cnt]=numb[i];   //출력할 0번부터 M-1번까지 값 저장
        dfs(cnt+1);
        visited[i]=false;   //재귀함수로 출력했으니 다른걸 보기위해 미방문처리
    }
}
int main(){//15663
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    int tmp;
    for(int i=0; i<N; ++i) cin>>numb[i];
    sort(numb,numb+N);
    dfs(0);
}