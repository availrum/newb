#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int height[1001][1001];
pair<int,int> node[1001][1001]; // 링크드리스트 배열로 저장
pair<int,int> find(pair<int,int> n){
    if(n==node[n.first][n.second]) return n;
    return node[n.first][n.second]=find(node[n.first][n.second]);
    //경로압축을 위한 저장
}
void merge(pair<int,int> input1, pair<int,int> input2){ // 분리집합에 추가
    pair<int,int> x=find(input1);
    pair<int,int> y=find(input2);
    if(x==y) return;
    if(height[x.first][x.second]>height[y.first][y.second]) swap(x,y);
    node[x.first][x.second]=y;
    if(height[x.first][x.second]==height[y.first][y.second]) ++height[y.first][x.second];
}
int main(){// 백준 16724번 피리부는 사나이 
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
    pair<int,int> current;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<M; ++j){
            current.first=i+1;
            current.second=j+1;
            if(st[j]=='U'){
                merge(current,{current.first-1,current.second});
            }
            else if(st[j]=='D'){
                merge(current,{current.first+1,current.second});
            }
            else if(st[j]=='L'){
                merge(current,{current.first,current.second-1});
            }
            else if(st[j]=='R'){
                merge(current,{current.first,current.second+1});
            }
        }
    }
    unordered_map<int,int> map_check;
    int sol=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            current={i,j};
            pair<int,int> tmp_input=find(current);
            if(!map_check[(tmp_input.first)+(tmp_input.second)*1001]){ // 등록한 적 없는 세이프티존만
                // 안겹치게 해시 구현 (1000개이므로)
                ++sol;
                ++map_check[(tmp_input.first)+(tmp_input.second)*1001];
            }
        }
    }
    cout<<sol<<'\n';
}