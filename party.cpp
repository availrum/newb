#include<iostream>
#include<queue>
using namespace std;
int maxcost;
int main(){//1238
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, X;
	cin>>N>>M>>X;
	int ocost[N+1][N+1];
	int cost[N+1][N+1];
	for(int i=0; i<=N; ++i) for(int j=0; j<=N; ++j){
		cost[i][j]=2147483646;
		ocost[i][j]=2147483646;
	}
	for(int i=0; i<M; ++i){
		int st, ed, val;
		cin>>st>>ed>>val;
		ocost[st][ed]=val;
	}
	queue<int> qu;
	qu.push(X);
	cost[X][X]=0;
	while(!qu.empty()){
		int y=qu.front();
		qu.pop();
		for(int j=1; j<=N; ++j){
			if(ocost[y][j]>100) continue;
			else if(cost[X][j]>cost[X][y]+ocost[y][j]){
                cost[X][j]=cost[X][y]+ocost[y][j];
                qu.push(j);
            }
		}
	}
	qu.push(X);
	while(!qu.empty()){
		int y=qu.front();
		qu.pop();
		for(int j=1; j<=N; ++j){
			if(ocost[j][y]>100) continue;
			else if(cost[j][X]>ocost[j][y]+cost[y][X]){
                cost[j][X]=ocost[j][y]+cost[y][X];
                qu.push(j);
            }
		}
	}
	int sum;
	for(int i=1; i<=N; ++i){
		sum=cost[i][X]+cost[X][i];
		// cout<<cost[i][X]<<' '<<cost[X][i]<<'\n';
		if(sum>maxcost) maxcost=sum;
	}
	cout<<maxcost<<'\n';
}