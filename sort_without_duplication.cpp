#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){ //10867
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<bool> used(2001,false);
    vector<int> numb;
    for(int i=0; i<N; ++i){
        cin>>t;
        if(!used[t+1000]){
            numb.push_back(t);
            used[t+1000]=true;
        }
    }
    sort(numb.begin(),numb.end());
    for(int i=0; i<numb.size(); ++i){
        if(i!=0) cout<<' ';
        cout<<numb[i];
    }
    cout<<'\n';
}