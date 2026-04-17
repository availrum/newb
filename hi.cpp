#include<iostream>
#include<vector>
using namespace std;
int main(){ //1535
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,int>> act(N);
    for(int i=0; i<N; ++i){
        cin>>act[i].first;
    }
    for(int i=0; i<N; ++i){
        cin>>act[i].second;
    }
    vector<vector<int>> happy(N,vector<int>(100,0));
    int max_happy=0;
    for(int i=0; i<N; ++i){
        if(i==0){
            for(int j=act[i].first; j<100; ++j){
                happy[i][j]=act[i].second;
                max_happy=max(max_happy,happy[i][j]);
            }
            continue;
        }
        for(int j=0; j<100; ++j){
            if(j>=act[i].first){
                if(j==0) happy[i][j]=max(happy[i-1][j], happy[i-1][j-act[i].first]+act[i].second);
                else happy[i][j]=max(happy[i][j-1],max(happy[i-1][j], happy[i-1][j-act[i].first]+act[i].second));
            }
            else if(j!=0) happy[i][j]=max(happy[i][j-1],happy[i-1][j]);
            else happy[i][j]=happy[i-1][j];
            max_happy=max(max_happy,happy[i][j]);
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<100; ++j){
    //         cout<<happy[i][j]<<' ';
    //     }cout<<'\n';
    // }
    
    cout<<max_happy<<'\n';
}