#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){//12893
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int visited[n+1]={0,};
    vector<int> vec[n+1];
    int hate, nam;
    for(int i=1; i<=n; ++i){
        cin>>hate;
        for(int j=0; j<hate; ++j){
            cin>>nam;
            vec[i].push_back(nam);
            vec[nam].push_back(i);
        }
    }
    queue<int> qu;
    bool flag=false;
    vector<int> solblue,solwhite;
    for(int i=1; i<=n; ++i){
        if(visited[i]) continue;
        qu.push(i);
        visited[i]=1;
        solblue.push_back(i);
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=0; j<vec[x].size(); ++j){
                if(!visited[vec[x][j]]){
                    if(visited[x]==2){
                        visited[vec[x][j]]=1;
                        solblue.push_back(vec[x][j]);
                    }
                    else{
                        visited[vec[x][j]]=2;
                        solwhite.push_back(vec[x][j]);
                    }
                    qu.push(vec[x][j]);
                }
            }
        }
    }
    sort(solblue.begin(),solblue.end());
    sort(solwhite.begin(),solwhite.end());
    cout<<solblue.size()<<'\n';
    for(int i=0; i<solblue.size(); ++i){
        cout<<solblue[i];
        if(i!=solblue.size()-1) cout<<' ';
        else cout<<'\n';
    }
    cout<<solwhite.size()<<'\n';
    for(int i=0; i<solwhite.size(); ++i){
        cout<<solwhite[i];
        if(i!=solwhite.size()-1) cout<<' ';
        else cout<<'\n';
    }
}
