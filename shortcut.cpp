#include<iostream>
#include<vector>
using namespace std;
struct sc{
    int ed;
    int dist;
};
int main(){ //1446
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,D;
    cin>>N>>D;
    vector<vector<sc>> arr(D+1);
    vector<int> pur(D+1,100000001);
    int st,ed,dist;
    for(int i=0; i<N; ++i){
        cin>>st>>ed>>dist;
        bool flag=true;
        if(st<D && ed<=D){
            for(int j=0; j<arr[st].size(); ++j){
                if(arr[st][j].ed==ed && arr[st][j].dist>dist){
                    arr[st][j].dist=dist;
                    flag=false;
                    break;
                }
            }
            if(flag && ed-st>dist && D>dist) arr[st].push_back({ed,dist});
        }
    }
    pur[0]=0;
    for(int i=0; i<D; ++i){
        for(int j=0; j<arr[i].size(); ++j){
            pur[arr[i][j].ed]=min(pur[arr[i][j].ed], pur[i]+arr[i][j].dist);
        }
        pur[i+1]=min(pur[i+1],pur[i]+1);
    }
    cout<<pur[D]<<'\n';
    
}