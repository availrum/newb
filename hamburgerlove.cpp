#include<iostream>
#include<queue>
using namespace std;
int main(){//1980
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,t;
    cin>>n>>m>>t;
    // pair<int,int> burger[t+1];
    // queue<pair<int,int>> qu;
    int burger[t+1]={0,};
    queue<int> qu;
    qu.push(0);
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        if(x+n <= t && burger[x+n]<burger[x]+1){
            burger[x+n]=burger[x]+1;
            qu.push(x+n);
        }
        if(x+m <= t && burger[x+m]<burger[x]+1){
            burger[x+m]=burger[x]+1;
            qu.push(x+m);
        }
    }
    int maxburger=0, cola=t;
    for(int i=t; i>=0; --i){
        if(burger[i]){
            maxburger=burger[i];
            cola=t-i;
            break;
        }
    }
    cout<<maxburger<<' '<<cola<<'\n';
}