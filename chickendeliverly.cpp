#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int M, mini=214748364;
struct pos{
    int x;
    int y;
};
vector<pos> curchic;
vector<pos> home;
vector<pos> chic;
int street(void){
    int sum=0;
    for(int i=0; i<home.size(); ++i){
        int shortest=10001;
        int posx=home[i].x, posy=home[i].y;
        for(int j=0; j<M; ++j){
            int x=curchic[j].x, y=curchic[j].y;
            int dist=abs(posx-x)+abs(posy-y);
            shortest=min(shortest,dist);
        }
        sum+=shortest;
    }
    return sum;
}
void rec(int num, int starti){
    if(num==M){
        int sum=street();
        mini=min(mini,sum);
        return;
    }
    for(int i=starti; i<chic.size(); ++i){
        pos tmp=chic[i];
        curchic.push_back(tmp);
        rec(num+1,i+1);
        curchic.pop_back();
    }
}
int main(){//15686
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp;
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>tmp;
            if(tmp==1) home.push_back({i,j});
            else if(tmp==2) chic.push_back({i,j});
        }
    }
    rec(0,0);
    cout<<mini<<'\n';
}