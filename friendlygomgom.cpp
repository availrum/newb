#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//25192
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,cnt=0;
    cin>>N;
    string st;
    unordered_map<string,int> ma;
    for(int i=0; i<N; ++i){
        cin>>st;
        if(st=="ENTER"){
            ma.clear();
            continue;
        }
        else if(ma[st]==0){
            ++cnt;
            ++ma[st];
        }
    }
    cout<<cnt<<'\n';
}