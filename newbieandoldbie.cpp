#include<iostream>
#include<queue>
using namespace std;
int main(){//17209
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int report[N][N];
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            report[i][j]=0;
        }
    }
    string st;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<st.size(); ++j){
            int tmp=st[j]-'0';
            if(tmp==1){
                report[i][j]=1;
                report[j][i]=1;
            }
        }
    }

    int visited[N]={0,};
    int oldbie=0;
    for(int i=0; i<N; ++i){
        if(visited[i]) continue;
        int cnt1=1, cnt2=0;
        queue<int> qu;
        qu.push(i);
        visited[i]=1;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=0; j<N; ++j){
                if(!report[x][j] || visited[j]) continue;
                if(visited[x]==1){
                    visited[j]=2;
                    ++cnt2;
                    qu.push(j);
                }
                else if(visited[x]==2){
                    visited[j]=1;
                    ++cnt1;
                    qu.push(j);
                }
            }
        }
        oldbie+=max(cnt1,cnt2);
    }
    cout<<oldbie<<'\n';
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         cout<<report[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}