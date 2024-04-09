#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
bool visited_bfs[51][51];
bool graphb[51][51];
queue<int> qux,quy;

void bfs(int a,int b,int N, int M){// 현재 좌표ab, 행렬최대NM //결국 메인 안으로
    visited_bfs[a][b]=true; //방문표시 하지만 왜인지 방문처리가안된다
    qux.push(a);  //시작 좌표
    quy.push(b);
    while(!qux.empty()){ //남은 간선이 없을때까지
        int x=qux.front();
        int y=quy.front();
        // cout<< x <<' ';
        qux.pop();
        quy.pop();
                    cout<<x<<" "<<y<<'\n';
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(x+i<0 || x+i>=N) continue;//행렬 범위밖
                if(y+j<0 || y+j>=M) continue;//행렬 범위밖
                if(i!=0 && j!=0) continue; //상하좌우만
                if(!graphb[x+i][y+j]) continue; //조건 확인
                if(visited_bfs[x+i][y+j]) continue; //방문로그 확인
                visited_bfs[x+i][y+j]=true;
                    qux.push(x+i);
                    quy.push(y+j);
                    visited_bfs[x+i][y+j]=true;
                    bfs(x+i,y+j,N,M);
                // }
            }
        }
    }

}
int main(){
    int test,M,N,K,a,b,cnt;
    cin>>test;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<test; i++){
        cin>>M>>N>>K;
        cnt=0;
        bool visited_bfs[51][51] = {0};
        bool graphb[51][51]= {0};
        for(int j=0; j<K; j++){//dfs.bfs사용할 칸을 1로
            cin>>b>>a;
            graphb[a][b]=1;
        }
        
        for(int l=0; l<N; l++){
            for(int m=0; m<M; m++){
                if(!visited_bfs[l][m] && graphb[l][m]){ //만약 방문안했고 1이면

                    visited_bfs[l][m]=true; //방문표시
                    qux.push(l);  //시작 좌표
                    quy.push(m);
                    while(!qux.empty()){ //남은 간선이 없을때까지
                        int x=qux.front();
                        int y=quy.front();
                        // cout<< x <<' ';
                        qux.pop();
                        quy.pop();
                                    // cout<<x<<" "<<y<<'\n';
                        for(int n=-1; n<=1; n++){
                            for(int j=-1; j<=1; j++){
                                if(x+n<0 || x+n>=N) continue;//행렬 범위밖
                                if(y+j<0 || y+j>=M) continue;//행렬 범위밖
                                if(n!=0 && j!=0) continue; //상하좌우만
                                if(!graphb[x+n][y+j]) continue; //조건 확인
                                if(visited_bfs[x+n][y+j]) continue; //방문로그 확인
                                    // visited_bfs[x+n][y+j]=true;
                                    visited_bfs[x+n][y+j]=true;
                                    qux.push(x+n);
                                    quy.push(y+j);
                                    
                            }
                        }
                    }

                    cnt++;  //묶음으로 횟수카운트
                }
            }
        }
        cout<<cnt<<'\n';
        // for(int j=0; j<N; j++){ //Check graph
        //     for(int k=0; k<M; k++){
        //         cout<<graphb[j][k];
        //     }
        //     cout<<'\n';
        // }
    }
    
}