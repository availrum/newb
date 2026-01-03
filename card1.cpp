#include<iostream>
#include<queue>
using namespace std;
int main(){ //2161
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    queue<int> qu;
    for(int i=1; i<=N; ++i){
        qu.push(i);
    }
    while(qu.size()>1){
        cout<<qu.front()<<' ';
        qu.pop();
        qu.push(qu.front());
        qu.pop();
    }
    cout<<qu.front()<<'\n';
}