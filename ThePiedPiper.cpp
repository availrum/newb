#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int height[1001][1001];
pair<int,int> node[1001][1001];
pair<int,int> find(pair<int,int> n){
    if(n==node[n.first][n.second]) return n;
    return node[n.first][n.second]=find(node[n.first][n.second]);
    //경로압축
}
void merge(pair<int,int> tmp1, pair<int,int> tmp2){
    pair<int,int> x=find(tmp1);
    pair<int,int> y=find(tmp2);
    if(x==y) return;
    if(height[x.first][x.second]>height[y.first][y.second]) swap(x,y);
    node[x.first][x.second]=y;
    if(height[x.first][x.second]==height[y.first][y.second]) ++height[y.first][x.second];
}
int main(){//16724
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    pair<int,int> xy;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            pair<int,int> xy={i,j};
            node[i][j]=xy;
        }
    }
    string st;
    pair<int,int> tmp;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<M; ++j){
            tmp.first=i+1;
            tmp.second=j+1;
            if(st[j]=='U'){
                merge(tmp,{tmp.first-1,tmp.second});
            }
            else if(st[j]=='D'){
                merge(tmp,{tmp.first+1,tmp.second});
            }
            else if(st[j]=='L'){
                merge(tmp,{tmp.first,tmp.second-1});
            }
            else if(st[j]=='R'){
                merge(tmp,{tmp.first,tmp.second+1});
            }
        }
    }
    unordered_map<int,int> mapx;
    pair<int,int> tmpn;
    int sol=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            tmpn={i,j};
            pair<int,int> tmpin=find(tmpn);
            if(!mapx[(tmpin.first)+(tmpin.second)*1001]){
                //안겹치게 해시 구현
                ++sol;
                ++mapx[(tmpin.first)+(tmpin.second)*1001];
            }
        }
    }
    cout<<sol<<'\n';
}