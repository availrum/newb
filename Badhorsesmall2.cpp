#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;
int main(){//12082
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int Tcase=1; Tcase<=T; ++Tcase){
        int M;
        cin>>M;
        unordered_map<string,int> number;
        // unordered_map<int,string> log;
        vector<int> vec[201];
        pair<string,string> st[M];
        int idx=0;
        for(int i=0; i<M; ++i){
            cin>>st[i].first>>st[i].second;
            if(number[st[i].first]==0){
                ++idx;
                number[st[i].first]=idx;
            }
            if(number[st[i].second]==0){
                ++idx;
                number[st[i].second]=idx;
            }
            vec[number[st[i].first]].push_back(number[st[i].second]);
            vec[number[st[i].second]].push_back(number[st[i].first]);
        }
        queue<int> qu;
        int visited[idx+1]={0,};
        bool flag=false;
        for(int i=1; i<=idx; ++i){
            if(visited[i]) continue;
            qu.push(i);
            visited[i]=1;
            while(!qu.empty()){
                int x=qu.front();
                qu.pop();
                for(int j=0; j<vec[x].size(); ++j){
                    if(!visited[vec[x][j]]){
                        if(visited[x]==1) visited[vec[x][j]]=2;
                        else visited[vec[x][j]]=1;
                        qu.push(vec[x][j]);
                    }
                    else{
                        if(visited[x]==visited[vec[x][j]]){
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout<<"Case #"<<Tcase<<": Yes"<<'\n';
        else cout<<"Case #"<<Tcase<<": No"<<'\n';

    }
}