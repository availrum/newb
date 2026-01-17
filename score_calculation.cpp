#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main(){ //2822
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    int arr[8],score[8];
    for(int i=0; i<8; ++i){
        cin>>score[i];
        arr[i]=score[i];
    }
    sort(score,score+8);
    set<int> check;
    int total_score=0;
    for(int i=3; i<8; ++i){
        check.insert(score[i]);
        total_score+=score[i];
    }
    cout<<total_score<<'\n';
    int cnt=0;
    for(int i=0; i<8; ++i){
        if(check.find(arr[i])!=check.end()){
            if(cnt!=0) cout<<' ';
            cout<<i+1;
            ++cnt;
        }
    }
    cout<<'\n';

} 