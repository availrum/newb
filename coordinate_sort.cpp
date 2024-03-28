#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N,M,tempi;
    pair<int, int> check;
    vector<pair<int, int>> k;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>check.first>>check.second;
        k.push_back(check);
    }
    stable_sort(k.begin(),k.end());
    
    for(int i=0; i<N; i++){
        cout<<k.at(i).first<<' '<<k.at(i).second;
        cout<<'\n';
    }
}