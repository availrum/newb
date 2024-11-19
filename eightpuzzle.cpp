#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
string purpose="12345678#";
unordered_map<string,int> hurimem;
int huri(string st){
    if(hurimem[st]) return hurimem[st];
    int cnt=0;
    for(int i=0; i<9; ++i){
        if(st[i]!=purpose[i]) ++cnt;
    }
    hurimem[st]=cnt;
    return cnt;
}
bool isSolvable(string st) {
    int count_inverse=0;
    for (int i=0; i<9; ++i) {
        if (st[i]=='#') continue;
        for (int j=i+1; j<9; ++j) {
            if (st[j]!='#' && st[i]>st[j]) ++count_inverse;
        }
    }
    return count_inverse%2==0; 
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
int main(){//11112
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    unordered_map<string, int> befsol;
    for(int testkase=0; testkase<T; ++testkase){
        string st="",tmpst;
        for(int i=0; i<3; ++i){
            cin>>tmpst;
            st+=tmpst;
        }
        if(befsol[st]){
            cout<<befsol[st]<<'\n';
            continue;
        }
        int sol=2147483647;
        if(isSolvable(st)==false){
            cout<<"impossible"<<'\n';
            continue;
        }
        if(st==purpose){
            cout<<"0"<<'\n';
            continue;
        }
        priority_queue<Node> pq;
        unordered_map<string,int> checked;
        checked[st]=1;
        pq.push({st,0,huri(st)});
        bool flag=false;
        while(!pq.empty()){
            string curstring=pq.top().state;
            int curcost=pq.top().cost;
            int findblank=curstring.find('#');
            int curx=findblank/3;
            int cury=findblank%3;
            pq.pop();
            if(curcost+huri(curstring)>=sol) continue;
            for(int i=0; i<4; ++i){
                int nexx=curx+dirx[i];
                int nexy=cury+diry[i];
                if(nexx>2 || nexx<0) continue;
                if(nexy>2 || nexy<0) continue;
                string inputst=curstring;
                swap(inputst[findblank],inputst[nexx*3+nexy]);
                if(inputst==purpose){
                    sol=min(sol,curcost+1);
                    befsol[st]=sol;
                    continue;
                }
                if(checked[inputst] && checked[inputst]<=curcost+1){
                    continue;
                }
                pq.push({inputst,curcost+1,huri(inputst)});
                checked[inputst]=curcost+1;
            }
        }
        if(sol==-1){
            cout<<"impossible"<<'\n';
        }
        else cout<<sol<<'\n';
    }
}