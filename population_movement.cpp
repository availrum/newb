#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int main(){ //16234
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,L,R;
    cin>>N>>L>>R;
    vector<vector<int>> world(N,vector<int>(N,0));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>world[i][j];
        }
    }
    int day=0;
    while(true){
        bool flag=true;
        vector<vector<bool>> visited(N,vector<bool>(N,false));
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(visited[i][j]) continue;
                queue<pair<int,int>> qu;
                vector<pair<int,int>> country;
                qu.push({i,j});
                country.push_back({i,j});
                visited[i][j]=true;
                while(!qu.empty()){
                    int x=qu.front().first;
                    int y=qu.front().second;
                    qu.pop();
                    for(int k=0; k<4; ++k){
                        int nx=x+dirx[k];
                        int ny=y+diry[k];
                        if(nx<0 || nx>=N) continue;
                        if(ny<0 || ny>=N) continue;
                        if(abs(world[x][y]-world[nx][ny])<L 
                        || abs(world[x][y]-world[nx][ny])>R) continue;
                        if(visited[nx][ny]) continue;
                        qu.push({nx,ny});
                        country.push_back({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
                int population=0;
                for(int k=0; k<country.size(); ++k){
                    population+=world[country[k].first][country[k].second];
                }
                population/=country.size();
                for(int k=0; k<country.size(); ++k){
                    world[country[k].first][country[k].second]=population;
                }
                if(country.size()!=1) flag=false;
            }
        }

        if(flag) break;
        ++day;
    }
    cout<<day<<'\n';
} 