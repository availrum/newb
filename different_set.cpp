#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){ //1822
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int na,nb,t;
    cin>>na>>nb;
    map<int,int> mapa, mapb;
    vector<int> candi;
    for(int i=0; i<na; ++i){
        cin>>t;
        ++mapa[t];
        candi.push_back(t);
    }
    for(int i=0; i<nb; ++i){
        cin>>t;
        ++mapb[t];
    }
    vector<int> sol;
    for(auto& ele:mapa){
        if(mapb[ele.first]) continue;
        sol.push_back(ele.first);
    }
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i){
        if(i!=0) cout<<' ';
        cout<<sol[i];
    }
    if(sol.size()!=0) cout<<'\n';
}