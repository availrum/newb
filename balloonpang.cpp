#include<iostream>
#include<deque>
using namespace std;
int main(){//2346
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp;
    cin>>N;
    deque<pair<int,int>> deq;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        deq.push_back({tmp,i+1});
    }
    int x=deq.front().first;
    int idx=deq.front().second;
    deq.pop_front();
    cout<<idx;
    // while(!deq.empty()){
    for(int i=0; i<N-1; ++i){
        cout<<' ';
        if(x>0){
            for(int j=0; j<x-1; ++j){
                int y=deq.front().first;
                int yidx=deq.front().second;
                deq.pop_front();
                deq.push_back({y,yidx});
            }
            x=deq.front().first;
            idx=deq.front().second;
            deq.pop_front();
            cout<<idx;
        }
        else{
            for(int j=0; j<abs(x)-1; ++j){
                int y=deq.back().first;
                int yidx=deq.back().second;
                deq.pop_back();
                deq.push_front({y,yidx});
            }
            x=deq.back().first;
            idx=deq.back().second;
            deq.pop_back();
            cout<<idx;
        }
    }
    cout<<'\n';
}