#include<iostream>
#include<queue>
using namespace std;
int main(){ //1655
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    priority_queue<int> qumin;
    priority_queue<int,vector<int>, greater<int>> qumax;
    for(int i=0; i<N; ++i){
        cin>>t;
        if(qumin.empty()){
            qumin.push(t);
        }
        else if(qumax.empty()){
            if(qumin.top()<=t) qumax.push(t);
            else{
                qumax.push(qumin.top());
                qumin.pop();
                qumin.push(t);
            }
        }
        else{
            if(qumin.top()>t) qumin.push(t);
            else qumax.push(t);
            while(qumin.size()<qumax.size()){
                qumin.push(qumax.top());
                qumax.pop();
            }
            while(qumin.size()>qumax.size()+1){
                qumax.push(qumin.top());
                qumin.pop();
            }
        }
        cout<<qumin.top()<<'\n';
    }
}