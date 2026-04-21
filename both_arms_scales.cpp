#include<iostream>
#include<vector>
using namespace std;
const int max_weight=40000;
int main(){ //2629
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<int> pendulum(N,0);
    vector<bool> weight(max_weight+1,false);
    weight[0]=true;
    for(int i=0; i<N; ++i){
        cin>>pendulum[i];
        vector<int> tmp;
        for(int j=0; j<=max_weight; ++j){
            if(weight[j]){
                if(pendulum[i]>=j) tmp.push_back(pendulum[i]-j);
                else tmp.push_back(j-pendulum[i]);

                if(j+pendulum[i]<=max_weight) tmp.push_back(j+pendulum[i]);
            }
        }
        for(int j=0; j<tmp.size(); ++j) weight[tmp[j]]=true;
    }
    int M;
    cin>>M;
    for(int i=0; i<M; ++i){
        cin>>t;
        if(i!=0) cout<<' ';
        if(weight[t]) cout<<"Y";
        else cout<<"N";
    }
    cout<<'\n';
    // for(int i=0; i<11; ++i){
    //     cout<<weight[i]<<' ';
    // }cout<<'\n';
}