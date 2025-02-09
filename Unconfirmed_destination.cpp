#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){//9370
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int n,m,t;
        cin>>n>>m>>t;
        int s,g,h;
        cin>>s>>g>>h;
        int a,b,d;
        vector<pair<int,int>> road[n+1];
        int gtoh;
        for(int i=0; i<m; ++i){
            cin>>a>>b>>d;
            road[a].push_back({b,d});
            road[b].push_back({a,d});
            if(a==g && b==h) gtoh=d;
            else if(a==h && b==g) gtoh=d;
        }
        vector<int> candi;
        int x;
        for(int i=0; i<t; ++i){
            cin>>x;
            candi.push_back(x);
        }
        sort(candi.begin(), candi.end());

        int cross[n+1];
        int gcandi[n+1], hcandi[n+1];
        // for(int i=1; i<=n; ++i){
        // }
        for(int i=0; i<=n; ++i){
            cross[i]=214748364;
            gcandi[i]=214748364;
            hcandi[i]=214748364;
        }

        queue<int> qu;

        qu.push(s);
        cross[s]=0;
        while(!qu.empty()){//시작지점에서 g,h까지를 구하는 다익스트라
            int cur=qu.front();
            qu.pop();
            for(int i=0; i<road[cur].size(); ++i){
                if(cross[road[cur][i].first] > cross[cur]+road[cur][i].second){
                    cross[road[cur][i].first] = cross[cur]+road[cur][i].second;
                    qu.push(road[cur][i].first);
                }
            }
        }
        qu.push(g);
        gcandi[g]=0;
        while(!qu.empty()){//g에서 후보까지를를 구하는 다익스트라(g-h간선x)
            int cur=qu.front();
            qu.pop();
            for(int i=0; i<road[cur].size(); ++i){
                if((cur==g && road[cur][i].first==h) || (cur==h && road[cur][i].first==g)) continue;
                else if(gcandi[road[cur][i].first] > gcandi[cur]+road[cur][i].second){
                    gcandi[road[cur][i].first] = gcandi[cur]+road[cur][i].second;
                    qu.push(road[cur][i].first);
                }
            }
        }
        qu.push(h);
        hcandi[h]=0;
        while(!qu.empty()){//h의 거리를 구하는 다익스트라 (g-h간선x)
            int cur=qu.front();
            qu.pop();
            for(int i=0; i<road[cur].size(); ++i){
                if((cur==g && road[cur][i].first==h) || (cur==h && road[cur][i].first==g)) continue;
                else if(hcandi[road[cur][i].first] > hcandi[cur]+road[cur][i].second){
                    hcandi[road[cur][i].first] = hcandi[cur]+road[cur][i].second;
                    qu.push(road[cur][i].first);
                }
            }
        }
        int mincost=2147483647, val;
        for(int i=0; i<t; ++i){
            val=min(cross[g]+gtoh+hcandi[candi[i]] ,cross[h]+gtoh+gcandi[candi[i]]);
            if(mincost>val){
                mincost=val;
            }
        }
        vector<int> sol;
        for(int i=0; i<t; ++i){
            val=min(cross[g]+gtoh+hcandi[candi[i]] ,cross[h]+gtoh+gcandi[candi[i]]);
            if(val>cross[candi[i]]) continue;
            // cout<<candi[i]<<' '<<cross[g]<<' '<<gtoh<<' '<<hcandi[candi[i]]<<'\n';
            // cout<<candi[i]<<' '<<cross[h]<<' '<<gtoh<<' '<<gcandi[candi[i]]<<'\n';
            sol.push_back(candi[i]);
        }
        for(int i=0; i<sol.size(); ++i){
            cout<<sol[i];
            if(i!=sol.size()-1) cout<<' ';
            else cout<<'\n';
        }
    }
}