#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ //2531
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,d,k,c;
    cin>>N>>d>>k>>c;
    int sushi[N];
    for(int i=0; i<N; ++i){
        cin>>sushi[i];
    }
    unordered_map<int,int> check;
    ++check[c];
    int lft=0, rgt=k-1, cnt=1;
    for(int i=0; i<=rgt; ++i){
        if(!check[sushi[i]]){
            ++cnt;
        }
        ++check[sushi[i]];
    }
    int max_cnt=cnt;
    while(lft<N){
        --check[sushi[lft]];
        if(!check[sushi[lft]]) --cnt;
        ++lft;

        ++rgt;
        if(rgt>=N) rgt%=N;

        if(!check[sushi[rgt]]) ++cnt;
        ++check[sushi[rgt]];
        max_cnt=max(max_cnt,cnt);
    }
    cout<<max_cnt<<'\n';
}