#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main(){//13913
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int arrmax=max(N+1,K*2+1);
    int coordi[arrmax]={0,};
    int path[arrmax]={0,};
    if(N==K){
        cout<<"0"<<'\n';
        cout<<N<<'\n';
        return 0;
    }

    queue<int> qu;
    qu.push(N);
    while(!coordi[K]){
        int x=qu.front();
        qu.pop();
        if(x+1<=K && coordi[x+1]==0){
            qu.push(x+1);
            coordi[x+1]=coordi[x]+1;
            path[x+1]=x;
        }
        if(x-1>=0 && coordi[x-1]==0){
            qu.push(x-1);
            coordi[x-1]=coordi[x]+1;
            path[x-1]=x;

        }
        if(x<K && coordi[2*x]==0){
            qu.push(2*x);
            coordi[2*x]=coordi[x]+1;
            path[2*x]=x;
        }
    }
    stack<int> sol;
    int cur=K;
    sol.push(K);
    while(cur!=N){
        cur=path[cur];
        sol.push(cur);
    }
    cout<<coordi[K]<<'\n';
    while(!sol.empty()){
        cout<<sol.top();
        sol.pop();
        if(!sol.empty()) cout<<' ';
        else cout<<'\n';
    }
}