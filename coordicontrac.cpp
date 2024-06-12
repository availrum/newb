#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(){//18870
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp=0,tmpi=1000000001;
    unordered_map<int,int> umap;
    cin>>N;
    int coordi[N],coord[N];
    for(int i=0; i<N; ++i) {
        cin>>coordi[i];
        coord[i]=coordi[i];
    }
    sort(coordi,coordi+N);
    for(int i=0; i<N; ++i){
        if(tmpi==coordi[i]) tmp++;
        else tmpi=coordi[i];
        umap[coordi[i]]=i-tmp;
    }
    for(int i=0; i<N; ++i) cout<<umap[coord[i]]<<' ';
    cout<<'\n';
}