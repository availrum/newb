#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//25512
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int p,c;
    vector<int> vec[n];
    for(int i=0; i<n-1; ++i){
        cin>>p>>c;
        vec[p].push_back(c);
    }
    int w,b;
    pair<int,int> color[n];
    for(int i=0; i<n; ++i){
        cin>>w>>b;
        color[i].first=w;
        color[i].second=b;
    }
    long long int wcost=0, bcost=0;
    int wvisited[n]={0,}, bvisited[n]={0,};
    queue<int> qu;
    qu.push(0);
    wvisited[0]=1;
    wcost+=color[0].first;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            qu.push(vec[x][i]);
            if(wvisited[x]==1){
                wvisited[vec[x][i]]=2;
                wcost+=color[vec[x][i]].second;
            }
            else if(wvisited[x]==2){
                wvisited[vec[x][i]]=1;
                wcost+=color[vec[x][i]].first;
            }
        }
    }
    qu.push(0);
    bvisited[0]=2;
    bcost+=color[0].second;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            qu.push(vec[x][i]);
            if(bvisited[x]==1){
                bvisited[vec[x][i]]=2;
                bcost+=color[vec[x][i]].second;
            }
            else if(bvisited[x]==2){
                bvisited[vec[x][i]]=1;
                bcost+=color[vec[x][i]].first;
            }
        }
    }
    long long int sol=min(wcost,bcost);
    // cout<<wcost<<' '<<bcost<<'\n';
    cout<<sol<<'\n';
}