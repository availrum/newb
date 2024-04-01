#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){//1764
    int N,M,cnt;
    map<string, int> no;
    cin>>N>>M;
    string st;
    vector<string> sol;
    for(int i=0; i<N; i++){
        cin>>st;
        no[st]++;
    }
    for(int i=0; i<M; i++){
        cin>>st;
        no[st]++;
        if(no[st]>1){
            sol.push_back(st);
        }
    }
    sort(sol.begin(),sol.end());
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); i++){
            cout<<sol[i]<<'\n';
    }
    return 0;
}