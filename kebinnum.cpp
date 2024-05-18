#include<iostream>
#include<queue>
#include<map>
#include<vector>
int graph[101][101];
int sol[101][101];
using namespace std;
int main(){//1389
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,m1,m2;
    queue<int> qu;
    cin>>N>>M;
    // cout<<graph[0][0]<<' '<<graph[1][1]<<'\n';
    for(int i=0; i<M; i++){
        cin>>m1>>m2;
        graph[m1][m2]=m2;
        graph[m2][m1]=m1;
        // cout<<i<<'\n';
    } //여기까지 입력
    // cout<<"123"<<'\n';//입력확인
    for(int i=1; i<=N; i++){//케인베이컨수 구하기 - 1번부터 N번까지
        qu.push(i); //시작포인트로 i를 넣기
        int num=1;  //시작 케빈베이컨수 1 
        int y=0;
        // map<vector<int>,int> ma;
        map<int,int> ma;
        bool visited[N+1][N+1]={0};// 방문여부 매번 false으로 초기화하기
        // visited[i][i]=true; //자기 자신으로 이동하지 않도록
        while(!qu.empty()){//queue가 빌때까지 반복
            int x=qu.front();//연결값으로 이동
            qu.pop();   //x에 저장후 빼기
            for(int j=1; j<=N; j++){//연결된 지점 확인
                if(graph[x][j]==0 || visited[x][j]) continue; //해당 지점의 연결이 없거나 방문한 지점이라면 넘기기 1>2
                
                qu.push(graph[x][j]);  //방문을 안했다면 큐에 넣고
                visited[x][j]=true; //방문처리하기
                // if(sol[i][j]>num ||sol[i][j]==0) sol[i][j]=num; //더 작은 수로 도달할 있거나 첫방문이면 숫자 덮어쓰기
                //현재 j에 와있으므로 i에서 j를 오는 더 빠른 방법이 있다면 덮어쓴다(아니면 입력한적이 없거나)
                // if(ma[{x,j}]>ma[{y,j}]+1 || ma[{x,j}]==0) ma[{x,j}]=ma[{y,j}]+1;//더 빠른 경로가 
                
                // // if(ma[{i,j}]==0) ma[{i,j}]=ma[{x,j}];
                // if(ma[{i,j}]>ma[{x,j}]) ma[{i,j}]=ma[{x,j}];
                // if(ma[{i,j}]==0) ma[{i,j}]=ma[{x,j}]+1;
                
                if(ma[j]>ma[x] || ma[j]==0) ma[j]=ma[x]+1;
            }
            y=x;
            // num++;  //연결지점을 큐에 전부 넣었고, 넣은지점에서 시작하면 +1에서 시작한다
        }
        for(int j=1; j<=N; j++) {
            if(i==j) continue;
            // sol[i][j]=ma[{i,j}];
            sol[i][j]=ma[j];
            if(sol[i][j]!=0) cout<<i<<' '<<j<<' '<<sol[i][j]<<'\n';
        }
    }
    int nam=0,min=0;
    for(int i=1; i<=N; i++){
        int sum=0;    //각각의 케빈베이컨수를 구하기 위해 초기화
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            sum+=sol[i][j]; //
        }
        if(min==0 || (sum!=0 && min>sum)) {
            min=sum;  //
            nam=i;
        }
        // cout<<sum<<'\n';
    }
    cout<<nam<<'\n';
    // cout<<sol[1][2]<<' '<<sol[1][3]<<' '<<sol[1][4]<<' '<<sol[1][5]<<'\n';
    
}
