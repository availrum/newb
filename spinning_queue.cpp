#include<iostream>
#include<deque>
using namespace std;
int main(){ //1021
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    deque<int> de;
    for(int i=1; i<=N; ++i){
        de.push_back(i);
    }
    int total_cnt=0;
    for(int i=0; i<M; ++i){
        int t;
        cin>>t;
        int cnt=0;
        while(de.front()!=t){
            de.push_back(de.front());
            de.pop_front();
            ++cnt;
        }
        int dsize=de.size();
        de.pop_front();
        total_cnt+=min(cnt, dsize-cnt);
    }
    cout<<total_cnt<<'\n';
}