#include<iostream>
using namespace std;
int arr[21][21], team[21], N, mini,minf;
bool visited[21];
void rec(int pe,int num){
    if(num==N/2){
        int sum=0;
        for(int i=0; i<N/2; ++i){
            for(int j=i+1; j<N/2; ++j){
                sum+=(arr[team[i]-1][team[j]-1]+arr[team[j]-1][team[i]-1]);
            }
        }
        for(int i=2; i<=N; ++i){
            if(visited[i]) continue;
            for(int j=i+1; j<=N; ++j){
                if(visited[j]) continue;
                sum-=(arr[i-1][j-1]+arr[j-1][i-1]);
            }
        }
        if(abs(sum)<mini || minf==0){
            mini=abs(sum);
            minf=1;
        }
        return;
    }
    for(int i=pe; i<=N; ++i){
        if(visited[i]) continue;
        visited[i]=true;
        team[num]=i;
        rec(i+1,num+1);
        visited[i]=false;
    }
}
int main(){//14889
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>arr[i][j];
    visited[1]=true;
    team[0]=1;
    rec(2,1);
    cout<<mini<<'\n';
}