#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
string purpose="123456780";
// unordered_map<string,int> hurimem;
// 메모리 제한이 굉장히 빡빡하니 heuristci memorize를 포기
// int 하나에 4b > 8,000,000개
int huri(string st){
    // if(hurimem[st]) return hurimem[st];
    int cnt=0;
    for(int i=0; i<9; ++i){
        if(st[i]!=purpose[i]) ++cnt;
    }
    return cnt;
}
struct Node {
    string state; 
    int cost;
    int heuristic;

    //우선순위큐 비교연산용
    bool operator<(const Node& other) const {
        return (cost+heuristic) > (other.cost+other.heuristic);
        //cost+h값 기준 우선순위
    }
};
bool isSolvable(string st) {
    int count_inverse=0;
    for (int i=0; i<9; ++i) {
        if (st[i]=='0') continue;
        for (int j=i+1; j<9; ++j) {
            if (st[j]!='0' && st[i]>st[j]) ++count_inverse;
        }
    }
    return count_inverse%2==0; 
}
int main(){//1525
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // hurimem[purpose]=0;
    string st="",tmpst;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cin>>tmpst;
            st+=tmpst;
        }
    }
    int sol=2147483647;
    if(st==purpose){
        cout<<"0"<<'\n';
        return 0;
    }
    priority_queue<Node> pq;
    unordered_map<string,int> checked;
    checked[st]=1;
    if(isSolvable(st)==false){
        cout<<"-1"<<'\n';
        return 0;
    }
    pq.push({st,0,huri(st)});
    while(!pq.empty()){
        string curstring=pq.top().state;
        int curcost=pq.top().cost;
        int findblank=curstring.find('0');
        int curx=findblank/3;
        int cury=findblank%3;
        pq.pop();
        if(curcost+huri(curstring)>sol) continue;
        //현재 답으로 기록된것보다 현재값 + 예측값이 더 크면 넘기기
        for(int i=0; i<4; ++i){
            int nexx=curx+dirx[i];
            int nexy=cury+diry[i];
            if(nexx>2 || nexx<0) continue;
            if(nexy>2 || nexy<0) continue;
            string inputst=curstring;
            swap(inputst[findblank],inputst[nexx*3+nexy]);
            if(checked[inputst] && curcost+1>=checked[inputst]) continue;
            if(inputst==purpose) sol=min(sol,curcost+1);
            pq.push({inputst, curcost+1, huri(inputst)});
            checked[inputst]=curcost+1;
        }
    }
    if(sol==2147483647){
        cout<<"-1"<<'\n';
    }
    else cout<<sol<<'\n';
}