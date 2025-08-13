#include<iostream>
#include<queue>
using namespace std;
int main(){ //15828
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    queue<int> router;
    while(true){
        int t;
        cin>>t;
        if(t==0){
            router.pop();
        }
        else if(t==-1){
            break;
        }
        else if(router.size()>=N) continue;
        else{
            router.push(t);
        }
    }
    if(router.empty()){
        cout<<"empty"<<'\n';
    }
    else{
        while(!router.empty()){
            cout<<router.front();
            router.pop();
            if(!router.empty()) cout<<' ';
            else cout<<'\n';
        }
    }
}