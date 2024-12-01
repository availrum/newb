#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
struct pos{
    int x;
    int y;
    bool operator< (const pos& other) const{
        if(x>other.x || x<other.x){
            return x<other.x;
        }
        return y<other.y;
    }
};
int main(){//1202
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    
    pos tmp;
    vector<pos> jewel;

    for(int i=0; i<N; ++i){
        cin>>tmp.x>>tmp.y;
        jewel.push_back(tmp);
    }
    // cout<<'\n';
    int tmpin;
    unordered_map<int,int> check;
    vector<int> bag;
    for(int i=0; i<K; ++i){
        cin>>tmpin;
        bag.push_back(tmpin);
    }

    long long int sol=0;
    // cout<<'\n';
    // while(!pqu.empty()){
    //     int jmas=pqu.top().x;
    //     int jval=pqu.top().y;
    //     pqu.pop();
    //     cout<<jmas<<' '<<jval<<'\n';
    // }

    priority_queue<int> inpqu;
    //값으로 정렬, 후보체크
    sort(jewel.begin(),jewel.end());
    sort(bag.begin(),bag.end());
    int jewidx=0;
    for(int i=0; i<bag.size(); ++i){
        while(jewidx < jewel.size() && jewel[jewidx].x <= bag[i]){
            if(i>=bag.size()) break;
            int jweight=jewel[jewidx].x;
            int jvalue=jewel[jewidx].y;

            inpqu.push(jvalue);
            ++jewidx;
        }
        if(!inpqu.empty()){
            sol+=inpqu.top();
            inpqu.pop();
        }
    }
    cout<<sol<<'\n';
}