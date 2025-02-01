#include<iostream>
#include<vector>
using namespace std;
int find(int N, int* constallation){
    if(constallation[N]==N) return N;
    return constallation[N]=find(constallation[N], constallation);
}
void merge(int a, int b, int* constallation){
    int x=find(a,constallation);
    int y=find(b,constallation);
    if(x==y) return;
    if(x<y) swap(x,y);
    constallation[x]=y;
}
int main(){//4386
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int sky=1;
    while(cin>>N){
        if(N==0) break;
        pair<int,int> coordi[N+1];
        for(int i=1; i<=N; ++i){
            cin>>coordi[i].first>>coordi[i].second;
        }
        int constallation[N+1];
        for(int i=0; i<=N; ++i){
            constallation[i]=i;
        }
        for(int i=1; i<=N; ++i){
            int mini=2147483647;
            // int idx;
            vector<int> idx;
            for(int j=1; j<=N; ++j){
                if(i==j) continue;
                int dist=(coordi[i].first-coordi[j].first)*(coordi[i].first-coordi[j].first)
                        +(coordi[i].second-coordi[j].second)*(coordi[i].second-coordi[j].second);
                if(mini>dist){
                    mini=dist;
                    idx.clear();
                    idx.push_back(j);
                }
                else if(mini==dist){
                    idx.push_back(j);
                }
            }
            for(int j=0; j<idx.size(); ++j) merge(i,idx[j], constallation);
        }
        int cnt=0;
        bool check[N+1]={false,};
        for(int i=1; i<=N; ++i){
            int x=find(i,constallation);
            // cout<<x<<'\n';
            if(!check[x]){
                check[x]=true;
                ++cnt;
            }
        }
        cout<<"Sky "<<sky<<" contains "<<cnt<<" constellations."<<'\n';
        ++sky;
    }
}