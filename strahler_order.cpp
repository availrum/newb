#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){//9470
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=1; tcase<=T; ++tcase){
        int K,M,P;
        cin>>K>>M>>P;
        vector<int> vec[M+1], rvec[M+1];
        unordered_map<int,int> check, strahler;
        int a,b;
        for(int i=0; i<P; ++i){
            cin>>a>>b;
            vec[a].push_back(b);
            rvec[b].push_back(a);
            ++check[b];
        }
        queue<int> qu;
        for(int i=1; i<=M; ++i){
            if(!check[i]){
                qu.push(i);
                ++strahler[i];
            }
        }
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();

            int tmp=0;
            bool flag=false;
            for(int i=0; i<rvec[x].size(); ++i){
                if(strahler[rvec[x][i]]>tmp){
                    flag=false;
                    tmp=strahler[rvec[x][i]];
                }
                else if(strahler[rvec[x][i]]==tmp){
                    flag=true;
                }
            }
            if(flag){
                strahler[x]=tmp+1;
            }
            else if(tmp!=0) strahler[x]=tmp;
            else strahler[x]=1;
            for(int i=0; i<vec[x].size(); ++i){
                if(check[vec[x][i]]==1){
                    qu.push(vec[x][i]);
                }
                --check[vec[x][i]];
            }
        }
        cout<<K<<' '<<strahler[M]<<'\n';
    }
}