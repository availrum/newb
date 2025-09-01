#include<iostream>
#include<vector>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};

int main(){ //15812
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][M], visited[N][M];
    vector<pair<int,int>> candidate, village;
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            arr[i][j]=st[j]-'0';
            visited[i][j]=0;
            if(arr[i][j]==0) candidate.push_back({i,j});
            else village.push_back({i,j});
        }
    }
    
    // for(int i=0; i<village.size(); ++i){
    //     cout<<village[i].first<<' '<<village[i].second<<'\n';
    // }
    // cout<<'\n';
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<arr[i][j];
    //     }
    //     cout<<'\n';
    // }
    int min_distance=40;
    for(int i=0; i<candidate.size(); ++i){
        for(int j=i+1; j<candidate.size(); ++j){
            int longest=0;
            for(int k=0; k<village.size(); ++k){
                int cur_dist=min((abs(candidate[i].first-village[k].first)+abs(candidate[i].second-village[k].second))
                    , (abs(candidate[j].first-village[k].first)+abs(candidate[j].second-village[k].second)));
                longest=max(longest, cur_dist);
            }
            min_distance=min(min_distance, longest);
        }
    }
    cout<<min_distance<<'\n';
} 