#include<iostream>
#include<vector>
using namespace std;
int main(){//9372
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N,M;
        cin>>N>>M;
        vector<int> nation[N+1];
        int a,b;
        for(int i=0; i<M; ++i){
            cin>>a>>b;
            nation[a].push_back(b);
            nation[b].push_back(a);
        }
        //??
        cout<<N-1<<'\n';
    }
}