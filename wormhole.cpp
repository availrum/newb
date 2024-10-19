#include<iostream>
#include<vector>
using namespace std;
int main(){//1865
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin>>TC;
    int N,M,W;
    int S, E, T;
    const int inf=2147483646;
    bool flag;
    for(int i=0; i<TC; ++i){
        cin>>N>>M>>W;
        int ocost[N+1][N+1],cost[N+1];
        for(int j=0; j<=N; ++j){
            for(int k=0; k<=N; ++k){
                ocost[j][k]=inf;
                if(j==k) ocost[j][k]=0;
            }
        }
        for(int j=0; j<M; ++j){
            cin>>S>>E>>T;
            if(ocost[S][E]>T) ocost[S][E]=T;
            if(ocost[E][S]>T) ocost[E][S]=T;
        }
        for(int j=0; j<W; ++j){
            cin>>S>>E>>T;
            if(ocost[S][E]>-T) ocost[S][E]=-T;
        }
        vector<vector<pair<int,int>>> node(N+1);
        for(int j=1; j<=N; ++j){
            for(int k=1; k<=N; ++k){
                if(ocost[j][k]!=inf) node[j].push_back({k,ocost[j][k]});
            }
        }
        flag=false;
        for(int l=1; l<=N; ++l){
            for(int k=0; k<=N; ++k) cost[k]=inf;
            cost[l]=0;
            for(int j=1; j<N; ++j){
                bool flagbel=0;//업뎃안되면 끝내기용도 키포인트
                for(int k=1; k<=N; ++k){
                    if(cost[k]==inf) continue;
                    // for(int m=1; m<=N; ++m){
                    //     if(ocost[k][m]>10001) continue; 
                    for(auto [ed,val] : node[k]){
                        if(cost[ed]>cost[k]+val){
                            cost[ed]=cost[k]+val;
                            flagbel=1;
                        }
                    }
                }
                if(!flagbel) break;
            }
            //후...나한테왜이라는거ㅕㅕㅑㅛㅑ
            for(int j=1; j<=N; ++j){
                if(cost[j]==inf) continue;
                for(auto[ed,val] : node[j]){
                    if(cost[ed]>cost[j]+val){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}