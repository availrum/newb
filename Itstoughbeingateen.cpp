#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){//6858
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y;
    vector<int> vec[8];
    unordered_map<int,int> check;
    vec[1].push_back(7);
    ++check[7];
    vec[1].push_back(4);
    ++check[4];
    vec[2].push_back(1);
    ++check[1];
    vec[3].push_back(4);
    ++check[4];
    vec[3].push_back(5);
    ++check[5];
    while(cin>>x>>y){
        if(x==0 && y==0) break;
        vec[x].push_back(y);
        ++check[y];
    }
        priority_queue<int,vector<int>,greater<int>> qu;
        for(int i=1; i<=7; ++i){
            if(!check[i]) qu.push(i);
        }
        vector<int> sol;
        while(!qu.empty()){
            int tmp=qu.top();
            qu.pop();
            for(int i=0; i<vec[tmp].size(); ++i){
                if(check[vec[tmp][i]]==1) qu.push(vec[tmp][i]);
                --check[vec[tmp][i]];
            }
            sol.push_back(tmp);
        }
        // if(sol.size()!=7){
        //     cout<<"Cannot complete these tasks. Going to bed."<<'\n';
        //     return 0;
        // }
        for(int i=0; i<sol.size(); ++i){
            cout<<sol[i];
            if(i!=sol.size()-1) cout<<' ';
            else cout<<'\n';
        }

}