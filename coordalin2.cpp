#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    pair<int, int> c; 
    vector<pair<int,int>> a;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>c.second>>c.first;
        a.push_back(c);
    }
    stable_sort(a.begin(),a.end());
    for(int i=0; i<N; i++){
        cout<<a.at(i).second<<' '<<a.at(i).first<<'\n';
    }
    return 0;
}
