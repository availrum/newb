#include<iostream>
using namespace std;
int main(){//1956
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    cin>>V>>E;
    int a,b,c;
    int dist[V+1][V+1];
    for(int i=0; i<=V; ++i){
        for(int j=0; j<=V; ++j){
            dist[i][j]=214748364;
            if(i==j) dist[i][j]=0;
        }
    }
    for(int i=0; i<E; ++i){
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
    int mincycle=214748364;
    for(int i=1; i<=V; ++i){
        //start
        for(int j=1; j<=V; ++j){
            //mid
            if(i==j) continue;
            else if(dist[i][j] >= 214748364) continue;
            for(int k=1; k<=V; ++k){
                if(dist[j][k]<214748364){
                    dist[i][k]=min(dist[i][k],dist[i][j]+dist[j][k]);
                    if(i==k) mincycle=min(mincycle,dist[i][j]+dist[j][k]);
                }
            }
        }
    }
    if(mincycle==214748364) cout<<"-1"<<'\n';
    else cout<<mincycle<<'\n';
}