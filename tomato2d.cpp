#include<iostream>
#include<queue>
using namespace std;
int diri[4] = {1, -1, 0, 0};
int dirj[4] = {0, 0, 1, -1};
struct Vector2d{//벡터화
    int i,j;
    int max=0;//날짜측정 초기화용
};

int main(){//7576
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,H,max=0,cnt0=0,cnt;
    queue<Vector2d> bfs;
    cin>>M>>N;
    int graph[N+1][M+1];
    cnt=M*N; //체크못한 부분 확인
    
    for(int i=0; i<N; i++){//세로 N
        for(int j=0; j<M; j++){//가로 M
            cin>>graph[i][j];
            Vector2d tmpi;
            tmpi.i=i;
            tmpi.j=j;
            if(graph[i][j]==-1) cnt--; // -1 개수만큼 벽이 존재 >> 체크할 부분 숫자 감소 
            if(graph[i][j]==0) cnt0++; //안익은 토마토가 없으면 바로 끝나도록(없어도무관)
            if(graph[i][j]==1){//1이면 시작점으로 큐에 넣기
                bfs.push(tmpi); 
            }
        }
    }

    if(cnt0==0) {//모두 익어있다면
        cout<<"0"<<'\n';
        return 0;
    }

    int dit=0,tim=0; //체크한 개수와 전체시간 초기화

    while(!bfs.empty()){ // 처음 시작점으로 잡은것이 끝날때까지
        Vector2d tmp=bfs.front(); //임시변수 tmp에 시작점 저장
        bfs.pop(); //저장하고 빼주기
        tim=tmp.max; //
        dit++; //하나 체크완료했으니 더해주기
        for(int i=0; i<4; i++){//이동가능범위 6개(3D*2)
            int x=tmp.i+diri[i];
            int y=tmp.j+dirj[i];
            if(x>N-1 || x<0 || y>M-1 || y<0) continue; //상자바깥범위 가면 건너뛰기
            int *visited = &graph[x][y]; //좌표의 주소값을 받고 좌표값 체크
            if(*visited==0){ // 방문 안한범위라면
                *visited=true; //방문처리
                Vector2d vect; //이동한 좌표 xyz를 큐에 넣을예정
                vect.i=x;
                vect.j=y;
                vect.max=tmp.max+1; // 이번 좌표에서 하루 사용했으니 1추가
                bfs.push(vect); 
            }
        }
    }
    if(dit==cnt){//체크한 포인트가 1과 0의 개수랑 같다면
        cout<<tim<<'\n';
        return 0;
    }
    else{//다르면 체크 못한 포인트가 존재 
        cout<<"-1"<<'\n';
    }
}